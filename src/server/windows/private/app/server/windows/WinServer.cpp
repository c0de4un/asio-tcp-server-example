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

            WinServer::WinServer()
                :
                Server()
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

            void WinServer::Create()
            {
                WinServer* const winServer_ptr(new WinServer());

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

            void WinServer::_stop()
            {
                std::cout << "WinServer::_stop\n";
            }

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
