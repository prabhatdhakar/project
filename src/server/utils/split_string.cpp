#include "../../headers.hpp"

vector<string> split_string(const string& str, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream token_stream(str);
    while (getline(token_stream, token, delimiter))
        tokens.push_back(token);
    return tokens;
}