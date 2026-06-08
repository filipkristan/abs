#include "File.hh"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using std::string;
using std::cout;
using std::endl;

// Writes text to a file (Replaces all data with set text)
void writeDataToFile(string location, string data, bool appendMode) {
    std::ofstream file;
    if (appendMode) {
        file.open(location, std::ios::app);
    } else {
        file.open(location, std::ios::out);
    }

    if (file.is_open()) {
        file << data << "\n";
        file.close();
    } else
        cout << "File was closed!" << "\n";
}

// Returns the data read from a file
string readDataFromFile(string location) {
    std::ifstream stream(location);
    string data;
    if (stream) {
        std::ostringstream ss;
        ss << stream.rdbuf();
        data = ss.str();
        std::erase(data, '\n');
    } else {
        cout << "Unable to read data from the file!" << '\n';
        cout << "File location: " << location << '\n';
    }
    return data;
}

std::vector<string> readFileLines(const string &location) {
    std::ifstream stream(location);
    std::vector<string> lines;
    if (stream) {
        string line;
        while (std::getline(stream, line)) {
            lines.push_back(line);
        }
    } else {
        cout << "Unable to read data from the file!" << '\n';
        cout << "File location: " << location << '\n';
    }
    return lines;
}
