cmake_minimum_required(VERSION 3.8)
project(bs)

set(CMAKE_CXX_STANDARD 20)

add_executable(bs
        src/main.cc
        src/misc/libFK.cc
        src/misc/libFK.hh
        src/misc/src.cc
        src/misc/src.hh
        src/misc/progressBar.cc
        src/misc/progressBar.hh
)

set(RESOURCES_DIR "${CMAKE_INSTALL_PREFIX}/share/bs/res")

install(TARGETS bs DESTINATION /usr/local/bin)

install(DIRECTORY res/ DESTINATION ${RESOURCES_DIR})