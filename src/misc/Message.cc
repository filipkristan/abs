#include "Message.hh"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void Message::msg(int level, string message)
{
    string prefix = "";
    if (level == 0)
    {
        prefix = "[ INFO ] ";
    }
    else if (level == 1)
    {
        prefix = "[" + string("\033[32m") + " !OK! " + "\033[0m" + "] ";
    }
    else if (level == 2)
    {
        prefix = "[" + string("\033[33m") + " ???? " + "\033[0m" + "] ";
    }
    else
    {
        prefix = "[" + string("\033[31m") + " !!!! " + "\033[0m" + "] ";
    }
    cout << prefix << message << endl;
};
