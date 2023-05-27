/**
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

#ifndef APP_SERVER_CORE_HPP
#define APP_SERVER_CORE_HPP

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// INCLUDES
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Include STL memory
#include <memory>

// Include STL atomic
#include <atomic>

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

            class Server
            {

            private:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // FIELDS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                static std::shared_ptr<Server> mInstance;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DELETED
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                Server(const Server&)            = delete;
                Server& operator=(const Server&) = delete;
                Server(Server &&)                = delete;
                Server& operator=(Server &&)     = delete;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            protected:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // FIELDS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                std::atomic_bool mStop;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // CONSTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                explicit Server();

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            public:

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // DESTRUCTOR
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                virtual ~Server();

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // GETTERS & SETTERS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                static void setInstance(std::shared_ptr<Server>& pInstance) noexcept;
                static std::shared_ptr<Server> getInstance() noexcept;

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                // METHODS
                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                static void Terminate();

                virtual bool Start();
                virtual void Stop();

                // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

            };

            // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        }

    }

}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#endif /// !APP_SERVER_CORE_HPP
