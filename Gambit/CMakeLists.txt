cmake_minimum_required(VERSION 3.8)
project(Gambit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Board.cpp Board.h Display.cpp Display.h Enums.h Placement.cpp Placement.h FileIO.cpp FileIO.h)
add_executable(Gambit ${SOURCE_FILES})