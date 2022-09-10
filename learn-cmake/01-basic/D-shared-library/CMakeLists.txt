cmake_minimum_required(VERSION 3.5)
project(demo_hello_library)

# Generate the shared library from the library sources
add_library(hello_library SHARED
    src/hello.cpp
)
# Alternative name for the target
add_library(hello::library ALIAS hello_library)  
target_include_directories(hello_library
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# Add an executable with above sources
add_executable(hello_binary
    src/main.cpp
)

# Link the library to target
target_link_libraries(hello_binary
    PRIVATE
        hello::library
)