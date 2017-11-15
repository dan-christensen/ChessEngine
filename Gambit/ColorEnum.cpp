//
// Created by Dan on 11/15/2017.
//

#include "Enums.h"

std::string ColorEnum::colorToString(int id){
    static const char* pieceStrings[] = {"White", "Black", "COLOR_DEFAULT"};
    return pieceStrings[id];
}
