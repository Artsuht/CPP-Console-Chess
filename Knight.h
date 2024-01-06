#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPieces.h"

class Knight : public ChessPieces
{
public:
	Knight(ChessBoard& chess_board, int colour);
	void SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board);
	std::vector<ChessPieces>& GetPieces() { return Knights; }

private:
	std::vector<ChessPieces>Knights;
};

#endif //KNIGHT_H

