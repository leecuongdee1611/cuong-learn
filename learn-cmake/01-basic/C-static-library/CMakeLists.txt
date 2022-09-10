cmake_minimum_required(VERSION 3.5)
project(hello_library)

# Generate the static library from the library sources
add_library(hello_library STATIC
    src/hello.cpp
)
target_include_directories(hello_library
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# Add an executable with the above sources
add_executable(hello_binary
    src/main.cpp
)

# Link the new library
target_link_libraries(hello_binary
    PRIVATE
        hello_library
)