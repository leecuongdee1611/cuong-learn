project(thread_create)

add_executable(${PROJECT_NAME} thread_create.c)

target_link_libraries(${PROJECT_NAME}
	pthread
)
