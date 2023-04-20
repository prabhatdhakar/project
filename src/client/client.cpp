#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include "../headers.hpp"

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 3)
        {
            cerr << "Usage: client <host> <port>\n";
            return 1;
        }

        // creating io_context object to handle I/O operations
        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);

        // establish connection or binding socket to endpoints
        tcp::resolver::results_type endpoints = resolver.resolve(argv[1], argv[2]);

        tcp::socket socket(io_context);

        boost::asio::connect(socket, endpoints);


        //user validation
        string username;
        string password;


        while(true){    
                    cout << "Enter username: ";
                    getline(cin, username);

                    cout << "Enter password: ";
                    getline(cin, password);

                    // Send username and password to server
                    string credentials = username + " " + password + "\n";
                    boost::asio::write(socket, boost::asio::buffer(credentials));

                    // Read response from server

                    boost::asio::streambuf buf;  // creating a buffer to rea and write data
                    boost::asio::read_until(socket, buf, "\n");

                    // assigning const char* to string 
                    string response = boost::asio::buffer_cast<const char*>(buf.data());

                    response = response.substr(0, response.size() - 1);

                    // Check if credentials are valid
                    if (response != "OK")
                    {
                        cerr << "Invalid credentials. Enter again!!\n";
                        continue;
                    }
                    break;
        }
       
        while (true)
        {
            cout << "ftp --> ";
            string command;
            getline(cin, command);

            if(command == "quit")
                break;

            boost::asio::write(socket, boost::asio::buffer(command + "\n"));
            boost::asio::streambuf buf;
            boost::asio::read_until(socket, buf, "\n");

            string response = boost::asio::buffer_cast<const char*>(buf.data());
            response = response.substr(0, response.size() - 1);

            if (command.substr(0, 3) == "get") {
                // Extract the filename from the command
                cout<<"downloading....\n";

                string filename = command.substr(4);
                if(response =="File not found."){
                    cout<<response<<endl;
                }else{
                    ofstream outfile("downloads/"+filename); // fs
                    outfile << response << endl; // Write received data to file
                    cout<<"DONE....\n";
                }
            }
            else if(command.substr(0, 4) == "push"){
                string filename = command.substr(4);
                cout<<push_file(filename); 
            }    
            else    
               cout << response << endl;

        }
    }
    catch (exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    return 0;
}
