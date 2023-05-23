#include"Vua.h"

bool King::CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]) {
	if (DesCol - Pos.Col >= -1 && DesCol - Pos.Col <= 1 && DesRow - Pos.Row >= -1 && DesRow - Pos.Row <= 1)
		return true;
	return false;
}

