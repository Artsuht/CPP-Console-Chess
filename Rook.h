#ifndef ROOK_H
#define ROOK_H

#include "ChessPieces.h"

class Rook : public ChessPieces
{
public:
	Rook(ChessBoard& chess_board, int colour);
	void SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board);
	std::vector<ChessPieces>& GetPieces() { return Rooks; }
private:
	std::vector<ChessPieces>Rooks;
};

#endif //ROOK_H

