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
make
sudo make install
echo "*** Program Result:"
demo_cmake_install_bin
sudo xargs rm < install_manifest.txt
echo "*** Uninstalled target by clean install_manifest.txt"