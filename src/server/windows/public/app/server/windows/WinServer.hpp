/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef APP_SERVER_WIN_SERVER_HPP
#define APP_SERVER_WIN_SERVER_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include app::server::core::Server
#ifndef APP_SERVER_CORE_HPP
    #include <app/server/core/Server.hpp>
#endif /// !APP_SERVER_CORE_HPP

// Include asio
#ifndef APP_SERVER_WIN_ASIO_HPP
    #include <app/server/windows/asio.hpp>
#endif /// !APP_SERVER_WIN_ASIO_HPP

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

            class WinServer final : public app::server::core::Server
            {

            private:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // FIELDS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                boost::asio::io_context& mContext;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // CONSTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                explicit WinServer(boost::asio::io_context& mContext);

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // METHODS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                void _stop();

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DELETED
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                WinServer(const WinServer&)            = delete;
                WinServer& operator=(const WinServer&) = delete;
                WinServer(WinServer &&)                = delete;
                WinServer& operator=(WinServer &&)     = delete;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            public:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DESTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                virtual ~WinServer();

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // METHODS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                static void Create(boost::asio::io_context& context);

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // Server.METHODS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                virtual bool Start();
                virtual void Stop();

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            };

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !APP_SERVER_WIN_SERVER_HPP
