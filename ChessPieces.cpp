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

void ChessPieces::SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board)
{ 
	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces[i].piece_type == PAWN && pieces[i].piece_colour == BLACK)
		{
			chess_board.UpdateBoard(i * SQUARES + CENTER, B_SECOND_ROW, pieces[i].piece_symbol);
			pieces[i].piece_x = i * SQUARES + CENTER;
			pieces[i].piece_y = B_SECOND_ROW;
		}

		else if (pieces[i].piece_type == PAWN && pieces[i].piece_colour == WHITE)
		{
			chess_board.UpdateBoard(i * SQUARES + CENTER, W_SECOND_ROW, pieces[i].piece_symbol);
			pieces[i].piece_x = i * SQUARES + CENTER;
			pieces[i].piece_y = W_SECOND_ROW;
		}

		else if (pieces[i].piece_type == ROOK && pieces[i].piece_colour == BLACK)
		{
			if (i == 0)
			{
				chess_board.UpdateBoard(CENTER, B_FIRST_ROW, pieces[i].piece_symbol);
				pieces[i].piece_x = CENTER;
				pieces[i].piece_y = B_FIRST_ROW;
			}

			if (i == 1)
			{
				chess_board.UpdateBoard(SQUARES * ROOK2_DIST - CENTER, B_FIRST_ROW, pieces[i].piece_symbol);
				pieces[i].piece_x = SQUARES * ROOK2_DIST - CENTER;
				pieces[i].piece_y = B_FIRST_ROW;
			}

		}

		else if (pieces[i].piece_type == ROOK && pieces[i].piece_colour == WHITE)
		{
			if (i == 0)
			{
				chess_board.UpdateBoard(CENTER, W_FIRST_ROW, pieces[i].piece_symbol);
				pieces[i].piece_x = CENTER;
				pieces[i].piece_y = W_FIRST_ROW;
			}

			if (i == 1)
			{
				chess_board.UpdateBoard(SQUARES * 8 - CENTER, W_FIRST_ROW, pieces[i].piece_symbol);
				pieces[i].piece_x = SQUARES * ROOK2_DIST - CENTER; //Will exceed borders if added
				pieces[i].piece_y = W_FIRST_ROW;
			}

		}

		else if (pieces[i].piece_type == KNIGHT && pieces[i].piece_colour == BLACK)
		{
			if (i == 0)
			{
				chess_board.UpdateBoard(SQUARES + CENTER, B_FIRST_ROW, pieces[i].piece_symbol);

				pieces[i].piece_x = SQUARES + CENTER;
				pieces[i].piece_y = B_FIRST_ROW;
			}

			if (i == 1)
			{
				chess_board.UpdateBoard(SQUARES * KNIGHT2_DIST + CENTER, B_FIRST_ROW, pieces[i].piece_symbol);
				pieces[i].piece_x = SQUARES * KNIGHT2_DIST + CENTER;
				pieces[i].piece_y = B_FIRST_ROW;
 			}
		}

		else if (pieces[i].piece_type == KNIGHT && pieces[i].piece_colour == WHITE)
		{
			if (i == 0)
			{
				chess_board.UpdateBoard(SQUARES + CENTER, W_FIRST_ROW, pieces[i].piece_symbol);

				pieces[i].piece_x =  SQUARES + CENTER;
				pieces[i].piece_y = W_FIRST_ROW;
			}

			if (i == 1)
			{
				chess_board.UpdateBoard(SQUARES * KNIGHT2_DIST + CENTER, W_FIRST_ROW, pieces[i].piece_symbol);
				pieces[i].piece_x = SQUARES * KNIGHT2_DIST + CENTER;
				pieces[i].piece_y = W_FIRST_ROW;
			}
		}

		else if (pieces[i].piece_type == BISHOP && pieces[i].piece_colour == BLACK)
		{
			if (i == 0)
			{
				chess_board.UpdateBoard(SQUARES * BISHOP_DIST + CENTER, B_FIRST_ROW, pieces[i].piece_symbol);
				pieces[i].piece_x = SQUARES * BISHOP_DIST + CENTER;
				pieces[i].piece_y = B_FIRST_ROW;
			}

			if (i == 1)
			{
				chess_board.UpdateBoard(SQUARES * BISHOP2_DIST + CENTER, B_FIRST_ROW, pieces[i].piece_symbol);
				pieces[i].piece_x = SQUARES * BISHOP2_DIST + CENTER;
				pieces[i].piece_y = B_FIRST_ROW;
			}
		}

		else if (pieces[i].piece_type == BISHOP && pieces[i].piece_colour == WHITE)
		{
			if (i == 0)
			{
				chess_board.UpdateBoard(SQUARES * BISHOP_DIST + CENTER, W_FIRST_ROW, pieces[i].piece_symbol);
				pieces[i].piece_x = SQUARES * BISHOP_DIST + CENTER;
				pieces[i].piece_y = W_FIRST_ROW;
			}

			if (i == 1)
			{
					chess_board.UpdateBoard(SQUARES * BISHOP2_DIST + CENTER, W_FIRST_ROW, pieces[i].piece_symbol);
					pieces[i].piece_x = SQUARES * BISHOP2_DIST + CENTER;
					pieces[i].piece_y = W_FIRST_ROW;
			}
		}

		else if (pieces[i].piece_type == KING && pieces[i].piece_colour == BLACK)
		{
			chess_board.UpdateBoard(SQUARES * KING_DIST + CENTER, B_FIRST_ROW, pieces[i].piece_symbol);
			pieces[i].piece_x = SQUARES * KING_DIST + CENTER;
			pieces[i].piece_y = B_FIRST_ROW;
		}

		else if (pieces[i].piece_type == KING && pieces[i].piece_colour == WHITE)
		{
			chess_board.UpdateBoard(SQUARES * KING_DIST + CENTER, W_FIRST_ROW, pieces[i].piece_symbol);
			pieces[i].piece_x = SQUARES * KING_DIST + CENTER;
			pieces[i].piece_y = W_FIRST_ROW;
		}

		else if (pieces[i].piece_type == QUEEN && pieces[i].piece_colour == BLACK)
		{
			chess_board.UpdateBoard(SQUARES * QUEEN_DIST + CENTER, B_FIRST_ROW, pieces[i].piece_symbol);
			pieces[i].piece_x = SQUARES * QUEEN_DIST;
			pieces[i].piece_y = B_FIRST_ROW;
		}

		else if (pieces[i].piece_type == QUEEN && pieces[i].piece_colour == WHITE)
		{
			chess_board.UpdateBoard(SQUARES * QUEEN_DIST + CENTER, W_FIRST_ROW, pieces[i].piece_symbol);
			pieces[i].piece_x = SQUARES * QUEEN_DIST;
			pieces[i].piece_y = W_FIRST_ROW;
		}

	}
}

void ChessPieces::MovePiece(ChessPieces& piece, ChessBoard& chess_board, int p_x, int p_y)
{
	piece.piece_y *= 2;
	chess_board.UpdateBoard(piece.piece_x, piece.piece_y, piece.piece_symbol);
}

