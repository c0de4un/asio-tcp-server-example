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
#ifndef APP_SERVER_WIN_CLIENT_CONNECTION_HPP
    #include <app/server/windows/WinClientConnection.hpp>
#endif /// !APP_SERVER_WIN_CLIENT_CONNECTION_HPP

// Include STL
#include <iostream>
#include <string>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// WinClientConnection
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

            WinClientConnection::WinClientConnection(
                    const app::server::core::ClientConnection::id_t id,
                    boost::asio::io_context& _context,
                    boost::asio::ip::tcp::socket _socket
            )
                :
                ClientConnection(id),
                mContext(_context),
                mSocket(std::move(_socket))
            {
            }

            WinClientConnection::~WinClientConnection() = default;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // WinClientConnection.PUBLIC.METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            WinClientConnection* WinClientConnection::Create(
                const app::server::core::ClientConnection::id_t id,
                boost::asio::io_context& _context,
                boost::asio::ip::tcp::socket _socket
            ) {
                return new WinClientConnection(id, _context, std::move(_socket));
            }

            void WinClientConnection::Confirm()
            {
                const std::string msg("Welcome to the Server");

                boost::asio::async_write(
                    mSocket,
                    boost::asio::buffer(msg),
                    [this](std::error_code ec, std::size_t length)
                    {
                        if (ec)
                        {
                            std::cout << "ERROR: WinClientConnection::Confirm: " << ec.message() << "\n";
                        }
                        else
                        {
                            std::cout << "WinClientConnection::Confirm: " << std::to_string(length) << " bytes sent\n";
                        }
                    }
                );
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
