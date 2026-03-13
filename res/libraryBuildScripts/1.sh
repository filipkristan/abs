#!/bin/bash

depriv() {
  if [[ $SUDO_USER ]]; then
    sudo -u "$SUDO_USER" -- "$@"
  else
    "$@"
  fi
}

{
if [ ! -f /usr/local/include/GLFW/glfw3.h ]; then
    rm -rf glfw-3.4*
    depriv curl https://github.com/glfw/glfw/releases/download/3.4/glfw-3.4.zip -L -O -J
    depriv unzip glfw-3.4.zip
    depriv mkdir /usr/local/include
    rm -rf /usr/local/include/GLFW
    mv glfw-3.4/include/GLFW /usr/local/include/
    rm -rf glfw-3.4* > /dev/null
    exit 0
fi
}