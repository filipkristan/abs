#include "File.hh"
#include "Build.hh"
#include "Message.hh"
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

using std::string;
using std::cout;
using std::endl;

bool fileExists(const string &filename) {
    return fs::exists(filename);
}

// Segregates to two files, one to list already installed libraries and another that lists libraries to install
void outputNeededLibraries(const string file, string librariesOutput) {
    std::vector lines = readFileLines(file);
    string query = "#include <"; // Match value to know what libraries to look for
    string queryEnd = ">";
    string library, searchLibraryPath;
    string foundLibrariesList = "out/libFound.txt"; // Output found libraries
    string notFoundLibrariesList = "out/libNotFound.txt"; // Output missing libraries
    for (size_t i = 0; i < lines.size(); ++i) {
        string line = lines[i];
        size_t result = -1;
        while ((result = line.find(query, result + 1)) != string::npos) {
            // Query for needed libraries
            size_t startPosition = result + query.length();
            size_t endPosition = line.find(queryEnd, startPosition);
            if (endPosition == string::npos) {
                cout << "Error: no \"endPosition! \"" << endl;
                break;
            }
            library = line.substr(startPosition, endPosition - query.length());
            writeDataToFile(librariesOutput, library, true); // Output needed libraries
            writeDataToFile(notFoundLibrariesList, library, true);
            searchLibraryPath = "/usr/local/include/" + library;
            if (fileExists(searchLibraryPath)) {
                writeDataToFile(foundLibrariesList, library, true);
            } else {
                writeDataToFile(notFoundLibrariesList, library, true);
            }
        }
    }
}

void generateBuildCommand(string buildFlagsPath, int argc, char *argv) {
    string allBuildFlags = readDataFromFile(buildFlagsPath);
    string inputFile;
    if (argc == 2) {
        inputFile = argv;
    }
    string outputFileName = "a.out";

#ifdef __APPLE__
#ifdef TARGET_OS_MAC
    string buildCommand = "clang++ " + inputFile + " -lstdc++ " + allBuildFlags + " -o " + outputFileName;
#endif
#elif defined(__linux__)
    string buildCommand = "g++ " + inputFile + " -lstdc++ " + allBuildFlags + " -o " + outputFileName;
#else
    string buildCommand = "g++ " + inputFile + " -lstdc++ " + allBuildFlags + " -o " + outputFileName;
#endif
    Message::msg(1, "Compiling the program!");
    system(buildCommand.c_str());
}

void runCompiledProgram() {
    if (fileExists("./a.out")) {
        Message::msg(1, "Running the compiled program!");
        system("export DYLD_LIBRARY_PATH=/usr/local/lib && ./a.out");
    } else {
        Message::msg(3, "Program not compiled, missing file.");
    }
}

void handleBuildingAndRunningTheProgram(string runLibraryInstallScripts, string buildFlagsPath, int argc,
                                        char *argv) {
    if (fileExists(runLibraryInstallScripts)) {
        system("sudo -S chmod -R a+rx /usr/local/share/bs/res");
        string cmd = "sudo -S chmod +x " + runLibraryInstallScripts + " && sudo -S bash " +
                     runLibraryInstallScripts;
        system(cmd.c_str());
        generateBuildCommand(buildFlagsPath, argc, argv);
    }
    runCompiledProgram();
}

void generateInstallScript(string foundLibraries) {
    std::vector<string> library = readFileLines(foundLibraries);
    std::vector<string> availableLibrariesToBeInstalled = readFileLines(
        "/usr/local/share/bs/res/availableLibs.txt");
    string availableLibraryBuildFlags = "/usr/local/share/bs/res/libraryBuildFlags";
    string buildScriptsDir = "/usr/local/share/bs/res/libraryBuildScripts/";
    string buildFlagsPath = "out/buildFlags.txt";
    string buildScriptPath = buildScriptsDir + "0" + ".sh";
    string runLibraryInstallScripts = "out/runLibraryInstallScripts.sh";
    for (size_t i = 0; i < library.size(); ++i) {
        for (size_t j = 0; j < availableLibrariesToBeInstalled.size(); ++j) {
            if (library[i] == availableLibrariesToBeInstalled[j]) {
                buildScriptPath = buildScriptsDir + std::to_string(j + 1) + ".sh";
                writeDataToFile(runLibraryInstallScripts, buildScriptPath, true);
                string buildFlagsFile = availableLibraryBuildFlags + "/" + std::to_string(j + 1) + ".txt";
                string buildFlagsFileData = " " + readDataFromFile(buildFlagsFile);
                writeDataToFile(buildFlagsPath, buildFlagsFileData, true);
            }
        }
    }
}
