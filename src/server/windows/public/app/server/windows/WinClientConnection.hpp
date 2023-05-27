/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef APP_SERVER_WIN_CLIENT_CONNECTION_HPP
#define APP_SERVER_WIN_CLIENT_CONNECTION_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include core::ClientConnection
#ifndef APP_SERVER_CORE_CLIENT_CONNECTION_HPP
    #include <app/server/core/ClientConnection.hpp>
#endif /// !APP_SERVER_CORE_CLIENT_CONNECTION_HPP

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

            class WinClientConnection final : public app::server::core::ClientConnection
            {

            private:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // CONSTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                explicit WinClientConnection(const app::server::core::ClientConnection::id_t);

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DELETED
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                WinClientConnection(const WinClientConnection&)            = delete;
                WinClientConnection& operator=(const WinClientConnection&) = delete;
                WinClientConnection(WinClientConnection &&)                = delete;
                WinClientConnection& operator=(WinClientConnection &&)     = delete;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            public:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DESTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                virtual ~WinClientConnection();

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // METHODS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                static WinClientConnection* Create(const app::server::core::ClientConnection::id_t);

                void Confirm();

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            };

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !APP_SERVER_WIN_CLIENT_CONNECTION_HPP
