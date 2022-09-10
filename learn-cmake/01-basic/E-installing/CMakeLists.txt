cmake_minimum_required(VERSION 3.5)
project(demo_cmake_install)

# Generate the shared library from the library sources
add_library(hello_library SHARED
    src/hello.cpp
)
target_include_directories(hello_library
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# Create an executable with the above sources
add_executable(demo_cmake_install_bin
    src/main.cpp
)

# Link the library to the target
target_link_libraries(demo_cmake_install_bin
    PRIVATE
        hello_library
)

############# Install ############
# Binaries
install (TARGETS demo_cmake_install_bin
    DESTINATION bin
)
# Library
install (TARGETS hello_library
    LIBRARY DESTINATION lib
)
# Header files
install (DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include
)
# Config
install (FILES cmake-examples.conf
    DESTINATION etc
)