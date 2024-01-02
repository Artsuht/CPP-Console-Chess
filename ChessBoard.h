#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <string>
#include <vector>

class ChessBoard
{
public:
	ChessBoard();
	void DrawBoard();
	void UpdateBoard(int p_x, int p_y, char c_piece);
	void InitBoard();
	bool SquareIsEmpty();
	bool GetSquare(int sq_num) { return occupied_square[sq_num]; }
	//Get
	char BoardArea(int x, int y) { return chess_board[y][x]; }
	char Border() { return '#'; }
	char  Empty() { return '.'; }
	int BoardSize() { return length * width; }
private:

	static const int length{ 8 };
	static const int width{ 8 };
	char chess_board[length * width][length * width];
	std::vector<bool>occupied_square;
};

#endif //CHESSBOARD_H

