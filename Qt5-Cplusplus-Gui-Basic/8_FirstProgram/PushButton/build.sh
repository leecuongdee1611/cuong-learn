#!/bin/bash
projectname=${PWD##*/}
echo "Building project $projectname"
qmake -project
echo "QT += widgets" >> ./$projectname.pro
qmake
make
./$projectname
