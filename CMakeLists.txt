cmake_minimum_required(VERSION 3.8)
project(bs)

set(CMAKE_CXX_STANDARD 20)

add_executable(bs
        main.cc
        libFK.cc
        libFK.hh
        src.cc
        src.hh
        progressBar.cc
        progressBar.hh
)

set(RESOURCES_DIR "${CMAKE_INSTALL_PREFIX}/share/bs/res")

install(TARGETS bs DESTINATION /usr/local/bin)

install(DIRECTORY res/ DESTINATION ${RESOURCES_DIR})