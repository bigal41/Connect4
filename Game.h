#ifndef GAME_H
#define GAME_H


class Game{
	public:
		void init();
		void play();
	private:  
		bool win;
		char player1;
		char player2;
		int turn;
		Board* b;
  
};

#endif