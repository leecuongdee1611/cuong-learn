#!/bin/bash
WS=../
cd $WS
if [ -d "build" ]
then
    rm -rf build
    echo "*** Folder build/ removed"
fi
mkdir build
echo "*** Folder build/ created"
cd build
cmake ..
make
echo "*** Program Result: /build/binary/"
cd binary
./cmake_project
