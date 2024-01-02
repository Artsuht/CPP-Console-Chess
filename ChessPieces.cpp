#include "ChessPieces.h"
#include "Windows.h"

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
	//Define some constants and make it readable

	for (int i = 0; i < pieces.size(); i++)
	{
		if (pieces[i].piece_type == PAWN && pieces[i].piece_colour == BLACK) 
			chess_board.UpdateBoard((i * SQUARES) - CENTER, B_SECOND_ROW, pieces[i].piece_symbol);

		else if (pieces[i].piece_type == PAWN && pieces[i].piece_colour == WHITE)
			chess_board.UpdateBoard((i * SQUARES) - CENTER, W_SECOND_ROW, pieces[i].piece_symbol); 

		else if (pieces[i].piece_type == ROOK && pieces[i].piece_colour == BLACK)
			chess_board.UpdateBoard((i * SQUARES) - CENTER, B_FIRST_ROW, pieces[i].piece_symbol);

		else if (pieces[i].piece_type == ROOK && pieces[i].piece_colour == WHITE)
			chess_board.UpdateBoard((i * SQUARES) - CENTER, W_FIRST_ROW, pieces[i].piece_symbol);
		//Logic on all above is different for some reason, change it

		else if (pieces[i].piece_type == KNIGHT && pieces[i].piece_colour == BLACK)
		{
			if(i == 0)
			chess_board.UpdateBoard(((i + 1) * SQUARES) + CENTER , B_FIRST_ROW, pieces[i].piece_symbol);
			if(i == 1)
			  chess_board.UpdateBoard((i * SQUARES * 6) + CENTER, B_FIRST_ROW, pieces[i].piece_symbol);
		}

		else if (pieces[i].piece_type == KNIGHT && pieces[i].piece_colour == WHITE)
		{
			if (i == 0)
				chess_board.UpdateBoard(((i + 1) * SQUARES) + CENTER, W_FIRST_ROW, pieces[i].piece_symbol); 
			if (i == 1)
				chess_board.UpdateBoard((i * SQUARES * 6) + CENTER, W_FIRST_ROW, pieces[i].piece_symbol); 
		}

		else if (pieces[i].piece_type == BISHOP && pieces[i].piece_colour == BLACK)
		{
			if (i == 0)
				chess_board.UpdateBoard(((i + 1) * SQUARES) + (CENTER * 3), B_FIRST_ROW, pieces[i].piece_symbol);
			if (i == 1)
				chess_board.UpdateBoard(((i * SQUARES) * 4) + (CENTER * 3), B_FIRST_ROW, pieces[i].piece_symbol); 
		}

		else if (pieces[i].piece_type == BISHOP && pieces[i].piece_colour == WHITE)
		{
			if (i == 0)
				chess_board.UpdateBoard(((i + 1) * SQUARES) + (CENTER * 3), W_FIRST_ROW, pieces[i].piece_symbol);
			if (i == 1)
				chess_board.UpdateBoard(((i * SQUARES) * 4) + (CENTER * 3), W_FIRST_ROW, pieces[i].piece_symbol);
		}

		else if (pieces[i].piece_type == KING && pieces[i].piece_colour == BLACK)
				chess_board.UpdateBoard(((i + 1) * SQUARES) * 4 + CENTER, B_FIRST_ROW, pieces[i].piece_symbol);

		else if (pieces[i].piece_type == KING && pieces[i].piece_colour == WHITE)
			chess_board.UpdateBoard(((i + 1) * SQUARES) * 4 + CENTER, W_FIRST_ROW, pieces[i].piece_symbol);

		else if (pieces[i].piece_type == QUEEN && pieces[i].piece_colour == BLACK)
			chess_board.UpdateBoard(((i + 1) * SQUARES) * 3 + CENTER, B_FIRST_ROW, pieces[i].piece_symbol);

		else if (pieces[i].piece_type == QUEEN  && pieces[i].piece_colour == WHITE)
			chess_board.UpdateBoard(((i + 1) * SQUARES) * 3 + CENTER, W_FIRST_ROW, pieces[i].piece_symbol);

	}
}

void ChessPieces::MovePiece(ChessPieces& piece, ChessBoard& chess_board, int p_x, int p_y)
{
	

}

