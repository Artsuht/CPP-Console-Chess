#include "Queen.h"

Queen::Queen(ChessBoard& chess_board, int colour)
{
	SpawnPieces(Queens = GeneratePieces(Piece_Info::QUEEN_QUANTITY, 'Q', Piece_Info::QUEEN, colour), chess_board);
}

void Queen::SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board)
{
	for (auto& queen : pieces)
	{
		if (queen.GetColour() == Piece_Info::BLACK)
		{
			chess_board.UpdateBoard(Piece_Info::SQUARES * Piece_Info::QUEEN_DIST + Piece_Info::CENTER, Piece_Info::B_FIRST_ROW, queen.GetSymbol());
			queen.SetX(Piece_Info::SQUARES * Piece_Info::QUEEN_DIST);
			queen.SetY(Piece_Info::B_FIRST_ROW);
		}
		else
		{
			chess_board.UpdateBoard(Piece_Info::SQUARES * Piece_Info::QUEEN_DIST + Piece_Info::CENTER, Piece_Info::W_FIRST_ROW, queen.GetSymbol());
			queen.SetX(Piece_Info::SQUARES * Piece_Info::QUEEN_DIST + Piece_Info::CENTER);
			queen.SetY(Piece_Info::W_FIRST_ROW);
		}
	}
}
