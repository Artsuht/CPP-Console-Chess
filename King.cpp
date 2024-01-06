#include "King.h"

King::King(ChessBoard& chess_board, int colour)
{
	SpawnPieces(Kings = GeneratePieces(Piece_Info::KING_QUANTITY, 'K', Piece_Info::KING, colour), chess_board);
}

void King::SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board)
{
	for (auto& king : pieces)
	{
		if (king.GetColour() == Piece_Info::BLACK)
		{
			chess_board.UpdateBoard(Piece_Info::SQUARES * Piece_Info::KING_DIST + Piece_Info::CENTER, Piece_Info::B_FIRST_ROW, king.GetSymbol());
			king.SetX(Piece_Info::SQUARES * Piece_Info::KING_DIST + Piece_Info::CENTER);
			king.SetY(Piece_Info::B_FIRST_ROW);
		}
		else
		{
			chess_board.UpdateBoard(Piece_Info::SQUARES * Piece_Info::KING_DIST + Piece_Info::CENTER, Piece_Info::W_FIRST_ROW, king.GetSymbol());
			king.SetX(Piece_Info::SQUARES * Piece_Info::KING_DIST + Piece_Info::CENTER);
			king.SetY(Piece_Info::W_FIRST_ROW);
		}
	}

}
