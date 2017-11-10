cmake_minimum_required(VERSION 3.8)
project(Gambit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Board.cpp Board.h Display.cpp Display.h Enums.cpp Enums.h)
add_executable(Gambit ${SOURCE_FILES})