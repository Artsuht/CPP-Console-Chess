#ifndef CHESSENGINE_H
#define CHESSENGINE_H

#include "ChessPieces.h"

class ChessEngine
{
public:
	void SeekMoves();
private:
	std::vector<bool>MoveIsOptimal;
	static const int search_limit = 10; //
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
