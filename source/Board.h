#pragma once
#include "Hau.h"
#include "Ma.h"
#include "Tinh.h"
#include "Tot.h"
#include "Vua.h"
#include "Xe.h"

using namespace std;
class Board
{
public:
	Board();
	~Board();
	void printBoard();
	bool isInCheck(int color);
	bool canMove(int color);
	Pieces* board[8][8];
};