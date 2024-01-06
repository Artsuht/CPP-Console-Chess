#ifndef KING_H
#define KING_H

#include "ChessPieces.h"

class King : public ChessPieces
{
public:
	King(ChessBoard& chess_board, int colour);
	void SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board);
	std::vector<ChessPieces>& GetPieces() { return Kings; }
private:

	std::vector<ChessPieces>Kings;
};

#endif //KING_H

