#!/bin/bash
g++ -E preprocessor.cpp > test.p
g++ -o execute preprocessor.cpp
./execute
