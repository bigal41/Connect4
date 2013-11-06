#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game{
	public:
		void init();
		void play();
		int checkPiece(int);
		bool checkHorz();
		bool checkVert();
		int  getMove();
	private:
		bool win;
		char player1;
		char player2;
		int turn;
		int piece;
		int place;
		Board* b;
  
};

#endif
