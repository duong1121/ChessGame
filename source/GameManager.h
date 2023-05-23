#pragma once
#include <iostream>
#include "Board.h"
#include "Pieces.h"

class ChessGame
{
public:
    ChessGame() : turnOf(0) {}
    ~ChessGame() {}
    void enterNames();
    void start();
    bool isGameOver();

protected:
    void getNextMove(Pieces* board[8][8]);
    void alternateTurn();
    void printPlayers(std::string time);
    std::string nameA;
    std::string nameB;
    std::string getCurrentTime();
    struct tm* endTime;
    bool exitCode;

private:
    Board gameBoard;
    int turnOf;
};