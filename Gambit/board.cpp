//
// Created by Dan on 11/8/2017.
//

#include <iostream>
#include "board.h"
#include "utils.h"

board::board() {
    b = 0;
    setBitBoard();
}

board::board(color boardColor, piece boardType, unsigned long long boardValue) {
    this->b = boardValue;
    this->boardType = boardType;
    this->boardColor = boardColor;
    setBitBoard();
}

bool board::setBitBoard() {
    bitBoard = std::bitset<64>(this->b);
    return true;
}

bool board::setBitMask(unsigned long long bitMask) {
    this->bitMask = bitMask;
    return true;
}

bool board::placePiece(std::string rank, std::string file) {
    unsigned long long piece = 0;
    int position = utils::getPieceLocation(rank, file);
    piece |= 1ULL << position;

    this->b |= piece;
    this->setBitBoard();
    return true;
}

bool board::removePiece(std::string rank, std::string file) {
    unsigned long long piece = this->b;
    int position = utils::getPieceLocation(rank, file);
    piece &= ~(1ULL << position);

    this->b &= piece;
    this->setBitBoard();
    return true;
}

bool board::movePiece(std::string startRank, std::string startFile, std::string endRank, std::string endFile) {
    this->placePiece(endRank, endFile);
    this->removePiece(startRank, startFile);

    this->setBitBoard();
    return true;
}
