#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "ChessBoard.h"

static bool game_running = true;

class ChessGame
{
 public:

  static void RunGame();
  void DisplayMenu();

 private:
  enum menu_options
  {
	START_GAME,
	END_GAME,
	EXIT_GAME,
  };
};


#endif //CHESS_GAME_H