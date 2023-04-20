#include "../../headers.hpp"

string sys(){
        string response;
#ifdef _WIN32
        response = "Windows";
#else
        struct utsname info;
        if (uname(&info) == 0)
            response = info.sysname;
        else
            response = "Unknown";
#endif
        return response;
}