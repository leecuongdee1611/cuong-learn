#!/bin/bash
if [ -d "build" ]
then
	cho "*** Removing build data"
	cd build
	rm -rf *
fi
cmake ..
make

echo "*** Program Result:"
./01-function-pointer/A-replace-switch/replace-switch