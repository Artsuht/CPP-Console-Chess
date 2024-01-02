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

			for (int multiplier = 1; multiplier < length; multiplier++) //Just to run through multiples of 8
			{
				if (rows == multiplier * width - 1) //Cross every eight tiles
					chess_board[columns][rows] = '#';
				if (columns == multiplier * length) //Create a section every eight tiles
					chess_board[columns][rows] = '#';
			}
		}
	}
}

bool ChessBoard::SquareIsEmpty()
{
	char f = 'S';

	int seeker_x{0};
	int seeker_y{1};
	bool move_next = false;

	int width = 8;
	int length = 8;



	DrawBoard();

	std::cout << "X: " << seeker_x << " Y: " << seeker_y << std::endl;
	return false;
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
