cmake_minimum_required(VERSION 3.20)
project(MA1lib C)

set(CMAKE_C_STANDARD 99)

add_library(MA2lib STATIC matrixOp.c)

install(TARGETS MA2lib DESTINATION lib)
install(FILES complexma1lib.h DESTINATION include)
