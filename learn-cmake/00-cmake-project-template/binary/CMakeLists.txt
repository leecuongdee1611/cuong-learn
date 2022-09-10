project(cmake_project)

# Create the executable
add_executable(${PROJECT_NAME} main.c)

# Link include directory 
target_include_directories(${PROJECT_NAME}
	PRIVATE
		${PROJECT_SOURCE_DIR}/include
)

# Link the static library
# Link the header only library
target_link_libraries(${PROJECT_NAME}
	sub::lib1
	sub::lib2
)
