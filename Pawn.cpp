#include "Pawn.h"

Pawn::Pawn(ChessBoard& chess_board, int colour)
{
	SpawnPieces(Pawns = GeneratePieces(Piece_Info::PAWN_QUANTITY, 'P', Piece_Info::PAWN, colour), chess_board);
}

void Pawn::SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board)
{
	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces[i].piece_colour == Piece_Info::BLACK)
		{
			chess_board.UpdateBoard(i * Piece_Info::SQUARES + Piece_Info::CENTER, Piece_Info::B_SECOND_ROW, pieces[i].piece_symbol);
			pieces[i].piece_x = i * Piece_Info::SQUARES + Piece_Info::CENTER;
			pieces[i].piece_y = Piece_Info::B_SECOND_ROW;
		}
		else 
		{
			chess_board.UpdateBoard(i * Piece_Info::SQUARES + Piece_Info::CENTER, Piece_Info::W_SECOND_ROW, pieces[i].piece_symbol);
			pieces[i].piece_x = i * Piece_Info::SQUARES + Piece_Info::CENTER;
			pieces[i].piece_y = Piece_Info::W_SECOND_ROW;
		}
	}
}

void Pawn::MovePiece(std::vector<ChessPieces>& piece, ChessBoard& chess_board, int index, int x)
{
	if (!piece[index].captured && piece[index].InBounds(chess_board, piece[index].piece_x, piece[index].piece_y))
	{
			//Check if player is trying to move pawn two or more squares ahead.0
			if (((x * Piece_Info::SQUARES)) / Piece_Info::SQUARES >= 2 && piece[index].double_move)
			{
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());

				piece[index].piece_y += Piece_Info::SQUARES * 2;
				piece[index].double_move = false;
			}
			else //Just default to a single square
			{
				if (piece[index].InBounds(chess_board, piece[index].piece_x, piece[index].piece_y + Piece_Info::SQUARES))
				{
					chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());

					piece[index].piece_y += Piece_Info::SQUARES;
					piece[index].double_move = false;
				}
			}

			chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, piece[index].piece_symbol);
	}
}
