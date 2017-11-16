//
// Created by Dan on 11/15/2017.
//

#ifndef GAMBIT_UTILS_H
#define GAMBIT_UTILS_H

#include "Enums.h"
#include "Board.h"

#include <vector>

class Utils {
public:
    static Piece getPiece(char pieceToken);
    static Color getColor(char colorToken);
    static bool combineBoards(std::vector<Board*> allBoards, Board* mainBoard);
    static Board* getBoard(std::vector<Board*> allBoards, Color color, Piece piece);
};


#endif //GAMBIT_UTILS_H
