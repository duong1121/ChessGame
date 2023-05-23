#pragma once
#include"Pieces.h"

class Knight :public Pieces {
private:
	virtual char getPiece() { return 'M'; }
	bool CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]);
public:
	~Knight() {}
	Knight(int color) :Pieces(color) {};
};