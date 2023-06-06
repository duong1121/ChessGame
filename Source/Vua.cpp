#include"Vua.h"

bool King::CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]) {
	int calcRow = DesRow - Pos.Row;
	int calcDest = DesCol - Pos.Col;
	if (((calcRow >= -1) && (calcRow <= 1)) &&
		((calcDest >= -1) && (calcDest <= 1)))
	{
		return true;
	}
	return false;
}

