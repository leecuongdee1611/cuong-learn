project(sync_thread)
add_executable(${PROJECT_NAME} mutex.c)
target_link_libraries(${PROJECT_NAME}
    pthread
)