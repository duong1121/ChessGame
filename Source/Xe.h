#pragma once
#include"Pieces.h"

class Rook :public Pieces {
private:
	virtual char getPiece() { return 'X'; }
	bool CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]);
public:
	~Rook() {}
	Rook(int color) :Pieces(color) {};
};