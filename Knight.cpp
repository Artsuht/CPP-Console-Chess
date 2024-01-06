#include "Knight.h"

Knight::Knight(ChessBoard& chess_board, int colour)
{
	SpawnPieces(Knights = GeneratePieces(Piece_Info::KNIGHTS_QUANTITY, 'k', Piece_Info::KNIGHT, colour), chess_board);
}

void Knight::SpawnPieces(std::vector<ChessPieces>& pieces, ChessBoard& chess_board)
{
	int sq = Piece_Info::SQUARES;
	for (auto& knight : pieces)
	{
		if (knight.piece_colour == Piece_Info::BLACK)
		{
			chess_board.UpdateBoard(sq + Piece_Info::CENTER, Piece_Info::B_FIRST_ROW, knight.piece_symbol);
			knight.piece_x = sq + Piece_Info::CENTER;
			knight.piece_y = Piece_Info::B_FIRST_ROW;

			sq *= Piece_Info::KNIGHT2_DIST;
		}
		else
		{
			chess_board.UpdateBoard(sq + Piece_Info::CENTER, Piece_Info::W_FIRST_ROW, knight.piece_symbol);
			knight.piece_x = sq + Piece_Info::CENTER;
			knight.piece_y = Piece_Info::W_FIRST_ROW;

			sq *= Piece_Info::KNIGHT2_DIST;
		}
	}
}

void Knight::MovePiece(std::vector<ChessPieces>& piece, ChessBoard& chess_board, int index, int left_right, int up_down)
{
	if (!piece[index].captured && piece[index].InBounds(chess_board, piece[index].piece_x, piece[index].piece_y))
	{
		//Down the board
		if (left_right == Piece_Info::FAR_RIGHT && up_down == Piece_Info::RIGHT_OR_DOWN) //Down 2 x
		{
			if (piece[index].InBounds(chess_board, piece[index].piece_x + Piece_Info::SQUARES, piece[index].piece_y + (Piece_Info::SQUARES * 2)))
			{
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y += Piece_Info::SQUARES;
				piece[index].piece_x += Piece_Info::SQUARES * 2;
			}
		}
		else if (left_right == Piece_Info::FAR_LEFT && up_down == Piece_Info::RIGHT_OR_DOWN) //Down - 2x
		{
			if (piece[index].InBounds(chess_board, piece[index].piece_x - (Piece_Info::SQUARES * 2), piece[index].piece_y + Piece_Info::SQUARES))
			{
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y += Piece_Info::SQUARES;
				piece[index].piece_x += Piece_Info::SQUARES * 2;
			}
		}
		else if (left_right == Piece_Info::RIGHT_OR_DOWN && up_down == Piece_Info::RIGHT_OR_DOWN) 
		{
			if (piece[index].InBounds(chess_board, piece[index].piece_x + Piece_Info::SQUARES, piece[index].piece_y + (Piece_Info::SQUARES * 2)))
			{
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_x += Piece_Info::SQUARES;
				piece[index].piece_y += Piece_Info::SQUARES * 2;
			}
		}
		else if (left_right == Piece_Info::LEFT_OR_UP && up_down == Piece_Info::RIGHT_OR_DOWN)
		{
			if (piece[index].InBounds(chess_board, piece[index].piece_x - Piece_Info::SQUARES, piece[index].piece_y + (Piece_Info::SQUARES * 2)))
			{
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y += Piece_Info::SQUARES * 2;
				piece[index].piece_x -= Piece_Info::SQUARES;
			}
		}
		//Up the board
		else if (left_right == Piece_Info::FAR_RIGHT && up_down == Piece_Info::LEFT_OR_UP)
		{
			if (piece[index].InBounds(chess_board, piece[index].piece_x + (Piece_Info::SQUARES * 2), piece[index].piece_y - Piece_Info::SQUARES))
			{
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y -= Piece_Info::SQUARES;
				piece[index].piece_x += Piece_Info::SQUARES * 2;
			}
		}

		else if (left_right == Piece_Info::FAR_LEFT && up_down == Piece_Info::LEFT_OR_UP)
		{
			if (piece[index].InBounds(chess_board, piece[index].piece_x - (Piece_Info::SQUARES * 2), piece[index].piece_y - Piece_Info::SQUARES))
			{
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y -= Piece_Info::SQUARES;
				piece[index].piece_x -= Piece_Info::SQUARES * 2;
			}
		}
		else if (left_right == Piece_Info::RIGHT_OR_DOWN && up_down == Piece_Info::LEFT_OR_UP)
		{
			if (piece[index].InBounds(chess_board, piece[index].piece_x + Piece_Info::SQUARES, piece[index].piece_y - (Piece_Info::SQUARES * 2)))
			{
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y -= Piece_Info::SQUARES * 2;
				piece[index].piece_x += Piece_Info::SQUARES;
			}
		}
		else if (left_right == Piece_Info::LEFT_OR_UP && up_down == Piece_Info::LEFT_OR_UP)
		{
			if (piece[index].InBounds(chess_board, piece[index].piece_x - Piece_Info::SQUARES, piece[index].piece_y - (Piece_Info::SQUARES * 2)))
			{
				chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, chess_board.Empty());
				piece[index].piece_y -= Piece_Info::SQUARES * 2;
				piece[index].piece_x -= Piece_Info::SQUARES;
			}
		}
		chess_board.UpdateBoard(piece[index].piece_x, piece[index].piece_y, piece[index].piece_symbol);
	}
}
