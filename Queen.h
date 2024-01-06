#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPieces.h"

class Queen : public ChessPieces
{
  public:
	  Queen(ChessBoard& chess_board, int colour);
	  void SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board);
	  std::vector<ChessPieces>& GetPieces() { return Queens; }
  private:
	  std::vector<ChessPieces> Queens;
};

#endif //QUEEN_H

