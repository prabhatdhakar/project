#include "../../headers.hpp"

string push_file(vector<string>& tokens){
    return tokens[0];
}

/*
string push_file(const vector<string>& tokens,boost::asio::ip::tcp::socket& sock)
{
    if (tokens.size() != 2)
        return "Usage: push <filename>";
    string filename = tokens[1];
    ofstream outfile(filename, ios::binary);
    if (!outfile)
        return "Error: could not open file for writing";
    try
    {
        boost::asio::streambuf buf;
        boost::asio::read_until(sock, buf, "\n");
        string data = boost::asio::buffer_cast<const char*>(buf.data());
        data = data.substr(0, data.size() - 1);
        while (data != "EOF")
        {
            outfile << data;
            boost::asio::read_until(sock, buf, "\n");
            data = boost::asio::buffer_cast<const char*>(buf.data());
            data = data.substr(0, data.size() - 1);
        }
        outfile.close();
        return "File uploaded successfully.";
    }
    catch (exception& e)
    {
        return "Exception: " + string(e.what());
    }
}*/