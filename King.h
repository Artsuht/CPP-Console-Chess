#ifndef KING_H
#define KING_H

#include "ChessPieces.h"

class King : public ChessPieces
{
public:
	King(ChessBoard& chess_board, int colour);
	void SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board);
	void MovePiece(std::vector<ChessPieces>& piece, ChessBoard& chess_board, int index, bool diagonal, int left_right, int up_down);
	std::vector<ChessPieces>& GetPieces() override { return Kings; }
private:
	std::vector<ChessPieces>Kings;
};

#endif //KING_H

