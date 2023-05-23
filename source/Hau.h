#pragma once
#include"Pieces.h"

class Queen :public Pieces {
	virtual char getPiece() { return 'H'; }
	bool CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]);
public:
	~Queen() {}
	Queen(int color) :Pieces(color) {};
};