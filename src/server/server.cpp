
#include "../headers.hpp"

mutex mtx; // declared a mutex

void session(tcp::socket sock)
{
    try
    {
        while (true)
        {
            boost::asio::streambuf buf;

            boost::asio::read_until(sock, buf, "\n");

            string data = boost::asio::buffer_cast<const char*>(buf.data());

            data = data.substr(0, data.size() - 1);

            string response = handle_command(data) + "\n";

            mtx.lock(); // acquire a lock

            boost::asio::write(sock, boost::asio::buffer(response));

            mtx.unlock(); // release the lock
        }
    }
    catch (exception& e)
    {
        cerr << "Exception in thread: " << e.what() << endl;
    }
}

void server(boost::asio::io_context& io_context, unsigned short port)
{
    // listening for incoming tcp connecctions on specified IP address and port no.
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));

    while (true)
    {
        try
        {
            tcp::socket sock(io_context);

            // accept incoming network connections on a listening socket
            acceptor.accept(sock);

            // detaching the thread
            thread(session, move(sock)).detach();
        }
        catch (exception& e)
        {
            cerr << "Exception in thread: " << e.what() << endl;
        }
    }
}

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 2)
        {
            cerr << "Usage: server <port>\n";
            return 1;
        }
        boost::asio::io_context io_context;

        // creating new thread and passing io_context by reference and port number i.e allowing the server to run simultaneously with other tasks in main thread.
        thread t(server, ref(io_context), atoi(argv[1]));

        t.join(); // wait for thread to complete and then executes the other instructions 
    }
    catch (exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}