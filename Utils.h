//
// Created by Dan on 11/15/2017.
//

#ifndef GAMBIT_UTILS_H
#define GAMBIT_UTILS_H


#include "Gambit/Enums.h"

class Utils {
public:
    static Piece getPiece(char pieceToken);
    static Color getColor(char colorToken);
};


#endif //GAMBIT_UTILS_H
