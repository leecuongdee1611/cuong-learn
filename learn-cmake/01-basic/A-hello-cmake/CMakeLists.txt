# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# set the project name
project(hello_cmake)

# add the executable
add_executable(${PROJECT_NAME} main.cpp)