cmake_minimum_required(VERSION 3.25)

project(UniversalProject C)

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(ProjectLib
    testMicroDouble.c
)

add_executable(UniversalProject
    microDouble.c
)

target_link_libraries(UniversalProject PRIVATE ProjectLib)

enable_testing()