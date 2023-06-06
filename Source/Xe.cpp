#include"Xe.h"

bool Rook::CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]) {
	if (Pos.Row == DesRow)
	{
		// make sure that all invervening squares are empty I
		int colOffset = (DesRow - Pos.Col > 0) ? 1 : -1;
		for (int checkCol = Pos.Col + colOffset;
			checkCol != DesCol;
			checkCol += colOffset)
		{
			if (Board[Pos.Row][checkCol] != 0)
				return false;
		}
		return true;
	}
	else if (DesCol == Pos.Col)
	{
		// make sure that all invervening squares are empty II
		int rowOffset = (DesRow - Pos.Row > 0) ? 1 : -1;
		for (int checkRow = Pos.Row + rowOffset; checkRow != DesRow; checkRow += rowOffset)
		{
			if (Board[checkRow][Pos.Col] != 0)
				return false;
		}
		return true;
	}
	return false;
}