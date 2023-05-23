#include"Hau.h"

bool Queen::CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]) {

	if (Pos.Col == DesCol) {
		int CheckRow = Pos.Row;
		int MoveRow = (DesRow - Pos.Row > 0) ? 1 : -1;
		for (CheckRow += MoveRow; CheckRow != DesRow; ) {
			if (Board[CheckRow][Pos.Col] != 0)
				return false;
			else
				return true;
		}
	}


	else if (Pos.Row == DesRow) {
		int CheckCol = Pos.Col;
		int MoveCol = (DesCol - Pos.Col > 0) ? 1 : -1;
		for (CheckCol += MoveCol; CheckCol != DesCol; ) {
			if (Board[Pos.Row][CheckCol] != 0)
				return false;
			else
				return true;
		}
	}

	else if (abs(DesCol - Pos.Col) == abs(DesRow - Pos.Row)) {

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