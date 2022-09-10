#!/bin/bash
if [ -d "build" ]
then
    rm -rf build
    echo "*** Folder build/ removed"
fi
mkdir build
echo "*** Folder build/ created"
cd build
cmake ..
# ccmake ..
cmake .. -DCMAKE_BUILD_TYPE=MinSizeRel
make VERBOSE=1
echo "*** Program Result:"
./cmake_build_type_bin
echo "*** Check size"
size cmake_build_type_bin # Haven't check on macbook