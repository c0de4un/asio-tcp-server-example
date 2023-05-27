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
#include <app/server/windows/main.hpp>

// DEBUG
#include <cassert>
#include <exception>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// MAIN
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main()
{
    std::cout << "Starting Windows Server . . .\n";

    boost::asio::io_context _context;

    app::server::win::WinServer::Create(_context, 8080);
    auto _server_ptr(app::server::core::Server::getInstance());

    assert(_server_ptr.get() && "main: Server not created");

    // Guarded block
    try
    {
        if (!_server_ptr->Start())
            _context.run();
        else
            std::cout << "main: Failed to start\n";
    }
    catch (const std::exception& _exception)
    {
        std::cout << "ERROR: main: " << _exception.what() << "\n";
    }
    catch (...)
    {
        std::cout << "ERROR: main: uknonwn error\n";
    }

    _server_ptr->Stop();
    std::cout << "Stopping Windows Server . . .\n";

    app::server::core::Server::Terminate();

    std::cout << "Press any key to exit . . .\n";
    std::cin.get();

    return OK_RESULT;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
