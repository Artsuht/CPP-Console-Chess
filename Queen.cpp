#include "Queen.h"

Queen::Queen(ChessBoard& chess_board, int colour)
{
	SpawnPieces(Queens = GeneratePieces(Piece_Info::QUEEN_QUANTITY, 'Q', Piece_Info::QUEEN, colour), chess_board);
}

void Queen::SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board)
{
	for (auto& queen : pieces)
	{
		if (queen.piece_colour == Piece_Info::BLACK)
		{
			chess_board.UpdateBoard(Piece_Info::SQUARES * Piece_Info::QUEEN_DIST + Piece_Info::CENTER, Piece_Info::B_FIRST_ROW, queen.piece_symbol);
			queen.piece_x = Piece_Info::SQUARES * Piece_Info::QUEEN_DIST + Piece_Info::CENTER;
			queen.piece_y = Piece_Info::B_FIRST_ROW;
		}
		else
		{
			chess_board.UpdateBoard(Piece_Info::SQUARES * Piece_Info::QUEEN_DIST + Piece_Info::CENTER, Piece_Info::W_FIRST_ROW, queen.piece_symbol);
			queen.piece_x = Piece_Info::SQUARES * Piece_Info::QUEEN_DIST + Piece_Info::CENTER;
			queen.piece_y = Piece_Info::W_FIRST_ROW;
		}
	}
}

void Queen::MovePiece(std::vector<ChessPieces>& piece, ChessBoard& chess_board, int index, int move_dist, bool diagonal, int left_right, int up_down)
{
	if (!piece[index].captured)
	{
		chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());

		if (piece[index].piece_x + Piece_Info::SQUARES * move_dist < chess_board.Size() && left_right == Piece_Info::RIGHT_OR_DOWN && !diagonal)
			piece[index].piece_x += Piece_Info::SQUARES * move_dist;

		else if (left_right == Piece_Info::LEFT_OR_UP && !diagonal)
			piece[index].piece_x -= Piece_Info::SQUARES * move_dist;

		else if (up_down == Piece_Info::RIGHT_OR_DOWN && !diagonal)
			piece[index].piece_y += Piece_Info::SQUARES * move_dist;

		else if (up_down == Piece_Info::LEFT_OR_UP && !diagonal)
			piece[index].piece_y -= Piece_Info::SQUARES * move_dist;


		if (diagonal && left_right == Piece_Info::RIGHT_OR_DOWN)
		{
			piece[index].piece_y += Piece_Info::SQUARES * move_dist;
			piece[index].piece_x += Piece_Info::SQUARES * move_dist;
		}
		else if (diagonal && left_right == Piece_Info::LEFT_OR_UP)
		{
			piece[index].piece_y += Piece_Info::SQUARES * move_dist;
			piece[index].piece_x -= Piece_Info::SQUARES * move_dist;
		}
		else if (diagonal && left_right == Piece_Info::RIGHT_OR_DOWN && up_down == Piece_Info::LEFT_OR_UP)
		{
			piece[index].piece_y -= Piece_Info::SQUARES * move_dist;
			piece[index].piece_x += Piece_Info::SQUARES * move_dist;
		}
		else if (diagonal && left_right == Piece_Info::LEFT_OR_UP && up_down == Piece_Info::LEFT_OR_UP)
		{
			piece[index].piece_y -= Piece_Info::SQUARES * move_dist;
			piece[index].piece_x -= Piece_Info::SQUARES * move_dist;
		}

		chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, piece[index].piece_symbol);
	}
}
