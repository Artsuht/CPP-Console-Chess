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
    static constexpr int MOVE_MIN = 1; //King, Pawns
	static constexpr int MOVE_MAX = 8; //Rooks, Bishops, Queen
	static constexpr int HORIZ_MAX = 2;


   //Black
   static constexpr int B_FIRST_ROW = 4;
   static constexpr int B_SECOND_ROW = 12;

   //White
   static constexpr int W_FIRST_ROW = 60;
   static constexpr int W_SECOND_ROW = 52;

   //Distances
   static constexpr int CENTER = 4; //Offset, could just multiply by 4 instead of 8 and subtracting.
   static constexpr int SQUARES = 8; //The distance between each piece.

   //Multiplier to Get Target Square
   static constexpr int BISHOP_DIST =2; 
   static constexpr int BISHOP2_DIST = 5;

   static constexpr int QUEEN_DIST = 3;
   static constexpr int KING_DIST = 4;

   static constexpr int ROOK2_DIST = 8;
   static constexpr int KNIGHT2_DIST = 6;
};


class ChessPieces
{
public:
	  ChessPieces(ChessBoard& chess_board, int quantity, char p_symbol, int type, int colour);
	  ChessPieces(char p_symbol, int type, int colour) : piece_symbol(p_symbol), piece_type(type), piece_colour(colour){} //For duplicates
	  ChessPieces(){}

	  std::vector<ChessPieces>& GeneratePieces(int quantity, char symbol, int type, int colour);
	  virtual std::vector<ChessPieces>& GetPieces() { return piece_duplicates; }
	  virtual void SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board){}

	  void UpdatePiece(ChessPieces& piece, ChessBoard& chess_board, int num_trav);

	  void PrintXY(std::vector<ChessPieces>& pieces) { for (auto& i : pieces) { std::cout << "X: " << i.GetX() << " Y: " << i.GetY() << std::endl; } }
	  //Set
	  void AddY(int y) { piece_y += y; }
	  void AddX(int x) { piece_x += x; }
	  void SetX(int x) { piece_x = x; }
	  void SetY(int y) { piece_y = y; }
	  //Get
	  int GetColour() { return piece_colour; }
	  int GetX() { return piece_x; }
	  int GetY() { return piece_y; }
	  char GetSymbol() { return piece_symbol; }
  private:
	  int piece_x{};
	  int piece_y{};

	  int piece_type{};
	  int piece_colour{};
	  
	  char piece_symbol{};
	  std::vector<ChessPieces>piece_duplicates;
};

#endif //CHESSPIECES_H