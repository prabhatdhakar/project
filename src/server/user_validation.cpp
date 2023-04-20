#include "../headers.hpp"

string user_validation(vector<string>& tokens){
        if(tokens[0] == "@ftpserver" && tokens[1] == "1234"){
            return "OK";
        }
        return "-1";
}