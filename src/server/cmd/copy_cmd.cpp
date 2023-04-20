#include "../../headers.hpp"

string cp_cmd(vector<string>& tokens){
    if (tokens.size() <3)
        return "Usage: mv <source_path> <target_path>";
    else{    
    try {
        if (filesystem::is_regular_file(tokens[1])) {
            // Copy a file
            filesystem::copy_file(tokens[1], tokens[2], filesystem::copy_options::overwrite_existing);
            return "done..\n";
        } else if (filesystem::is_directory(tokens[1])) {
            // Copy a directory
            filesystem::copy(tokens[1], tokens[2], filesystem::copy_options::recursive | filesystem::copy_options::overwrite_existing);
            return "done..\n";
        } else {
            return "Invalid path:\n ";
        }
    } catch (const exception& ex) {
        return ex.what();
    }
    }
}