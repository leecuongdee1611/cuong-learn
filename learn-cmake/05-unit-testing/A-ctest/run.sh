#!/bin/bash
if [ -d "build" ]
then
    rm -rf build
	echo ""
    echo "*** Folder build/ removed"
fi
mkdir build
echo ""
echo "*** Folder build/ created"
cd build
cmake ..
make
echo ""
echo "*** Program Result:"
./demo_ctest 4
echo ""
echo "*** Ctest working"
ctest -V
