//
// Created by Dan on 11/8/2017.
//

#include <iostream>
#include "Board.h"
#include "Utils.h"
#include "M42/m42.h"

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

bool Board::setBitMask(Board* mainBoard, std::string rank, std::string file) {
    if (this->boardType == PAWN) {
        this->bitMask = M42::pawn_attacks(this->boardColor, Utils::getPieceLocation(rank, file));
    }
    if (this->boardType == KNIGHT) {
        this->bitMask = M42::knight_attacks(Utils::getPieceLocation(rank, file));
    }
    if (this->boardType == BISHOP) {
        this->bitMask = M42::bishop_attacks(Utils::getPieceLocation(rank, file), mainBoard->board);
    }
    if (this->boardType == ROOK) {
        this->bitMask = M42::rook_attacks(Utils::getPieceLocation(rank, file), mainBoard->board);
    }
    if (this->boardType == QUEEN) {
        this->bitMask = M42::queen_attacks(Utils::getPieceLocation(rank, file), mainBoard->board);
    }
    if (this->boardType == KING) {
        this->bitMask = M42::king_attacks(Utils::getPieceLocation(rank, file));
    }
    return true;
}

bool Board::placePiece(std::string rank, std::string file) {
    unsigned long long piece = 0;
    int position = Utils::getPieceLocation(rank, file);
    piece |= 1ULL << position;

    this->board |= piece;
    this->setBitBoard();
    return true;
}

bool Board::removePiece(std::string rank, std::string file) {
    unsigned long long piece = this->board;
    int position = Utils::getPieceLocation(rank, file);
    piece &= ~(1ULL << position);

    this->board &= piece;
    this->setBitBoard();
    return true;
}

bool Board::movePiece(std::string startRank, std::string startFile, std::string endRank, std::string endFile) {
    this->placePiece(endRank, endFile);
    this->removePiece(startRank, startFile);

    this->setBitBoard();
    return true;
}
