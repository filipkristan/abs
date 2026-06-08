#include "libFK.hh"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

void fk::msg(int level, std::string message)
{
    std::string prefix = "";
    if (level == 0)
    {
        prefix = "[ INFO ] ";
    }
    else if (level == 1)
    {
        prefix = "[" + std::string("\033[32m") + " !OK! " + "\033[0m" + "] ";
    }
    else if (level == 2)
    {
        prefix = "[" + std::string("\033[33m") + " ???? " + "\033[0m" + "] ";
    }
    else
    {
        prefix = "[" + std::string("\033[31m") + " !!!! " + "\033[0m" + "] ";
    }
    std::cout << prefix << message << std::endl;
};

// Writes text to a file (Replaces all data with set text)
void fk::writeDataToFile(std::string location, std::string data, bool appendMode) {
    std::ofstream file;
    if (appendMode)
    {
        file.open(location, std::ios::app);
    }
    else
    {
        file.open(location, std::ios::out);
    }

    if (file.is_open())
    {
        file << data << "\n";
        file.close();
    }
    else
        std::cout << "File was closed!" << "\n";
}

// Returns the data read from a file
std::string fk::readDataFromFile(std::string location) {
    std::ifstream stream(location);
    std::string data;
    if (stream) {
        std::ostringstream ss;
        ss << stream.rdbuf();
        data = ss.str();
        std::erase(data, '\n');
    } else {
        std::cout << "Unable to read data from the file!" <<'\n';
        std::cout << "File location: " << location <<'\n';
    }
    return data;
}

std::vector<std::string> fk::readFileLines(const std::string& location) {
    std::ifstream stream(location);
    std::vector<std::string> lines;

    if (stream) {
        std::string line;
        while (std::getline(stream, line)) {
            lines.push_back(line);
        }
    } else {
        std::cout << "Unable to read data from the file!" << '\n';
        std::cout << "File location: " << location << '\n';
    }

    return lines;
}