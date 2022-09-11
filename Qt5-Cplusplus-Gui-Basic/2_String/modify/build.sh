#!/bin/bash
echo "Building"
qmake -project
qmake
make
