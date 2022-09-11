#!/bin/bash
if [ -d "build" ]
then
	#rm -rf build
	#echo "*** Folder build/ removed"
fi

mkdir build
cd build
cmake ..
make
