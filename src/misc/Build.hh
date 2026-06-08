#ifndef BUILD_HH
#define BUILD_HH

class Build {
};

bool fileExists(const std::string &filename);
void outputNeededLibraries(std::string file, std::string librariesOutput);
void generateBuildCommand(std::string buildFlagsPath, int argc, char *argv);
void runCompiledProgram();
void handleBuildingAndRunningTheProgram(std::string runLibraryInstallScripts, std::string buildFlagsPath, int argc, char *argv);
void generateInstallScript(std::string foundLibraries);

#endif
