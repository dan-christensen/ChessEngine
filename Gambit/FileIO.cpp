//
// Created by Dan on 11/14/2017.
//

#include "FileIO.h"

bool FileIO::parseFile(std::string move, std::vector<Board*> allBoards, Board* mainBoard) {
    std::string input = move;
    for (auto& c: input) c = toupper(c);

    std::regex placementPattern("([KQBNRP])([DL])(([A-H])([1-8]))");
    std::regex movementPattern("(([A-H])([1-8])([A-H])([1-8]))\\*?");

    if (std::regex_match(input, placementPattern)) {
        return parsePlacement(input, allBoards, mainBoard);
    } else if (std::regex_match(input, movementPattern)) {
        return paresMove(input, allBoards, mainBoard);
    }

    return true;
}

bool FileIO::parsePlacement(std::string move, std::vector<Board*> allBoards, Board* mainBoard) {
    return placement->placePiece(move, allBoards, mainBoard);
}

bool FileIO::paresMove(std::string move, std::vector<Board*> allBoards, Board* mainBoard) {
    return movement->movePiece(move, allBoards, mainBoard);
}

std::string FileIO::getUserInput() {
    std::string rVal;
    std::cout <<  "Please enter a move: ";
    std::cin >> rVal;
    return rVal;
}
