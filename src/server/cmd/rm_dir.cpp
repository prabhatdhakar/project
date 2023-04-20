#include "../../headers.hpp"

string rm_dir(vector<string>& tokens){
    if (tokens.size() == 1)
            return "Usage: rm <directory_name>";
        else
        {
            try
            {
                filesystem::remove_all(tokens[1]);
                return "Directory removed successfully.";
            }
            catch (exception& e)
            {
                return "Error: " + string(e.what());
            }
        }
}