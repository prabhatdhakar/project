#ifndef HEADERS
#define HEADERS
#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <sstream>
#include <filesystem>
#include <fstream>
using namespace std;

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/utsname.h>
#endif



using boost::asio::ip::tcp;

string handle_command(const string&);
string pwd();
string mkdir(vector<string>&);
string rm_dir(vector<string>&);
string list(vector<string>&);
string change_dir(vector<string>&);
string sys();
string get_file(vector<string>&);
string user_validation(vector<string>&);
string push_file(string&);
string mv_cmd(vector<string>& );
string cp_cmd(vector<string>&);
vector<string> split_string(const string&, char);

#endif