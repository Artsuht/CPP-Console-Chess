#include "Chess_Game.h"

#include "Rook.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"



#include "Windows.h"


void ChessGame::RunGame()
{

	ChessBoard board;

	Pawn b_pawns(board, Piece_Info::BLACK);
    Rook b_rooks(board, Piece_Info::BLACK);
	Knight b_knights(board, Piece_Info::BLACK);
	Bishop b_bishop(board, Piece_Info::BLACK);
	King b_king(board, Piece_Info::BLACK);
	Queen b_queen(board, Piece_Info::BLACK);

	Pawn w_pawns(board, Piece_Info::WHITE);
	Rook w_rooks(board, Piece_Info::WHITE);
	Knight w_knights(board, Piece_Info::WHITE);
	Bishop w_bishop(board, Piece_Info::WHITE);
	King w_king(board, Piece_Info::WHITE);
	Queen w_queen(board, Piece_Info::WHITE);

	board.DrawBoard();

	int piece_type;
	int piece_num;

	while (game_running)
	{
		std::cout << "You are playing as black (Top).\n";
		std::cout << "Choose a piece - [1]Pawn, [2]Rook, [3]Knight, [4]Bishop, [5]King, [6]Queen:" << std::endl;

		std::cin >> piece_type;

		std::cout << "Choose which piece out of them you wish to move: " << std::endl;
		std::cin >> piece_num;

		switch (piece_type)
		{
		case PAWN:
			b_pawns.MovePiece(b_pawns.GetPieces(), board, piece_num);
			break;

		case ROOK:
			break;

		case KNIGHT:
			break;

		case BISHOP:
			b_bishop.MovePiece(b_bishop.GetPieces(), board, piece_num, 2, 2);
			b_bishop.PrintXY(b_bishop.GetPieces());
			break;

		case KING:
			break;

		case QUEEN:
			break;
		}

		board.DrawBoard();
	}
}

void ChessGame::DisplayGuide()
{
}

void ChessGame::DisplayMenu()
{
	int input{};
	
	std::cout << "Chess - \n[0] Start Game \n[1] Exit Game\n[2] Guide\n" << std::endl;

	std::cin >> input;
	switch (input)
	{
	case START_GAME:
		system("cls");
		RunGame();
		break;
	case GAME_GUIDE:
		DisplayGuide();
		break;

	case EXIT_GAME:
		break;

	default:
		std::cout << "Invalid input." << std::endl;
		break;
	}
}
