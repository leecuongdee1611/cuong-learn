#!/bin/bash
if [ -d "build" ]
then
	cho "*** Removing build data"
	cd build
	# rm -rf *
fi
# cmake ..
make

echo "*** Program Result:"
./00-multithread/A-basic-thread/basic_thread