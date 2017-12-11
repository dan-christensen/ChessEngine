//
// Created by Dan on 11/15/2017.
//

#ifndef GAMBIT_UTILS_H
#define GAMBIT_UTILS_H


#include <vector>
#include "Enums.h"
#include "Board.h"

class Utils {
public:
    static Piece getPiece(char pieceToken);
    static Color getColor(char colorToken);
    static bool combineBoards(std::vector<Board*> allBoards, Board* mainBoard);
    static Board* getBoard(std::vector<Board*> allBoards, Color color, Piece piece);
    static int getPieceLocation(std::string rank, std::string file);
    static std::string pieceLocationToMove(int location);
    static bool isSpaceClear(int position, unsigned long long board);
};


#endif //GAMBIT_UTILS_H
