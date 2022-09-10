project(join_detach)
add_executable(${PROJECT_NAME} join_detach.c)
target_link_libraries(${PROJECT_NAME}
	pthread
)
