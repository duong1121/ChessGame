#include"Tinh.h"
#include<math.h>
bool Bishop::CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]) {
	
	if (abs(DesCol - Pos.Col) == abs(DesRow - Pos.Row)) {

		// check doan duong khong co chuong ngai vat
		int MoveRow = (DesRow - Pos.Row > 0) ? 1 : -1;
		int MoveCol = (DesCol - Pos.Col > 0) ? 1 : -1;

		int CheckRow = Pos.Row;
		int CheckCol = Pos.Col;
		while (CheckRow != DesRow) {
			CheckCol += MoveCol;
			CheckRow += MoveRow;
			if (Board[CheckRow][CheckCol] != 0)
				return false;
			else
				return true;
		}
	}
	return false;
}