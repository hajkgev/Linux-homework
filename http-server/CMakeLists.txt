cmake_minimum_required(VERSION 3.0)

project(http-server)

add_executable("${PROJECT_NAME}" source.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

target_link_libraries("${PROJECT_NAME}" PRIVATE Threads::Threads)

add_subdirectory(lib)
add_subdirectory(scheduler_lib)

target_link_libraries("${PROJECT_NAME}" PUBLIC lib scheduler_lib)

target_include_directories("${PROJECT_NAME}" PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/lib"
        "${PROJECT_SOURCE_DIR}/scheduler_lib"
        )

