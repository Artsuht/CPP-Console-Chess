#ifndef ROOK_H
#define ROOK_H

#include "ChessPieces.h"

class Rook : public ChessPieces
{
public:
	Rook(ChessBoard& chess_board, int colour);
	void SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board);
	void MovePiece(std::vector<ChessPieces>& piece, ChessBoard& chess_board, int index, int xy, int left_right, int up);
	bool movepiece;
	std::vector<ChessPieces>& GetPieces() override { return Rooks; }
private:
	std::vector<ChessPieces>Rooks;
};

#endif //ROOK_H

