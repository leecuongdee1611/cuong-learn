cmake_minimum_required(VERSION 3.5)

# set the project name and version
project(demo_ctest VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source
configure_file(Config.h.in Config.h)

# Add the MathFunc library
if(USE_MYMATH)
	add_subdirectory(lib-math)
	list(APPEND EXTRA_LIBS MathLib)
endif()

# add the executable
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find Config.h
target_include_directories(${PROJECT_NAME}
	PUBLIC
		${PROJECT_BINARY_DIR}
)

# enable testing
enable_testing()
# does the application run
add_test(NAME Runs COMMAND ${PROJECT_NAME} 25)
# does the usage message work?
add_test(NAME Usage COMMAND ${PROJECT_NAME})
set_tests_properties(Usage
	PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
)
# define a function to simplify adding tests
function(do_test target arg result)
	add_test(NAME Comp${arg} COMMAND ${target} ${arg})
	set_tests_properties(Comp${arg}
		PROPERTIES PASS_REGULAR_EXPRESSION ${result}
	)
endfunction()

# do a bunch of result based tests
do_test(${PROJECT_NAME} 4 "4 is 2")
do_test(${PROJECT_NAME} 9 "9 is 3")
do_test(${PROJECT_NAME} 5 "5 is 2.236")
do_test(${PROJECT_NAME} 7 "7 is 2.645")
do_test(${PROJECT_NAME} 25 "25 is 5")
do_test(${PROJECT_NAME} -25 "-25 is (-nan|nan|0)")
do_test(${PROJECT_NAME} 0.0001 "0.0001 is 0.01")
