#include "ChessPieces.h"

using namespace Piece_Info;

ChessPieces::ChessPieces(ChessBoard& chess_board, int quantity, char p_symbol, int type, int colour)
	: piece_symbol(p_symbol),
	piece_type(type),
	piece_colour(colour)
{
}

std::vector<ChessPieces>& ChessPieces::GeneratePieces(int quantity, char symbol, int type, int colour) 
{
	ChessPieces new_pieces(symbol, type, colour);
	for (int duplicates = 0; duplicates < quantity; duplicates++)
	{
		piece_duplicates.push_back(new_pieces);
	}

	return piece_duplicates;
}

bool ChessPieces::InBounds(ChessBoard& chess_board, int f_x, int f_y)
{
	if (f_x < chess_board.Size() && f_x > 0 && f_y < chess_board.Size() && f_y > 0)
		return true;
	
	return false;
}
