#include "../../headers.hpp"

string change_dir(vector<string>& tokens){
        if (tokens.size() == 1)
            return "Usage: cd <directory_path>";
        else
        {
            try
            {
                filesystem::current_path(tokens[1]);
                return "Directory changed successfully.";
            }
            catch (exception& e)
            {
                return "Failed to change directory: " + string(e.what());
            }
        }
}