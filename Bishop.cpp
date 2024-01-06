#include "Bishop.h"

Bishop::Bishop(ChessBoard& chess_board, int colour)
{
	SpawnPieces(Bishops = GeneratePieces(Piece_Info::BISHOPS_QUANTITY, 'B', Piece_Info::BISHOP, colour), chess_board);
}

void Bishop::SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board)
{
	int b_dist = Piece_Info::BISHOP_DIST;

	for (auto& bishop : pieces)
	{
		if (bishop.GetColour() == Piece_Info::BLACK)
		{
			chess_board.UpdateBoard(Piece_Info::SQUARES * b_dist + Piece_Info::CENTER, Piece_Info::B_FIRST_ROW, bishop.GetSymbol());
			bishop.SetX(Piece_Info::SQUARES * b_dist + Piece_Info::CENTER);
			bishop.SetY(Piece_Info::B_FIRST_ROW);
            
			b_dist = Piece_Info::BISHOP2_DIST;
		}
		else
		{
			chess_board.UpdateBoard(Piece_Info::SQUARES * b_dist + Piece_Info::CENTER, Piece_Info::W_FIRST_ROW, bishop.GetSymbol());
			bishop.SetX(Piece_Info::SQUARES * b_dist + Piece_Info::CENTER);
			bishop.SetY(Piece_Info::W_FIRST_ROW);

			b_dist = Piece_Info::BISHOP2_DIST;
		}
	}
}

void Bishop::MovePiece(std::vector<ChessPieces> &piece, ChessBoard& chess_board, int index, int x, int y)
{
			piece[index].AddX(x * Piece_Info::SQUARES);
			piece[index].AddY(y * Piece_Info::SQUARES);
			UpdatePiece(piece[index], chess_board, x);

			if (piece[index].GetX() > chess_board.Size() || piece[index].GetY() > chess_board.Size())
			{
				piece[index].AddX(-x * Piece_Info::SQUARES);
				piece[index].AddY(-y * Piece_Info::SQUARES);
				UpdatePiece(piece[index], chess_board, x);
			}
}
