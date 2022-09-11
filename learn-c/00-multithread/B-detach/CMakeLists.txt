project(detach)
add_executable(${PROJECT_NAME} detach.c)
target_link_libraries(${PROJECT_NAME}
	pthread
)
