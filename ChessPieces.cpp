#include "ChessPieces.h"

using namespace Piece_Info;

ChessPieces::ChessPieces(ChessBoard& chess_board, int quantity, char p_symbol, int type, int colour) 
:   piece_symbol(p_symbol),
	piece_type(type), 
	piece_colour(colour)
{
	SpawnPieces(GeneratePieces(quantity, p_symbol, type, colour), chess_board);
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

void ChessPieces::UpdatePiece(ChessPieces& piece, ChessBoard& chess_board, int num_trav)
{
	switch (piece.piece_type)
	{
	case BISHOP:
		chess_board.UpdateBoard(piece.GetX() - (num_trav * SQUARES), piece.GetY() - (num_trav * SQUARES), chess_board.Empty());
		chess_board.UpdateBoard(piece.GetX(), piece.GetY(), piece.GetSymbol());
		break;
	case PAWN:
		chess_board.UpdateBoard(piece.GetX(), piece.GetY() - 8, chess_board.Empty());
		chess_board.UpdateBoard(piece.GetX(), piece.GetY(), piece.GetSymbol());
		break;
	}
}

