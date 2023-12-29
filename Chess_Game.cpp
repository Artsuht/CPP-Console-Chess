#include "Chess_Game.h"

void ChessGame::RunGame()
{
    ChessBoard board;
	board.DrawBoard();
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