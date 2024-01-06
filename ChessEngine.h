#ifndef CHESSENGINE_H
#define CHESSENGINE_H

#include "ChessPieces.h"
#include "Rook.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Windows.h"

class ChessEngine
{
public:

	void MakeMove();
	void SeekMoves();
private:
	std::vector<bool>MoveIsOptimal;
	static const int search_limit{ 10 }; //
	int pieces_lost{};
};

#endif //CHESSENGINE_H

/*
* Goal of the Engine:
  Find the most optimal move in a given scenario
  Sacrifices should not be avoid.
* How: 
* Check the available legal moves
* While checking available legal moves, check whether a move is the most optimal
* To check if the move is optimal, the moves after the potential move should be predicted.
* This meaning the player's legal moves must also be evaluated at the same time, and the current board positions.
* 
*/
