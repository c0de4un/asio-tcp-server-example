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
#include <app/server/core/Server.hpp>

// Include STL iostream
#include <iostream>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Server
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace app
{

    namespace server
    {

        namespace core
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // FIELDS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            std::shared_ptr<Server> Server::mInstance(nullptr);

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // CONSTRUCTOR & DESTRUCTOR
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            Server::Server()
                :
                mStop(false)
            {
            }

            Server::~Server() = default;

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // GETTERS & SETTERS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            void Server::setInstance(std::shared_ptr<Server>& pInstance) noexcept
            {
                if (!mInstance.get())
                    mInstance.swap(pInstance);
            }

            std::shared_ptr<Server> Server::getInstance() noexcept
            {
                return mInstance;
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            void Server::Terminate()
            {
                std::cout << "Server::Terminate\n";

                mInstance.reset();
            }

            bool Server::Start()
            {
                return false;
            }

            void Server::Stop()
            {
                // void
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
            // Server.PRIVATE.METHODS
            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            IClientConnection::id_t Server::generateClientConnectionID()
            {
                IClientConnection::id_t id(0);

                std::unique_lock<std::mutex> lock(mConnectionsMutex);

                if (!mAvailableConnectionsIDs.empty())
                {
                    id = mAvailableConnectionsIDs.back();
                    mAvailableConnectionsIDs.pop_back();
                }

                if (!id)
                {
                    const auto reservedCount(mReservedConnectionsIDs.size());
                    if (reservedCount > mReservedConnectionsIDs.max_size() - 1)
                        return 0;

                    id = static_cast<IClientConnection::id_t>(reservedCount + 1);
                }

                mReservedConnectionsIDs.push_back(id);

                return id;
            }

            void Server::releaseClientConnectionID(const IClientConnection::id_t id)
            {
                std::unique_lock<std::mutex> lock(mConnectionsMutex);

                const auto end_iter(mReservedConnectionsIDs.cend());
                auto iter(mReservedConnectionsIDs.begin());
                while (iter != end_iter)
                {
                    if ((*iter) == id)
                    {
                        mReservedConnectionsIDs.erase(iter);
                        break;
                    }

                    iter++;
                }

                mAvailableConnectionsIDs.push_back(id);
            }

            void Server::storeClientConnection(connection_ptr& pConnection)
            {
                std::unique_lock<std::mutex> lock(mConnectionsMutex);

                mClientConnections[pConnection->getID()] = pConnection;
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
