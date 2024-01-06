#include "Pawn.h"

Pawn::Pawn(ChessBoard& chess_board, int colour)
{
	SpawnPieces(Pawns = GeneratePieces(Piece_Info::PAWN_QUANTITY, 'P', Piece_Info::PAWN, colour), chess_board);
}

void Pawn::SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board)
{
	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces[i].GetColour() == Piece_Info::BLACK)
		{
			chess_board.UpdateBoard(i * Piece_Info::SQUARES + Piece_Info::CENTER, Piece_Info::B_SECOND_ROW, pieces[i].GetSymbol());
			pieces[i].SetX(i * Piece_Info::SQUARES + Piece_Info::CENTER);
			pieces[i].SetY(Piece_Info::B_SECOND_ROW);
		}
		else 
		{
			chess_board.UpdateBoard(i * Piece_Info::SQUARES + Piece_Info::CENTER, Piece_Info::W_SECOND_ROW, pieces[i].GetSymbol());
			pieces[i].SetX(i * Piece_Info::SQUARES + Piece_Info::CENTER);
			pieces[i].SetY(Piece_Info::W_SECOND_ROW);
		}
	}
}

void Pawn::MovePiece(std::vector<ChessPieces>& piece, ChessBoard& chess_board, int index)
{
	piece[index].AddY(8);
	UpdatePiece(piece[index], chess_board, 8);
}
