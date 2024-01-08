#include "Chess_Game.h"

#include "ChessEngine.h"


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

    int piece_type{};
    int piece_num{};
    int  move_dist;
    int left_right{};
    int up_down{};
    bool diagonal{};

    while (game_running)
    {
        std::cout << "You are playing as black (Top).\n";
        std::cout << "Choose a piece - [1]Pawn, [2]Rook, [3]Knight, [4]Bishop, [5]King, [6]Queen:\n";
        std::cout << "Directions [1]Left, [2]Right, [3]Far Left, [4] Far Right\n";

        std::cin >> piece_type;

        switch (piece_type)
        {
        case PAWN:

            std::cout << "Choose which piece out of them you wish to move - [0] = 1: \n";
            std::cin >> piece_num;

            std::cout << "How Many Squares: " << std::endl;
            std::cin >> move_dist;

            b_pawns.MovePiece(b_pawns.GetPieces(), board, piece_num, move_dist);
            break;

        case ROOK:

            std::cout << "Choose which piece out of them you wish to move - [0] = 1: \n";
            std::cin >> piece_num;

            std::cout << "How Many Squares:";
            std::cin >> move_dist;

            std::cout << "Left or Right?: ";
            std::cin >> left_right;

            std::cout << "Up or Down?:";
            std::cin >> up_down;

            b_rooks.MovePiece(b_rooks.GetPieces(), board, piece_num, move_dist, left_right, up_down);
            break;

        case KNIGHT:

            std::cout << "Choose which piece out of them you wish to move - [0] = 1: \n";
            std::cin >> piece_num;

            std::cout << "Left or Right?: ";
            std::cin >> left_right;

            std::cout << "Up or Down?:";
            std::cin >> up_down;

            b_knights.MovePiece(b_knights.GetPieces(), board, piece_num, left_right, up_down);
            break;

        case BISHOP:

            std::cout << "Choose which piece out of them you wish to move - [0] = 1: \n";
            std::cin >> piece_num;

            std::cout << "How Many Squares: ";
            std::cin >> move_dist;

            std::cout << "Left or Right?: ";
            std::cin >> left_right;

            std::cout << "Up or Down?:";
            std::cin >> up_down;

            b_bishop.MovePiece(b_bishop.GetPieces(), board, piece_num, move_dist, move_dist, left_right, up_down);
            break;

        case KING:

            std::cout << "How Many Squares:";
            std::cin >> move_dist;

            std::cout << "Left or Right?: ";
            std::cin >> left_right;

            std::cout << "Up or Down?:";
            std::cin >> up_down;

            std::cout << "Diagonal?:";
            std::cin >> diagonal;

            b_king.MovePiece(b_king.GetPieces(), board, 0, diagonal, left_right, up_down);
            break;

        case QUEEN:

            std::cout << "How Many Squares: " << std::endl;
            std::cin >> move_dist;

            std::cout << "Left or Right?: ";
            std::cin >> left_right;

            std::cout << "Up or Down?:";
            std::cin >> up_down;

            std::cout << "Diagonal?:";
            std::cin >> diagonal;

            b_queen.MovePiece(b_queen.GetPieces(), board, 0, move_dist, diagonal, left_right, up_down);
            break;

        default:
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

void ChessGame::NotationParser(std::string notation)
{
}
