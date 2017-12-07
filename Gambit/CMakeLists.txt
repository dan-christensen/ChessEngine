cmake_minimum_required(VERSION 3.7)
project(Gambit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp board.cpp board.h display.cpp display.h enums.h placement.cpp placement.h fileIO.cpp fileIO.h movement.cpp movement.h utils.cpp utils.h pieceEnum.cpp colorEnum.cpp M42/m42.cpp M42/m42.h turnHandler.cpp turnHandler.h gameHandler.cpp gameHandler.h TermColor/termcolor.hpp)
add_executable(Gambit ${SOURCE_FILES})