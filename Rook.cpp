#include "Rook.h"

Rook::Rook(ChessBoard& chess_board, int colour)
{
	SpawnPieces(Rooks = GeneratePieces(Piece_Info::ROOKS_QUANTITY, 'R', Piece_Info::ROOK, colour), chess_board);
}

void Rook::SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board)
{
	int sq = Piece_Info::SQUARES;
	for(auto& rook : pieces)
	{
		if (rook.GetColour() == Piece_Info::BLACK)
		{
			chess_board.UpdateBoard(sq - Piece_Info::CENTER, Piece_Info::B_FIRST_ROW, rook.GetSymbol());
			rook.SetX(sq - Piece_Info::CENTER);
			rook.SetY(Piece_Info::B_FIRST_ROW);

			sq *= Piece_Info::ROOK2_DIST;
		}
		else
		{
			chess_board.UpdateBoard(sq - Piece_Info::CENTER, Piece_Info::W_FIRST_ROW, rook.GetSymbol());
			rook.SetX(sq - Piece_Info::CENTER);
			rook.SetY(Piece_Info::W_FIRST_ROW);
			sq *= Piece_Info::ROOK2_DIST;
		}
	}
}
