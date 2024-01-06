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
				if (piece[index].InBounds(chess_board, piece[index].piece_x + (xy * Piece_Info::SQUARES), piece[index].piece_y))
				{ 
				  chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
                  piece[index].piece_x += xy * Piece_Info::SQUARES;
				}
			}
				

			else if (left_right == Piece_Info::LEFT_OR_UP)
			{
			  if (piece[index].InBounds(chess_board, piece[index].piece_x - (xy * Piece_Info::SQUARES), piece[index].piece_y))
			  { 
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
                piece[index].piece_x -= xy * Piece_Info::SQUARES;
			  }
             
			}
				

			else if (up_down == Piece_Info::RIGHT_OR_DOWN)
			{
			  if (piece[index].InBounds(chess_board, piece[index].piece_x, piece[index].piece_y + (xy * Piece_Info::SQUARES)))
			  {
				 chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
                piece[index].piece_y += xy * Piece_Info::SQUARES;
			  }
            
			}
				

			else if (up_down == Piece_Info::LEFT_OR_UP)
			{
				if (piece[index].InBounds(chess_board, piece[index].piece_x, piece[index].piece_y - (xy * Piece_Info::SQUARES)))
				{
				 chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
                 piece[index].piece_y -= xy * Piece_Info::SQUARES;
				}
              
			}	

			chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, piece[index].piece_symbol);
	}
}
