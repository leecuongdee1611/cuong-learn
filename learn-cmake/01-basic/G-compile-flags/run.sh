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
# cmake .. -DCMAKE_CXX_FLAGS="-DEX3"
make VERBOSE=1
echo "*** Program Result:"
./cmake_compile_flags_bin