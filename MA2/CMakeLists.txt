cmake_minimum_required(VERSION 3.20)
project(MA2 C)

set(CMAKE_C_STANDARD 99)

add_executable(MA2 main.c)

add_subdirectory(MA2lib)
target_link_libraries(MA2 MA2lib)

