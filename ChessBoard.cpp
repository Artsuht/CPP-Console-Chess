#include "ChessBoard.h"

void ChessBoard::InitBoard()
{
	for (int columns = 0; columns < length * width; columns++)
	{
		for (int rows = 0; rows < length * width; rows++)
		{
			chess_board[columns][rows] = ".";

			chess_board[0][rows] = "#"; //Top Border
			chess_board[columns][0] = "#"; //Left Border

			chess_board[length * width - 1][rows] = "#"; //Bottom Border
			chess_board[columns][length * width - 1] = "#"; //Right Border

			for (int i = 0; i < length * width; i++) //Just to run through multiplications
			{
				if (rows == i * 5 && rows < length * width - 1) //Create a section every five tiles
					chess_board[columns][rows] = "#";
				if (columns == i * 5 && columns < length * width - 1) //Cross every five tiles
					chess_board[columns][rows] = "#";
			}
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
		 std::cout << std::endl;
	}
}