//
// Created by Dan on 11/15/2017.
//

#ifndef GAMBIT_UTILS_H
#define GAMBIT_UTILS_H


#include <vector>
#include "enums.h"
#include "board.h"

class utils {
public:
    static piece getPiece(char pieceToken);
    static color getColor(char colorToken);
    static bool combineBoards(std::vector<board*> allBoards, board* mainBoard);
    static board* getBoard(std::vector<board*> allBoards, color color, piece piece);
    static int getPieceLocation(std::string rank, std::string file);
    static bool isSpaceClear(int position, unsigned long long board);
};


#endif //GAMBIT_UTILS_H
