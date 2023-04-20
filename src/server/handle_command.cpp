#include "../headers.hpp"

string handle_command(const string& command)
{
    vector<string> tokens = split_string(command, ' ');
    if (tokens[0] == "pwd")
        return pwd();
    else if (tokens[0] == "mkdir")
        return mkdir(tokens);
    else if (tokens[0] == "ls")
        return list(tokens);
    else if (tokens[0] == "cd")
        return change_dir(tokens);
    else if (tokens[0] == "rm")
        return rm_dir(tokens);
    else if (tokens[0] == "sys")
        return sys();
    else if (tokens[0] == "get")
        return get_file(tokens);
          
    else if(tokens[0] == "mv")
            return mv_cmd(tokens);
    else if(tokens[0] == "cp")
            return cp_cmd(tokens);
    else if(tokens[0][0] == '@')
            return user_validation(tokens);
    else
        return "Unknown command.";
}