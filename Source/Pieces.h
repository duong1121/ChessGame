#pragma once
#include<iostream>
struct pos {
	int Col;
	int Row;
};
class Pieces {
public:
	Pieces(int color) {
		Color = color;
	}
	virtual ~Pieces(){
	}
	virtual char getPiece()=0;
	int getPieceColor();

	//static bool isWhitePiece();

	//static bool isBlackPiece();
	pos Pos;
	bool isLegalMove(int DesCol, int DesRow, Pieces* Board[8][8]);
private:
	virtual bool CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8])=0;
	int Color;
	/*enum color {
		White =   0,
		Black = 1
	};*/
	
};