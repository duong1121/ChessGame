#include"Board.h"

Board::Board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = 0;

		}
	}

	// hang tot
	for (int j = 0; j < 8; j++) {
		board[1][j] = new Pawn(0);
		board[1][j]->Pos.Row = 1;
		board[1][j]->Pos.Col = j;
	}

	for (int j = 0; j < 8; j++) {
		board[6][j] = new Pawn(1);
		board[6][j]->Pos.Row = 6;
		board[6][j]->Pos.Col = j;
	}

	board[0][0] = new Rook(0);
	board[0][0]->Pos.Row = 0;
	board[0][0]->Pos.Col = 0;

	board[0][1] = new Bishop(0);
	board[0][1]->Pos.Row = 0;
	board[0][1]->Pos.Col = 1;

	board[0][2] = new Knight(0);
	board[0][2]->Pos.Row = 0;
	board[0][2]->Pos.Col = 2;

	board[0][3] = new Queen(0);
	board[0][3]->Pos.Row = 0;
	board[0][3]->Pos.Col = 3;

	board[0][4] = new King(0);
	board[0][4]->Pos.Row = 0;
	board[0][4]->Pos.Col = 4;

	board[0][5] = new Knight(0);
	board[0][5]->Pos.Row = 0;
	board[0][5]->Pos.Col = 5;

	board[0][6] = new Bishop(0);
	board[0][6]->Pos.Row = 0;
	board[0][6]->Pos.Col = 6;

	board[0][7] = new Rook(0);
	board[0][7]->Pos.Row = 0;
	board[0][7]->Pos.Col = 7;

	//"============================="

	board[7][0] = new Rook(1);
	board[7][0]->Pos.Row = 7;
	board[7][0]->Pos.Col = 0;

	board[7][1] = new Bishop(1);
	board[7][1]->Pos.Row = 7;
	board[7][1]->Pos.Col = 1;

	board[7][2] = new Knight(1);
	board[7][2]->Pos.Row = 7;
	board[7][2]->Pos.Col = 2;

	board[7][3] = new Queen(1);
	board[7][3]->Pos.Row = 7;
	board[7][3]->Pos.Col = 3;

	board[7][4] = new King(1);
	board[7][4]->Pos.Row = 7;
	board[7][4]->Pos.Col = 4;

	board[7][5] = new Knight(1);
	board[7][5]->Pos.Row = 7;
	board[7][5]->Pos.Col = 5;

	board[7][6] = new Bishop(1);
	board[7][6]->Pos.Row = 7;
	board[7][6]->Pos.Col = 6;

	board[7][7] = new Rook(1);
	board[7][7]->Pos.Row = 7;
	board[7][7]->Pos.Col = 7;
}

Board::~Board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete board[i][j];
			board[i][j] = 0;
		}
	}
}

void Board::printBoard() {
	const int squareHeight = 3;
	const int squareWidth = 4;

	for (int row = 0; row < 8 * squareHeight; ++row)
	{
		int squareRow = row / squareHeight;
		// print side border with numbering
		if (row % 3 == 1)
		{
			cout << '-' << (char)('1' + 7 - squareRow) << '-';
		}
		else
		{
			cout << "---";
		}
		// print the chess board
		for (int col = 0; col < 8 * squareWidth; ++col)
		{
			int squareCol = col / squareWidth;
			if (((row % 3) == 1) && ((col % 4) == 1 || (col % 4) == 2) && board[7 - squareRow][squareCol] != 0)
			{
				if ((col % 4) == 1)
				{
					cout << board[7 - squareRow][squareCol]->getPieceColor();
				}
				else
				{
					cout << board[7 - squareRow][squareCol]->getPiece();
				}
			}
			else
			{
				if ((squareRow + squareCol) % 2 == 1)
				{
					cout << ' ';
				}
				else
				{
					cout << '*';
				}
			}
		}
		cout << endl;
	}
	// print the bottom border with numbers
	for (int row = 0; row < squareHeight; ++row)
	{
		if (row % 3 == 1)
		{
			cout << "---";
			for (int col = 0; col < 8 * squareWidth; ++col)
			{
				int squareCol = col / squareWidth;
				if ((col % 4) == 1)
				{
					cout << (squareCol + 1);
				}
				else
				{
					cout << '-';
				}
			}
			cout << endl;
		}
		else
		{
			for (int col = 1; col < 9 * squareWidth; ++col)
			{
				cout << '-';
			}
			cout << endl;
		}
	}
}

bool Board::isInCheck(int color) {
	int kingRow = 0;
	int kingCol = 0;
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			if (board[row][col] != 0)
			{
				if (board[row][col]->getPieceColor() == color)
				{
					if (board[row][col]->getPiece() == 'V')
					{
						kingRow = row;
						kingCol = col;
					}
				}
			}
		}
	}

	// run through the opponent's pieces and see if any can take the king
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			if (board[row][col] != 0)
			{
				if (board[row][col]->getPieceColor() != color)
				{
					if (board[row][col]->isLegalMove(kingCol, kingRow, board))
					{
						cout << "CheckMate" << endl;
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool Board::canMove(int color) {
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			if (board[row][col] != 0)
			{

				// if it is a piece of the current player, see if it has a legal move
				if (board[row][col]->getPieceColor() == color)
				{


					for (int moveRow = 0; moveRow < 8; ++moveRow)
					{
						for (int moveCol = 0; moveCol < 8; ++moveCol)
						{
							if (board[row][col]->isLegalMove(moveCol, moveRow, board))
							{
								// make move and check whether king is in check
								Pieces* temp = board[moveRow][moveCol];
								board[moveRow][moveCol] = board[row][col];
								board[row][col] = 0;
								bool boolCanMove = !isInCheck(color);

								// undo the move
								board[row][col] = board[moveRow][moveCol];
								board[moveRow][moveCol] = temp;

								if (boolCanMove)
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}