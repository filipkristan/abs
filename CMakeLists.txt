cmake_minimum_required(VERSION 3.8)
project(bs)

set(CMAKE_CXX_STANDARD 20)

add_executable(bs
        src/main.cc
        src/misc/Build.cc
        src/misc/Build.hh
        src/misc/Message.cc
        src/misc/Message.hh
        src/misc/File.cc
        src/misc/File.hh
)

set(RESOURCES_DIR "${CMAKE_INSTALL_PREFIX}/share/bs/res")

install(TARGETS bs DESTINATION /usr/local/bin)

install(DIRECTORY res/ DESTINATION ${RESOURCES_DIR})