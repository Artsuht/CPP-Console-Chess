#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <string>
#include <vector>

namespace Rank
{
	static constexpr int A = 4;
	static constexpr int B = 12;
	static constexpr int C = 20;

	static constexpr int D = 28;
	static constexpr int E = 36;
	static constexpr int F = 44;

	static constexpr int G = 56;
	static constexpr int H = 60;
};

class ChessBoard
{
public:
	ChessBoard();
	void DrawBoard();
	void UpdateBoard(int p_x, int p_y, char c_piece);
	void InitBoard();

	std::vector<bool>friendly_squares;
	std::vector<bool>occupied_squares;

	//Get
	int Size() { return length * width; }
	char BoardArea(int x, int y) { return chess_board[y][x]; }
	char Border() { return '#'; }
	char  Empty() { return '.'; }

private:
	static const int length{ 8 };
	static const int width{ 8 };
	char chess_board[length * width][length * width];
};

#endif //CHESSBOARD_H

