/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef APP_SERVER_CORE_CLIENT_CONNECTION_HPP
#define APP_SERVER_CORE_CLIENT_CONNECTION_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include IClientConnection
#ifndef APP_SERVER_CORE_I_CLIENT_CONNECTION_HXX
    #include <app/server/core/IClientConnection.hxx>
#endif /// !APP_SERVER_CORE_I_CLIENT_CONNECTION_HXX

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// ClientConnection
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

namespace app
{

    namespace server
    {

        namespace core
        {

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            class ClientConnection : public IClientConnection
            {

            private:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DELETED
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                ClientConnection(const ClientConnection&)            = delete;
                ClientConnection& operator=(const ClientConnection&) = delete;
                ClientConnection(ClientConnection &&)                = delete;
                ClientConnection& operator=(ClientConnection &&)     = delete;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            protected:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // CONSTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                explicit ClientConnection();

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            public:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DESTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                virtual ~ClientConnection();

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            };

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !APP_SERVER_CORE_CLIENT_CONNECTION_HPP
