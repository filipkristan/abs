#!/bin/bash

depriv() {
  if [[ $SUDO_USER ]]; then
    sudo -u "$SUDO_USER" -- "$@"
  else
    "$@"
  fi
}

{
if [ ! -f /usr/local/include/raylib.h ]; then
    echo "Raylib not found!"
    rm -rf raylib-5.5_macos.tar.gz && rm -rf raylib-5.5_macos
    echo "Downloading raylib..."
    curl https://github.com/raysan5/raylib/releases/download/5.5/raylib-5.5_macos.tar.gz -L -O -J > /dev/null 2>&1
    tar -xvf raylib-5.5_macos.tar.gz > /dev/null 2>&1
    depriv cd raylib-5.5_macos
    cp -r raylib-5.5_macos/include/ /usr/local/include
    chown -R $(whoami) /usr/local/include
    cp -r raylib-5.5_macos/lib/ /usr/local/lib
    chown -R $(whoami) /usr/local/lib
    export DYLD_LIBRARY_PATH=/usr/local/lib
    exit 0
fi
}

