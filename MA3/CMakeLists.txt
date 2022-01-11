cmake_minimum_required(VERSION 3.20)
project(MA3 C)

set(CMAKE_C_STANDARD 99)

add_executable(MA3 main.c)

add_subdirectory(MA3lib)
target_link_libraries(MA3 MA3lib)