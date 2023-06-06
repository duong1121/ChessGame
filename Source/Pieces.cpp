#include"Pieces.h"

int Pieces::getPieceColor()
{
    return Color;
}

/*bool Pieces::isWhitePiece()
{
    return getPieceColor() == Pieces::White ? true : false;
}

bool Pieces::isBlackPiece()
{
    return getPieceColor() == Pieces::Black ? true : false;
}*/

bool Pieces::isLegalMove(int DesCol, int DesRow, Pieces* Board[8][8])
{

    if ((Board[DesRow][DesCol] == 0))
    {
        return CheckNewPos(DesCol, DesRow, Board);
    }
    else if (Board[DesRow][DesCol]->getPieceColor() != Color)
    {
        
        return CheckNewPos(DesCol, DesRow, Board);
    }
    return false;
}