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
    int position = Utils::getPieceLocation(rank, file);
    piece |= 1ULL << position;

    board = board | piece;
    this->setBitBoard();
    return true;
}

bool Board::removePiece(std::string rank, std::string file) {
    unsigned long long piece = 1;
    int position = Utils::getPieceLocation(rank, file);
    piece &= 1ULL << position;

    board = board | piece;
    this->setBitBoard();
    return true;
}

bool Board::movePiece(std::string startRank, std::string startFile, std::string endRank, std::string endFile) {
    this->placePiece(endRank, endFile);


    this->setBitBoard();
    return true;
}
