//TODO: Finish movement check if space is available or if it is the opposite color.
//TODO: For Movement check if path is clear and if the end space is clear.
//TODO: For capture, just check if the path is clear and that the end space is an enemy.
//TODO: Make the Board drawing abstract.
//TODO: Combine white/black boards.

#include "M42/m42.h"
#include "GameHandler.h"

int main() {
    GameHandler game;
    M42::init();
    game.init();

    bool isRunning = true;

    while (isRunning) {
        game.draw();
        isRunning = game.update();
    }

//    Display d;
//    TurnHandler* t = new TurnHandler();
//    Board* mainBoard = new Board(COLOR_DEFAULT, PIECE_DEFAULT, 0);
//    Board* testKnightBoard = new Board(WHITE, QUEEN, 0);
//    Board* testPawnBoard = new Board(BLACK, PAWN, 0);
//    testKnightBoard->placePiece("D", "4");
//    testPawnBoard->placePiece("E", "6");
//    std::vector<Board*> allBoards;
//    allBoards.push_back(testKnightBoard);
//    allBoards.push_back(testPawnBoard);
//    Utils::combineBoards(allBoards, mainBoard);
//    d.drawBoard(allBoards);
//    testKnightBoard->bitMask = M42::knight_attacks(Utils::getPieceLocation("D", "4"));
//    d.drawBoard(testKnightBoard->bitMask);
//    std::cout << std::bitset<64>(testKnightBoard->bitMask & mainBoard->board) << std::endl;

    return 0;
}