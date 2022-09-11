project(Test)
add_executable(${PROJECT_NAME} test.c)
target_link_libraries(${PROJECT_NAME}
	pthread
)
