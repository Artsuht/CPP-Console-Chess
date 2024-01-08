#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPieces.h"

class Bishop : public ChessPieces
{
  public:
	  Bishop(ChessBoard& chess_board, int colour);
	  void SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board);
	  std::vector<ChessPieces>& GetPieces() override { return Bishops; }
	  void MovePiece(std::vector<ChessPieces>& piece, ChessBoard& chess_board, int index, int xy, int left_right, int up_down);

  private:
	  std::vector<ChessPieces>Bishops;
};

#endif //BISHOP_H

