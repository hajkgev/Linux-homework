target_link_libraries("${PROJECT_NAME}" PUBLIC http_lib scheduler_lib)

target_include_directories("${PROJECT_NAME}" PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/http_lib"
        "${PROJECT_SOURCE_DIR}/scheduler_lib"
        )

