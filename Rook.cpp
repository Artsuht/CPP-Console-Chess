#include "Rook.h"

Rook::Rook(ChessBoard& chess_board, int colour)
{
	SpawnPieces(Rooks = GeneratePieces(Piece_Info::ROOKS_QUANTITY, 'R', Piece_Info::ROOK, colour), chess_board);
}

void Rook::SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board)
{
	int sq = Piece_Info::SQUARES;
	for(auto& rook : pieces)
	{
		if (rook.piece_colour == Piece_Info::BLACK)
		{
			chess_board.UpdateBoard(sq - Piece_Info::CENTER, Piece_Info::B_FIRST_ROW, rook.piece_symbol);
			rook.piece_x = sq - Piece_Info::CENTER;
			rook.piece_y = Piece_Info::B_FIRST_ROW;

			sq *= Piece_Info::ROOK2_DIST;

			rook.on_square = rook.piece_x / Piece_Info::SQUARES + Piece_Info::B_SECOND_ROW - Piece_Info::CENTER;
			chess_board.friendly_squares[rook.on_square] = false;
		}
		else
		{
			chess_board.UpdateBoard(sq - Piece_Info::CENTER, Piece_Info::W_FIRST_ROW, rook.piece_symbol);
			rook.piece_x = sq - Piece_Info::CENTER;
			rook.piece_y = Piece_Info::W_FIRST_ROW;

			sq *= Piece_Info::ROOK2_DIST;
		}
	}
}

void Rook::MovePiece(std::vector<ChessPieces>& piece, ChessBoard& chess_board, int index, int xy, int left_right, int up_down)
{
	if (!piece[index].captured && piece[index].InBounds(chess_board, piece[index].piece_x, piece[index].piece_y))
	{
			if (left_right == Piece_Info::RIGHT_OR_DOWN)
			{
				if (InBounds(chess_board, piece[index].piece_x + (xy * Piece_Info::SQUARES), piece[index].piece_y) 
					&& !IsFriendly(chess_board, piece[index].piece_x + (xy * Piece_Info::SQUARES), piece[index].piece_y))
				{ 
				  chess_board.friendly_squares[piece[index].on_square] = false;

				  chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
                  piece[index].piece_x += xy * Piece_Info::SQUARES;
				}
			}

			else if (left_right == Piece_Info::LEFT_OR_UP)
			{
			  if (InBounds(chess_board, piece[index].piece_x - (xy * Piece_Info::SQUARES), piece[index].piece_y) 
				  && !IsFriendly(chess_board, piece[index].piece_x - (xy * Piece_Info::SQUARES), piece[index].piece_y))
			  { 
			    chess_board.friendly_squares[piece[index].on_square] = false;

				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_x -= xy * Piece_Info::SQUARES;
			  }
			}

			else if (up_down == Piece_Info::RIGHT_OR_DOWN)
			{
			  if (InBounds(chess_board, piece[index].piece_x, piece[index].piece_y + (xy * Piece_Info::SQUARES)) 
				  && !IsFriendly(chess_board, piece[index].piece_x, piece[index].piece_y + (xy * Piece_Info::SQUARES)))
			  {
				 chess_board.friendly_squares[piece[index].on_square] = false;

				 chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
                 piece[index].piece_y += xy * Piece_Info::SQUARES;
			  }
            
			}
				
			else if (up_down == Piece_Info::LEFT_OR_UP)
			{
				if (InBounds(chess_board, piece[index].piece_x, piece[index].piece_y - (xy * Piece_Info::SQUARES))
					&& !IsFriendly(chess_board, piece[index].piece_x, piece[index].piece_y - (xy * Piece_Info::SQUARES)))
				{
				 chess_board.friendly_squares[piece[index].on_square] = false;

				 chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
                 piece[index].piece_y -= xy * Piece_Info::SQUARES;
				}
              
			}	

			piece[index].on_square = piece[index].piece_x / Piece_Info::SQUARES + piece[index].piece_y - Piece_Info::CENTER + 1;
			chess_board.friendly_squares[piece[index].on_square] = true;

			chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, piece[index].piece_symbol);
	}
}
