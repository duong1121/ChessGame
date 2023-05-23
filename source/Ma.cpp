#include"Ma.h"

bool Knight::CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]) {
	if ((Pos.Col == DesCol + 1) || (Pos.Col == DesCol - 1))
	{
		if ((Pos.Row == DesRow + 2) || (Pos.Row == DesRow - 2))
			return true;
	}
	if ((Pos.Col == DesCol + 2) || (Pos.Col == DesCol - 2))
	{
		if ((Pos.Row == DesRow + 1) || (Pos.Row == DesRow - 1))
			return true;
	}
	return false;
}