project(basic_thread)

add_executable(${PROJECT_NAME} basic_thread.c)

target_link_libraries(${PROJECT_NAME}
	pthread
)
