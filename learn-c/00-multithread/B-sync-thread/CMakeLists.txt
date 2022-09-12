project(sync_thread)
add_executable(${PROJECT_NAME} mutex1.c)
target_link_libraries(${PROJECT_NAME}
    pthread
)