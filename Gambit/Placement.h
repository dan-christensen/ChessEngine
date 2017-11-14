//
// Created by Dan on 11/10/2017.
//

#ifndef GAMBIT_PLACEMENT_H
#define GAMBIT_PLACEMENT_H


#include "Board.h"

class Placement {
public:
    bool placePiece(Board* board, std::string rank, std::string file);
};


#endif //GAMBIT_PLACEMENT_H
