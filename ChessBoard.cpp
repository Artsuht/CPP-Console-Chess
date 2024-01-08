#include "ChessBoard.h"

ChessBoard::ChessBoard() 
{
	InitBoard();

	for (int sq = 0; sq < length * width; sq++)
		friendly_squares.push_back(false);
}

void ChessBoard::InitBoard()
{	
	for (int columns = 0; columns < length * width; columns++)
	{
		for (int rows = 0; rows < length * width; rows++)
		{
			chess_board[columns][rows] = '.';

			chess_board[0][rows] = '#'; //Top Border
			chess_board[columns][0] = '#'; //Left Border

			chess_board[length * width - 1][rows] = '#'; //Bottom Border
			chess_board[columns][length * width - 1] = '#'; //Right Border

		   if (rows % 8 == 0 || columns % 8 == 0)
		   chess_board[columns][rows] = '#';

		}
	}
}

void ChessBoard::DrawBoard()
{
	for (int columns = 0; columns < length * width; columns++)
	{
		for (int rows = 0; rows < length * width; rows++)
		{
			std::cout << chess_board[columns][rows];
		}
		std::cout << "\n";
	}
}

void ChessBoard::UpdateBoard(int p_x, int p_y, char c_piece) 
{
	chess_board[p_y][p_x] = c_piece;
}
