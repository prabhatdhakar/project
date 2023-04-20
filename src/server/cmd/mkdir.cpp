#include "../headers.hpp"
string mkdir(vector<string>& tokens){
        if (tokens.size() == 1)
            return "Usage: mkdir <directory_name>";
        else
        {
            filesystem::create_directory(tokens[1]);
            return "Directory created successfully.";
        }
}