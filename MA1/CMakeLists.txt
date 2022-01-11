cmake_minimum_required(VERSION 3.20)
project(MA1 C)

set(CMAKE_C_STANDARD 99)


add_executable(MA1 main.c)

add_subdirectory(MA1lib)
target_link_libraries(MA1 MA1lib)

install(TARGETS MA1 DESTINATION bin)