#include "Knight.h"

Knight::Knight(ChessBoard& chess_board, int colour)
{
	SpawnPieces(Knights = GeneratePieces(Piece_Info::KNIGHTS_QUANTITY, 'k', Piece_Info::KNIGHT, colour), chess_board);
}

void Knight::SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board)
{
	int sq = Piece_Info::SQUARES;
	for (auto& knight : pieces)
	{
		if (knight.GetColour() == Piece_Info::BLACK)
		{
			chess_board.UpdateBoard(sq + Piece_Info::CENTER, Piece_Info::B_FIRST_ROW, knight.GetSymbol());
			knight.SetX(sq + Piece_Info::CENTER);
			knight.SetY(Piece_Info::B_FIRST_ROW);

			sq *= Piece_Info::KNIGHT2_DIST;
		}
		else
		{
			chess_board.UpdateBoard(sq + Piece_Info::CENTER, Piece_Info::W_FIRST_ROW, knight.GetSymbol());
			knight.SetX(sq + Piece_Info::CENTER);
			knight.SetY(Piece_Info::W_FIRST_ROW);

			sq *= Piece_Info::KNIGHT2_DIST;
		}
	}
}
