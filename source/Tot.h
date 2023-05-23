#pragma once
#include"Pieces.h"

class Pawn :public Pieces {
private:
	virtual char getPiece() { return 'T'; }
	bool CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]);
public:
	~Pawn() {}
	Pawn(int color) :Pieces(color) {};
};