#include"Tinh.h"
#include<math.h>
bool Bishop::CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]) {
	
	if ((DesCol - Pos.Col == DesRow - Pos.Row) || (DesCol - Pos.Col == Pos.Row - DesRow))
	{
		// make sure that all invervening squares are empty
		int rowOffset = (DesRow - Pos.Row > 0) ? 1 : -1;
		int colOffset = (DesCol - Pos.Col > 0) ? 1 : -1;
		int checkRow;
		int checkCol;
		for (checkRow = Pos.Row + rowOffset, checkCol = Pos.Col + colOffset;
			checkRow != DesRow;
			checkRow += rowOffset, checkCol += colOffset)
		{
			if (Board[checkRow][checkCol] != 0)
				return false;
		}
		return true;
	}
	return false;
}