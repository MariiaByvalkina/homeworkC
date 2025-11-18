cmake_minimum_required(VERSION 3.25)

project(C_Homework C)

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(list src/list.c)

add_executable(listSort src/listSort.c src/test.c)
target_link_libraries(listSort PRIVATE list)

enable_testing()
