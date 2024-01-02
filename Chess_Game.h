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

 private:


  enum menu_options
  {
	START_GAME,
	GAME_GUIDE,
	EXIT_GAME,
  };
};


#endif //CHESS_GAME_H