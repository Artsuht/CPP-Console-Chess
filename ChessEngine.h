#ifndef CHESSENGINE_H
#define CHESSENGINE_H

class ChessEngine
{
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
*Technical Details:
* A bool vector could be used to map optimal moves to a true or false
* A move seek limit should be imposed e.g up to 10 moves ahead
*/
