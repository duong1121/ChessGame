#include"Tot.h"

using namespace std;
bool Pawn::CheckNewPos(int DesCol, int DesRow, Pieces* Board[8][8]) {
	
	//Xet Destination la o trong => di thang
	if (Board[DesRow][DesCol] == 0)
	{

		if (Pos.Col == DesCol) 
		{
			if (getPieceColor() == 0)
			{

				if (DesRow == Pos.Row + 1)
					return true;

				if (DesRow == Pos.Row + 2 && this->Pos.Row == 1)
					return true;
			}
			else
			{
				if (DesRow == Pos.Row - 1)
					return true;

				if (DesRow == Pos.Row - 2 && this->Pos.Row == 6)
					return true;
			}
		}
	}
	
	//Xet kieu di cheo
	else
	{
		// dest holds piece of opposite color
		if ((Pos.Col == DesCol + 1) || (Pos.Col == DesCol - 1))
		{
			if (getPieceColor() == 0)
			{
				if (DesRow == Pos.Row  + 1)
					return true;
			}
			else
			{
				if (DesRow == Pos.Row  - 1)
					return true;
			}
		}
	}
	return false;
}