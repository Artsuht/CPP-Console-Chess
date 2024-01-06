#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPieces.h"

class Knight : public ChessPieces
{
public:
	Knight(ChessBoard& chess_board, int colour);
	void SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board);
	void MovePiece(std::vector<ChessPieces>& piece, ChessBoard& chess_board, int index, int left_right, int up_down);
	std::vector<ChessPieces>& GetPieces() override { return Knights; }

private:
	std::vector<ChessPieces>Knights;
};

#endif //KNIGHT_H

