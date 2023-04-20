#include "../../headers.hpp"

string mv_cmd(vector<string>& tokens){
    if (tokens.size() <3)
            return "Usage: mv <old_directory/file_name> <new_directory/file_name>";
    else
    {
        try {
            filesystem::rename(tokens[1], tokens[2]);
            return "File renamed successfully.\n";
            }
        catch (filesystem::filesystem_error& e) {
            return e.what();
        }
    }        
}