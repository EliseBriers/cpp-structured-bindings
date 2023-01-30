# Set project name
project(catch2)

add_library(${PROJECT_NAME} catch_amalgamated.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)
