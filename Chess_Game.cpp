#include "Chess_Game.h"
#include "ChessPieces.h"

#include "Windows.h"


void ChessGame::RunGame()
{

	ChessBoard board;

	ChessPieces B_Pawns(board, Piece_Info::PAWN_QUANTITY, 'P', Piece_Info::PAWN, Piece_Info::BLACK);
	ChessPieces W_Pawns(board, Piece_Info::PAWN_QUANTITY, 'P', Piece_Info::PAWN, Piece_Info::WHITE);

	ChessPieces B_Rooks(board, Piece_Info::ROOKS_QUANTITY, 'R', Piece_Info::ROOK, Piece_Info::BLACK);
	ChessPieces W_Rooks(board, Piece_Info::ROOKS_QUANTITY, 'R', Piece_Info::ROOK, Piece_Info::WHITE);

	ChessPieces B_Knights(board, Piece_Info::KNIGHTS_QUANTITY, 'k', Piece_Info::KNIGHT, Piece_Info::BLACK);
	ChessPieces W_Knights(board, Piece_Info::KNIGHTS_QUANTITY, 'k', Piece_Info::KNIGHT, Piece_Info::WHITE);

	ChessPieces B_Bishops(board, Piece_Info::BISHOPS_QUANTITY, 'B', Piece_Info::BISHOP, Piece_Info::BLACK);
	ChessPieces W_Bishops(board, Piece_Info::BISHOPS_QUANTITY, 'B', Piece_Info::BISHOP, Piece_Info::WHITE);

	ChessPieces B_King(board, Piece_Info::KING_QUANTITY, 'K', Piece_Info::KING, Piece_Info::BLACK);
	ChessPieces W_King(board, Piece_Info::KING_QUANTITY, 'K', Piece_Info::KING, Piece_Info::WHITE);

	ChessPieces B_Queen(board, Piece_Info::QUEEN_QUANTITY, 'Q', Piece_Info::QUEEN, Piece_Info::BLACK);
	ChessPieces W_Queen(board, Piece_Info::QUEEN_QUANTITY, 'Q', Piece_Info::QUEEN, Piece_Info::WHITE);
    
    
	std::vector<ChessPieces>& BPawn_pieces = B_Pawns.GetPieces();
	std::vector<ChessPieces>& BRook_pieces = B_Rooks.GetPieces();
	std::vector<ChessPieces>& BKnight_pieces = B_Knights.GetPieces();
	std::vector<ChessPieces>& BBishops_pieces = B_Bishops.GetPieces();
	std::vector<ChessPieces>& BKing_piece = B_King.GetPieces();
	std::vector<ChessPieces>& BQueen_piece = B_Bishops.GetPieces();

	std::vector<ChessPieces>& WPawn_pieces = W_Pawns.GetPieces();
	std::vector<ChessPieces>& WRook_pieces = W_Rooks.GetPieces();
	std::vector<ChessPieces>& WKnight_pieces = W_Knights.GetPieces();
	std::vector<ChessPieces>& WBishop_pieces = W_Bishops.GetPieces();
	std::vector<ChessPieces>& WKing_piece = W_King.GetPieces();
	std::vector<ChessPieces>& WQueen_pieces = W_Queen.GetPieces();

	BPawn_pieces[3].MovePiece(board, 12, 2);

	std::cout << BPawn_pieces[3].GetY();

	board.DrawBoard();



	while (true)
	{
		Sleep(50);
	}

}

void ChessGame::DisplayGuide()
{
}

void ChessGame::DisplayMenu()
{
	int input{};
	
	std::cout << "Chess - \n[0] Start Game \n[1] Exit Game\n[2]Guide\n" << std::endl;

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