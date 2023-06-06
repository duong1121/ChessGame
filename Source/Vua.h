#pragma once
#include"Pieces.h"

class King :public Pieces {
private:
	virtual char getPiece() { return 'V'; }
	bool CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]);
public:
	~King() {}
	King(int color) :Pieces(color) {};
};