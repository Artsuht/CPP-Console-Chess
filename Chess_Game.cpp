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
	std::vector<ChessPieces>& BKing_pieces = B_King.GetPieces();
	std::vector<ChessPieces>& BQueen_pieces = B_Bishops.GetPieces();

	std::vector<ChessPieces>& WRook_pieces = W_Rooks.GetPieces();

	board.DrawBoard();

	std::cout << BPawn_pieces[7].GetX() << std::endl;
	std::cout << BPawn_pieces[2].GetY() << std::endl;


	while (true)
	{
		Sleep(50);
	}

}

void ChessGame::InitPieces(ChessBoard& board)
{
}

void ChessGame::DisplayMenu()
{
	int input{};
	
	std::cout << "Chess - \n[0] Start Game \n [1] Exit Game\n" << std::endl;

	std::cin >> input;
	switch (input)
	{
	case START_GAME:
		system("cls");
		RunGame();
		break;

	case EXIT_GAME:
		break;

	default:
		std::cout << "Invalid input." << std::endl;
		break;
	}
}