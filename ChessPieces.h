#ifndef CHESSPIECES_H
#define CHESSPIECES_H

#include "ChessBoard.h"

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

class ChessPieces
{
public:
	  ChessPieces(ChessBoard& chess_board, int quantity, std::string p_symbol, int type, int colour);
	  ChessPieces(std::string p_symbol, int type, int colour) : piece_symbol(p_symbol), piece_type(type), piece_colour(colour){} //For duplicates

	  void GeneratePieces(ChessBoard& chess_board, int quantity, std::string symbol, int type, int colour);
	  void SpawnPieces(ChessPieces& piece, ChessBoard& chess_board);
	  
	  void MovePiece(ChessPieces& piece, int p_x, int p_y);
	  bool MoveLegal(int p_x, int p_y);

  private:

	  int piece_x{};
	  int piece_y{};

	  int piece_type{};
	  int piece_colour{};
	  
	  std::string piece_symbol; //Symbol for piece
	  std::vector<ChessPieces>piece_duplicates;
};

#endif //CHESSPIECES_H