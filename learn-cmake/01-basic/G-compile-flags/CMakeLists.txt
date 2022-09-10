cmake_minimum_required(VERSION 3.5)

# SET A DEFAULT C++ COMPILE FLAG
# This method is not recommended for general usage
# The target_compile_definitions function is preferred
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DEX2" CACHE STRING "Set C++ Compile Flags" FORCE)

project(compile_flags)
add_executable(cmake_compile_flags_bin main.cpp)

# Set Per-Target flags
# This will cause the compiler to add the definition
# -DEX3 when compiling the target
# cmake .. -DCMAKE_CXX_FLAGS="-DEX3"
target_compile_definitions(cmake_compile_flags_bin
    PRIVATE EX3)