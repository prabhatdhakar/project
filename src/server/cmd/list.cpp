#include "../../headers.hpp"

string list(vector<string>& tokens){
        ostringstream output;
        if(tokens.size() > 2){
            return "Usage: ls <directory_name>";
        }
        else if(tokens.size() == 1){
            for (auto& entry : filesystem::directory_iterator("."))
                output << entry.path().filename().string() << endl;
        }
        else{
            try
            {
                for (auto& entry : filesystem::directory_iterator(tokens[1]))
                output << entry.path().filename().string() << endl;
            }
            catch (exception& e)
            {
                return "Error: " + string(e.what());
            }
        }
        return output.str();
}