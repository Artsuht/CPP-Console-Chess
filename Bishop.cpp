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
		if (bishop.piece_colour == Piece_Info::BLACK)
		{
			chess_board.UpdateBoard(Piece_Info::SQUARES * b_dist + Piece_Info::CENTER, Piece_Info::B_FIRST_ROW, bishop.piece_symbol);
			bishop.piece_x = Piece_Info::SQUARES * b_dist + Piece_Info::CENTER;
			bishop.piece_y = Piece_Info::B_FIRST_ROW;
            
			b_dist = Piece_Info::BISHOP2_DIST;
		}
		else
		{
			chess_board.UpdateBoard(Piece_Info::SQUARES * b_dist + Piece_Info::CENTER, Piece_Info::W_FIRST_ROW, bishop.piece_symbol);
			bishop.piece_x = Piece_Info::SQUARES * b_dist + Piece_Info::CENTER;
			bishop.piece_y = Piece_Info::W_FIRST_ROW;

			b_dist = Piece_Info::BISHOP2_DIST;
		}
	}
}

void Bishop::MovePiece(std::vector<ChessPieces> &piece, ChessBoard& chess_board, int index, int x, int y, int left_right, int up_down)
{


	if (!piece[index].captured && piece[index].InBounds(chess_board ,piece[index].piece_x, piece[index].piece_y))
	{

		if (left_right == Piece_Info::RIGHT_OR_DOWN && up_down == Piece_Info::RIGHT_OR_DOWN)
		{
			if (piece[index].InBounds(chess_board, piece[index].piece_x + (x * Piece_Info::SQUARES), piece[index].piece_y + (x * Piece_Info::SQUARES)))
			{
             chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());

			 piece[index].piece_x += x * Piece_Info::SQUARES;
			 piece[index].piece_y += y * Piece_Info::SQUARES;
			}
			
		}

		else if (left_right == Piece_Info::LEFT_OR_UP && up_down == Piece_Info::RIGHT_OR_DOWN)
		{
			if (piece[index].InBounds(chess_board, piece[index].piece_x - (x * Piece_Info::SQUARES), piece[index].piece_y + (x * Piece_Info::SQUARES)))
			{
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());

				piece[index].piece_x -= x * Piece_Info::SQUARES;
				piece[index].piece_y += y * Piece_Info::SQUARES;
			}
		}

		else if (left_right == Piece_Info::RIGHT_OR_DOWN && up_down == Piece_Info::LEFT_OR_UP)
		{
			if (piece[index].InBounds(chess_board, piece[index].piece_x + (x * Piece_Info::SQUARES), piece[index].piece_y - (x * Piece_Info::SQUARES)))
			{
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());

				piece[index].piece_x += x * Piece_Info::SQUARES;
				piece[index].piece_y -= x * Piece_Info::SQUARES;
			}
		}

		else if (left_right == Piece_Info::LEFT_OR_UP && up_down == Piece_Info::LEFT_OR_UP)
		{
			if (piece[index].InBounds(chess_board, piece[index].piece_x - (x * Piece_Info::SQUARES), piece[index].piece_y - (x * Piece_Info::SQUARES)))
			{
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());

				piece[index].piece_x -= x * Piece_Info::SQUARES;
				piece[index].piece_y -= y * Piece_Info::SQUARES;
			}
		}

		chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, piece[index].piece_symbol);
	}
}
