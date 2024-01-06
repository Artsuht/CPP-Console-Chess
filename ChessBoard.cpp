#include "ChessBoard.h"

ChessBoard::ChessBoard() 
{
	InitBoard();
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

			for (int multiplier = 0; multiplier < length; multiplier++) //Just to run through multiples of 8
			{
				if (rows == multiplier * width - 1) //Cross every eight tiles
					chess_board[columns][rows] = '#';
				if (columns == multiplier * length) //Create a section every eight tiles
					chess_board[columns][rows] = '#';
			}
		}
	}
}

void ChessBoard::SquareIsOccupied(int row)
{	
	for (int i = 0; i < length + 1; i++)
	{
		if (BoardArea(i * width - 4, row) != Empty() && i * 8 - 4 > 0 && i * 8 - 4 < 61)
		{
			UpdateBoard(i * 8 - 4, row, 'O');
			occupied_square.push_back(true);
		}
		else
		{
			occupied_square.push_back(false);
		}
	}
}

bool ChessBoard::CheckSquare(int square)
{
	int row = 4;
	for (int i = 0; i < length; i++)
	{
		
		SquareIsOccupied(row);
		row += 8;
	}

	return occupied_square[square];
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

void ChessBoard::UpdateBoard(int p_x, int p_y, char c_piece) //Update this function to as to be able to put pieces into specific squares.
{
	chess_board[p_y][p_x] = c_piece;
}
