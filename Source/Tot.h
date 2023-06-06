#pragma once
#include"Pieces.h"

class Pawn :public Pieces {
public:
	~Pawn() {}
	Pawn(int color) :Pieces(color) {};
private:
	virtual char getPiece() { return 'T'; }
	bool CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]);

};