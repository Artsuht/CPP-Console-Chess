#ifndef PAWN_H
#define PAWN_H

#include "ChessPieces.h"

class Pawn : public ChessPieces
{
public:
	Pawn(ChessBoard& chess_board, int colour);
	void SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board);
	std::vector<ChessPieces>& GetPieces() override { return Pawns; }
	void MovePiece(std::vector<ChessPieces>& piece, ChessBoard& chess_board, int index, int x);
private:
	std::vector<ChessPieces>Pawns;
};

#endif //PAWN_H

