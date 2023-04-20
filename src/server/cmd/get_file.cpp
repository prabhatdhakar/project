#include "../../headers.hpp"

string get_file(vector<string>& tokens){
        if (tokens.size() == 1)
            return "Usage: get <file_path>";
        else
        {
            ifstream file(tokens[1], ios::binary | ios::ate);
            if (!file)
                return "File not found.";
            else if(file){
                streamsize size = file.tellg();
                file.seekg(0, ios::beg);
                vector<char> buffer(size);
                if (file.read(buffer.data(), size))
                {
                    return string(buffer.data(), size);
                }
            }
            else
                return "Error reading file.";
        }
}