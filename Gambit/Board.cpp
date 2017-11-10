//
// Created by Dan on 11/8/2017.
//

#include <iostream>
#include "Board.h"

Board::Board() {
    board = 0;
    setBitBoard();
}

Board::Board(Enums::Piece boardType, unsigned long boardValue) {
    this->board = boardValue;
    this->boardType = boardType;
    setBitBoard();
}

bool Board::setBitBoard() {
    bitBoard = std::bitset<64>(this->board);
    return true;
}

bool Board::setBitMask() {

    return false;
}

bool Board::placePiece(std::string rank, std::string file) {
    unsigned long piece = 1;

    int a = 63;
    int b = a - 1;
    int c = b - 1;
    int d = c - 1;
    int e = d - 1;
    int f = e - 1;
    int g = f - 1;
    int h = g - 1;

    piece = piece << d;

    for (int i = 0; i < 4 - 1; ++i) {
        piece = piece >> 8;
    }

    board = board | piece;
    return false;
}


