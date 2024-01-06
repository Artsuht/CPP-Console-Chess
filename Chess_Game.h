#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "ChessBoard.h"

static bool game_running = true;

class ChessGame
{
 public:

  void RunGame();
  void DisplayGuide();
  void DisplayMenu();
  void NotationParser(std::string notation);//Maybe
 private:

  
   enum piece_options
   {
	   PAWN = 1,
	   ROOK,
	   KNIGHT,
	   BISHOP,
	   KING,
	   QUEEN
   };

  enum menu_options
  {
	START_GAME,
	GAME_GUIDE,
	EXIT_GAME,
  };
};


#endif //CHESS_GAME_H