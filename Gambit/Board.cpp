//
// Created by Dan on 11/8/2017.
//

#include <iostream>
#include "Board.h"

Board::Board() {
    board = 0;
    setBitBoard();
}

Board::Board(Color boardColor, Piece boardType, unsigned long long boardValue) {
    this->board = boardValue;
    this->boardType = boardType;
    this->boardColor = boardColor;
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
    unsigned long long piece = 1;

    int a = 63;
    int b = a - 1;
    int c = b - 1;
    int d = c - 1;
    int e = d - 1;
    int f = e - 1;
    int g = f - 1;
    int h = g - 1;

    int localRank = 0;
    int localFile = 0;

    if (rank == "A" || rank == "a") localRank = a;
    if (rank == "B" || rank == "b") localRank = b;
    if (rank == "C" || rank == "c") localRank = c;
    if (rank == "D" || rank == "d") localRank = d;
    if (rank == "E" || rank == "e") localRank = e;
    if (rank == "F" || rank == "f") localRank = f;
    if (rank == "G" || rank == "g") localRank = g;
    if (rank == "H" || rank == "h") localRank = h;

    if (file == "1") localFile = 1;
    if (file == "2") localFile = 2;
    if (file == "3") localFile = 3;
    if (file == "4") localFile = 4;
    if (file == "5") localFile = 5;
    if (file == "6") localFile = 6;
    if (file == "7") localFile = 7;
    if (file == "8") localFile = 8;

    int position = (localRank - (8 * (localFile - 1)));

    piece = piece << position;

    board = board | piece;
    this->setBitBoard();
    return true;
}

bool Board::removePiece(std::string rank, std::string file) {
    return false;
}

bool Board::movePiece(std::string startRank, std::string startFile, std::string endRank, std::string endFile) {
    this->placePiece(endRank, endFile);


    this->setBitBoard();
    return true;
}
