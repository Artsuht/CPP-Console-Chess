#include "ChessPieces.h"

ChessPieces::ChessPieces(const ChessBoard& chess_board, int quantity, std::string p_symbol, int type, int colour) : piece_symbol(p_symbol), piece_type(type), piece_colour(colour)
{
	GeneratePieces(chess_board ,quantity, p_symbol, type, colour);
}

void ChessPieces::GeneratePieces(const ChessBoard& chess_board, int quantity, std::string symbol, int type, int colour)
{
	ChessPieces new_pieces(symbol, type, colour);
	for (int duplicates = 0; duplicates < quantity; duplicates++)
	{
		piece_duplicates.push_back(new_pieces);
	}
	
	for (ChessPieces& duplicate : piece_duplicates)
	{
		SpawnPieces(duplicate, chess_board);
	}
}

void ChessPieces::SpawnPieces(const ChessPieces& piece, const ChessBoard& chess_board)
{

}
