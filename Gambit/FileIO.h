//
// Created by Dan on 11/14/2017.
//

#ifndef GAMBIT_FILEIO_H
#define GAMBIT_FILEIO_H


#include "Enums.h"
#include "Board.h"
#include "Placement.h"

#include <string>
#include <regex>
#include <iostream>
#include <vector>

class FileIO {
public:
    bool parseFile(std::string move, std::vector<Board*>* allBoards, Board* mainBoard);

private:
    bool parsePlacement(std::string move, std::vector<Board*>* allBoards, Board* mainBoard);
    bool paresMove(std::string move, std::vector<Board*>* allBoards, Board* mainBoard);

    Placement* placement;

};


#endif //GAMBIT_FILEIO_H
