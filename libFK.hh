#ifndef LIBFK_FK_HH
#define LIBFK_FK_HH

#include <string>
#include <vector>

class fk
{
public:
    static void msg(int level, std::string message);
    static void writeDataToFile(std::string location, std::string data, bool appendMode);
    static std::string readDataFromFile(std::string location);
    static std::vector<std::string> readFileLines(const std::string &location);
};


#endif //LIBFK_FK_HH
