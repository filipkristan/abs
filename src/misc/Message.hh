#ifndef BUILD_SYSTEM_MESSAGE_HH
#define BUILD_SYSTEM_MESSAGE_HH
#include <string>

using std::string;

class Message {
public:
    static void msg(int level, string message);
};

#endif //BUILD_SYSTEM_MESSAGE_HH
