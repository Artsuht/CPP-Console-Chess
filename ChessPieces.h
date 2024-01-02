#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include "ChessBoard.h"

namespace Piece_Info
{
  enum Piece_Type
 {
	PAWN,
	BISHOP,
	KNIGHT,
	ROOK,
	QUEEN,
	KING
 };

  enum Piece_Colour
 {
	BLACK,
	WHITE
 };

 enum Piece_Quantity
 {
	PAWN_QUANTITY = 8,
	BISHOPS_QUANTITY = 2,
	KNIGHTS_QUANTITY = 2,
	ROOKS_QUANTITY = 2,
	QUEEN_QUANTITY = 1,
	KING_QUANTITY = 1
 };

   //Black
   static constexpr int B_FIRST_ROW = 4;
   static constexpr int B_SECOND_ROW = 12;

   //White
   static constexpr int W_FIRST_ROW = 61;
   static constexpr int W_SECOND_ROW = 53;

   //Distances
   static constexpr int CENTER = 4;
   static constexpr int SQUARES = 8;

   //Distance to Target Square
   static constexpr int BISHOP_DIST = 2;
   static constexpr int QUEEN_DIST = 3;
   static constexpr int KING_DIST = 4;
};


class ChessPieces
{
public:
	  ChessPieces(ChessBoard& chess_board, int quantity, char p_symbol, int type, int colour);
	  ChessPieces(char p_symbol, int type, int colour) : piece_symbol(p_symbol), piece_type(type), piece_colour(colour){} //For duplicates

	  std::vector<ChessPieces>& GeneratePieces(int quantity, char symbol, int type, int colour);
	  void SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board);
	  
	  void MovePiece(ChessPieces& piece, ChessBoard& chess_board, int f_x, int f_y);
	  bool MoveLegal(int p_x, int p_y);
	  bool SquareIsEmpty(ChessPieces& piece, ChessBoard& chess_board, int p_x, int p_y);

  private:
	  int piece_x{};
	  int piece_y{};

	  int occupied_sqaured;

	  int piece_type{};
	  int piece_colour{};
	  
	  char piece_symbol; //Symbol for piece
	  std::vector<ChessPieces>piece_duplicates;
};

#endif //CHESSPIECES_H