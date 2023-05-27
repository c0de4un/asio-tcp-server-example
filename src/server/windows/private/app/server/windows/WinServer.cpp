/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// HEADER
#include <app/server/windows/WinServer.hpp>

// Include STL iostream
#include <iostream>

// Include WinClientConnection
#ifndef APP_SERVER_WIN_CLIENT_CONNECTION_HPP
    #include <app/server/windows/WinClientConnection.hpp>
#endif /// !APP_SERVER_WIN_CLIENT_CONNECTION_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// WinServer
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace app
{

    namespace server
    {

        namespace win
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTOR & DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            WinServer::WinServer(boost::asio::io_context& context, const boost::asio::ip::port_type port)
                :
                Server(),
                mContext(context),
                mAcceptor(
                    context,
                    boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)
                ),
                mPort(port)
            {
                std::cout << "WinServer::constructor\n";
            }

            WinServer::~WinServer()
            {
                std::cout << "WinServer::destructor\n";

                _stop();
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // WinServer.PUBLIC.METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            void WinServer::Create(boost::asio::io_context& context, const boost::asio::ip::port_type in_port)
            {
                WinServer* const winServer_ptr(new WinServer(context, in_port));

                std::shared_ptr<app::server::core::Server> server_ptr(
                    static_cast<app::server::core::Server*>(winServer_ptr)
                );
                app::server::core::Server::setInstance(server_ptr);
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // Server.PUBLIC.METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            bool WinServer::Start()
            {
                std::cout << "WinServer::Start\n";

                mStop.store(false);



                return true;
            }

            void WinServer::Stop()
            {
                std::cout << "WinServer::Stop\n";

                mStop.store(true);
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // WinServer.PRIVATE.METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            void WinServer::_waitForCLient()
            {
                if (mStop)
                    return;

                mAcceptor.async_accept(
                    [this](std::error_code ec, boost::asio::ip::tcp::socket socket)
                    {
                        if (mStop)
                            return;

                        if (ec)
                        {
                            std::cout << "ERROR: WinServer::_waitForCLient: " << ec.message() << "\n";
                        }
                        else
                        {
                            const auto _id(Server::generateClientConnectionID());
                            if (!_id)
                            {
                                std::cout << "WinServer::_waitForCLient: connections limit has been reached\n";
                                socket.close();

                                if (!mStop)
                                    _waitForCLient();

                                return;
                            }

                            WinClientConnection* winClientConnection_ptr(nullptr);
                            try
                            {
                                winClientConnection_ptr = WinClientConnection::Create(_id);
                            }
                            catch (...)
                            {
                                std::cout << "WinServer::_waitForCLient: failed to create WinClientConnection\n";
                                Server::releaseClientConnectionID(_id);
                            }

                            Server::connection_ptr _connection_ptr(
                                static_cast<app::server::core::IClientConnection*>(winClientConnection_ptr)
                            );
                            Server::storeClientConnection(_connection_ptr);

                            winClientConnection_ptr->Confirm();
                        }

                        if (!mStop)
                            _waitForCLient();
                    }
                );
            }

            void WinServer::_stop()
            {
                std::cout << "WinServer::_stop\n";

                if (!mContext.stopped())
                    mContext.stop(); // async
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
