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
				if (rows == i * 5) //Create a section every five tiles
					chess_board[columns][rows] = "#";
				if (columns == i * 5 && columns) //Cross every five tiles
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

void ChessBoard::UpdateBoard(int p_x, int p_y, std::string c_piece) //Update this function to as to be able to put pieces into specific squares.
{
	chess_board[p_x][p_y] = c_piece;
}
