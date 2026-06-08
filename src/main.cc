#include "misc/Message.hh"
#include "misc/Build.hh"
#include <filesystem>
#include <string>
#include <chrono>

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        Message::msg(3, "No input file specified.");
    } else if (argc > 2) {
        Message::msg(3, "Too many inputs specified.");
    } else {
        fs::create_directory("out");
        outputNeededLibraries(&*argv[1], "out/neededLibraries.txt");
        generateInstallScript("out/libNotFound.txt");
        handleBuildingAndRunningTheProgram("out/runLibraryInstallScripts.sh", "out/buildFlags.txt", argc, argv[1]);
        system("rm -rf out");
        system("rm -rf a.out");
    }
    return 0;
}
