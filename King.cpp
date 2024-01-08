#include "King.h"

King::King(ChessBoard& chess_board, int colour)
{
	SpawnPieces(Kings = GeneratePieces(Piece_Info::KING_QUANTITY, 'K', Piece_Info::KING, colour), chess_board);
}

void King::SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board)
{
	for (auto& king : pieces)
	{
		if (king.piece_colour == Piece_Info::BLACK)
		{
			chess_board.UpdateBoard(Piece_Info::SQUARES * Piece_Info::KING_DIST + Piece_Info::CENTER, Piece_Info::B_FIRST_ROW, king.piece_symbol);
			king.piece_x = Piece_Info::SQUARES * Piece_Info::KING_DIST + Piece_Info::CENTER;
			king.piece_y = Piece_Info::B_FIRST_ROW;

			king.on_square = king.piece_x / Piece_Info::SQUARES + Piece_Info::B_FIRST_ROW - Piece_Info::CENTER + 1;
			chess_board.friendly_squares[king.on_square] = true;
		}
		else
		{
			chess_board.UpdateBoard(Piece_Info::SQUARES * Piece_Info::KING_DIST + Piece_Info::CENTER, Piece_Info::W_FIRST_ROW, king.piece_symbol);
			king.piece_x = Piece_Info::SQUARES * Piece_Info::KING_DIST + Piece_Info::CENTER;
			king.piece_y = Piece_Info::W_FIRST_ROW;
		}
	}

}

void King::MovePiece(std::vector<ChessPieces>& piece, ChessBoard& chess_board, int index, bool diagonal, int left_right, int up_down)
{
	if (!piece[index].captured && InBounds(chess_board, piece[index].piece_x, piece[index].piece_y))
	{
		if (left_right == Piece_Info::RIGHT_OR_DOWN && !diagonal)
		{
		   if((InBounds(chess_board, piece[index].piece_x + Piece_Info::SQUARES, piece[index].piece_y))
			   &&!IsFriendly(chess_board, piece[index].piece_x + Piece_Info::SQUARES, piece[index].piece_y))
		   {
			 chess_board.friendly_squares[piece[index].on_square] = false;

			 chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
             piece[index].piece_x += Piece_Info::SQUARES;
		   }  
		}
			
		else if (piece[index].piece_x - Piece_Info::SQUARES > 0 && left_right == Piece_Info::LEFT_OR_UP && !diagonal)
		{
		  if ((InBounds(chess_board, piece[index].piece_x - Piece_Info::SQUARES, piece[index].piece_y))
			  && !IsFriendly(chess_board, piece[index].piece_x - Piece_Info::SQUARES, piece[index].piece_y))
		  {
			  chess_board.friendly_squares[piece[index].on_square] = false;

			  chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
			  piece[index].piece_x -= Piece_Info::SQUARES;
		  }
		}
			
		else if (up_down == Piece_Info::RIGHT_OR_DOWN && !diagonal)
		{
			if ((InBounds(chess_board, piece[index].piece_x, piece[index].piece_y + Piece_Info::SQUARES))
				&& !IsFriendly(chess_board, piece[index].piece_x, piece[index].piece_y + Piece_Info::SQUARES))
			{
				chess_board.friendly_squares[piece[index].on_square] = false;

				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y += Piece_Info::SQUARES;
			}
		}

		else if (up_down == Piece_Info::LEFT_OR_UP && !diagonal)
		{
			if ((InBounds(chess_board, piece[index].piece_x, piece[index].piece_y - Piece_Info::SQUARES)) 
				&& !IsFriendly(chess_board, piece[index].piece_x, piece[index].piece_y - Piece_Info::SQUARES))
			{
				chess_board.friendly_squares[piece[index].on_square] = false;

				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y -= Piece_Info::SQUARES;
			}
		}

		if (diagonal && left_right == Piece_Info::RIGHT_OR_DOWN && up_down == Piece_Info::RIGHT_OR_DOWN)
		{
			if ((InBounds(chess_board, piece[index].piece_x + Piece_Info::SQUARES, piece[index].piece_y + Piece_Info::SQUARES))
				&& !IsFriendly(chess_board, piece[index].piece_x + Piece_Info::SQUARES, piece[index].piece_y + Piece_Info::SQUARES))
			{
				chess_board.friendly_squares[piece[index].on_square] = false;

				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y += Piece_Info::SQUARES;
				piece[index].piece_x += Piece_Info::SQUARES;
			}
		}

		else if (diagonal && left_right == Piece_Info::LEFT_OR_UP && up_down == Piece_Info::RIGHT_OR_DOWN)
		{
			if ((InBounds(chess_board, piece[index].piece_x - Piece_Info::SQUARES, piece[index].piece_y + Piece_Info::SQUARES)) 
				&& !IsFriendly(chess_board, piece[index].piece_x - Piece_Info::SQUARES, piece[index].piece_y + Piece_Info::SQUARES))
			{
				chess_board.friendly_squares[piece[index].on_square] = false;

				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y += Piece_Info::SQUARES;
				piece[index].piece_x -= Piece_Info::SQUARES;
			}
		}

		else if (diagonal && left_right == Piece_Info::RIGHT_OR_DOWN && up_down == Piece_Info::LEFT_OR_UP)
		{
			if ((InBounds(chess_board, piece[index].piece_x + Piece_Info::SQUARES, piece[index].piece_y - Piece_Info::SQUARES))
				&& !IsFriendly(chess_board, piece[index].piece_x + Piece_Info::SQUARES, piece[index].piece_y - Piece_Info::SQUARES))
			{
				chess_board.friendly_squares[piece[index].on_square] = false;

				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y -= Piece_Info::SQUARES;
				piece[index].piece_x += Piece_Info::SQUARES;
			}
		}

		else if (diagonal && left_right == Piece_Info::LEFT_OR_UP && up_down == Piece_Info::LEFT_OR_UP)
		{
			if ((InBounds(chess_board, piece[index].piece_x - Piece_Info::SQUARES, piece[index].piece_y - Piece_Info::SQUARES))
				&& !IsFriendly(chess_board, piece[index].piece_x - Piece_Info::SQUARES, piece[index].piece_y - Piece_Info::SQUARES))
			{
				chess_board.friendly_squares[piece[index].on_square] = false;

				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y -= Piece_Info::SQUARES;
				piece[index].piece_x -= Piece_Info::SQUARES;
			}
		}

		piece[index].on_square = piece[index].piece_x / Piece_Info::SQUARES + piece[index].piece_y - Piece_Info::CENTER + 1;
		chess_board.friendly_squares[piece[index].on_square] = true;

		chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, piece[index].piece_symbol);
	}
}
