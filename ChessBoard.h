#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <string>
#include <vector>

static constexpr int Square = 5;

class ChessBoard
{
public:
	ChessBoard() { InitBoard(); }
	void DrawBoard();
	void UpdateBoard(int p_x, int p_y, std::string c_piece);
	void InitBoard();
private:

	static const int length{ 6 };
	static const int width{ 6 };
	std::string chess_board[length * width][length * width];
};

#endif //CHESSBOARD_H

