#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include "ChessBoard.h"

namespace Piece_Info
{
  enum piece_type
 {
	PAWN,
	BISHOP,
	KNIGHT,
	ROOK,
	QUEEN,
	KING
 };

  enum piece_colour
 {
	BLACK,
	WHITE
 };

 enum piece_quantity
 {
	PAWN_QUANTITY = 8,
	BISHOPS_QUANTITY = 2,
	KNIGHTS_QUANTITY = 2,
	ROOKS_QUANTITY = 2,
	QUEEN_QUANTITY = 1,
	KING_QUANTITY = 1
 };
   //Movement
    static constexpr int LEFT_OR_UP = 1;
	static constexpr int RIGHT_OR_DOWN = 2; 
	static constexpr int FAR_LEFT = 3;
	static constexpr int FAR_RIGHT = 4;


   //Black
   static constexpr int B_FIRST_ROW = 4;
   static constexpr int B_SECOND_ROW = 12;

   //White
   static constexpr int W_FIRST_ROW = 60;
   static constexpr int W_SECOND_ROW = 52;

   //Distances
   static constexpr int CENTER = 4; 
   static constexpr int SQUARES = 8; 

   //Multiplier to Get Target Square
   static constexpr int BISHOP_DIST = 2; 
   static constexpr int BISHOP2_DIST = 5;

   static constexpr int QUEEN_DIST = 3;
   static constexpr int KING_DIST = 4;

   static constexpr int ROOK2_DIST = 8;
   static constexpr int KNIGHT2_DIST = 6;
};


class ChessPieces : public ChessBoard
{
public:
	  ChessPieces(ChessBoard& chess_board, int quantity, char p_symbol, int type, int colour);
	  ChessPieces(char p_symbol, int type, int colour) : piece_symbol(p_symbol), piece_type(type), piece_colour(colour){} //For duplicates
	  ChessPieces(){}

	  std::vector<ChessPieces>& GeneratePieces(int quantity, char symbol, int type, int colour);
	  virtual std::vector<ChessPieces>& GetPieces() { return piece_duplicates; }
	  bool InBounds(ChessBoard& chess_board, int f_x, int f_y);
	
	  int piece_x{};
	  int piece_y{};
	  int on_square{};

	  int piece_type{};
	  int piece_colour{};
	  
	  char piece_symbol{};
	  bool double_move = true;
	  bool captured = false;

private:

	  std::vector<ChessPieces>piece_duplicates;
};

#endif //CHESSPIECES_H