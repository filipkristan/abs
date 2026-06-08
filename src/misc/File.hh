#ifndef BUILD_SYSTEM_FILE_HH
#define BUILD_SYSTEM_FILE_HH
#include <string>
#include <vector>

class File {
};

void writeDataToFile(std::string location, std::string data, bool appendMode);
std::string readDataFromFile(std::string location);
std::vector<std::string> readFileLines(const std::string &location);

#endif //BUILD_SYSTEM_FILE_HH
