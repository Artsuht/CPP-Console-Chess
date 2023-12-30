#include "ChessPieces.h"

ChessPieces::ChessPieces(ChessBoard& chess_board, int quantity, std::string p_symbol, int type, int colour) : piece_symbol(p_symbol), piece_type(type), piece_colour(colour)
{
	GeneratePieces(chess_board ,quantity, p_symbol, type, colour);
}

void ChessPieces::GeneratePieces(ChessBoard& chess_board, int quantity, std::string symbol, int type, int colour)
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

void ChessPieces::SpawnPieces(ChessPieces& piece, ChessBoard& chess_board)
{

}

void ChessPieces::MovePiece(ChessPieces& piece, int p_x, int p_y)
{
}
