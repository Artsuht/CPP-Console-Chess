#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPieces.h"

class Queen : public ChessPieces
{
  public:
	  Queen(ChessBoard& chess_board, int colour);
	  void SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board);
	  void MovePiece(std::vector<ChessPieces>& piece, ChessBoard& chess_board, int index, int move_dist, bool diagonal, int left_right, int up_down);
	  std::vector<ChessPieces>& GetPieces() override { return Queens; }
  private:
	  std::vector<ChessPieces> Queens;
};

#endif //QUEEN_H

