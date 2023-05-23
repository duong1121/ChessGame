#pragma once
#include"Pieces.h"

class Bishop :public Pieces {
private:
	virtual char getPiece() { return 'T'; }
	bool CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]);
public:
	~Bishop() {}
	Bishop(int color) :Pieces(color) {};
};