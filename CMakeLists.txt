cmake_minimum_required(VERSION 3.25)

project(cmake C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

add_library(Stack src/stack.c)

add_executable(sortStation src/sortStation.c)
add_executable(balanced src/balanced.c)

target_link_libraries(balanced PRIVATE Stack)
target_link_libraries(sortStation PRIVATE Stack)
