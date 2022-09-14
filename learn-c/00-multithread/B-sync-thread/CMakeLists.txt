project(sync_thread)
add_executable(${PROJECT_NAME} condition.c)
target_link_libraries(${PROJECT_NAME}
    pthread
)