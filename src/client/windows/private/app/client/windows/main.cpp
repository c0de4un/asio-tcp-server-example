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
#ifndef APP_CLIENT_WINDOWS_MAIN_HPP
    #include <app/client/windows/main.hpp>
#endif /// !APP_CLIENT_WINDOWS_MAIN_HPP

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// MAIN
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main()
{
    std::cout << "Starting Client\n";

    boost::asio::io_context _context;

    boost::asio::ip::tcp::resolver _resolver(_context);

    boost::asio::ip::tcp::resolver::results_type _endpoint(
        _resolver.resolve(std::string("127.0.0.1"), std::to_string(8080))
    );

    boost::asio::ip::tcp::socket _socket(_context);

    boost::asio::connect(_socket, _endpoint);

    char _buf[256];
    boost::system::error_code _error;

    const size_t _len(
        _socket.read_some(boost::asio::buffer(&_buf, 256), _error)
    );

    if (_error)
    {
        if (_error == boost::asio::error::eof)
            std::cout << "Client: Connection closed by the Server\n";
        else
            throw boost::system::system_error(_error);
    }
    else
    {
        std::cout << "Server-Response: ";
        std::cout.write(_buf, _len);
        std::cout << "\n";
    }

    std::cout << "Stopping Client\n";

    std::cout << "Press any key to exit . . .\n";
    std::cin.get();

    return RESULT_OK;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
