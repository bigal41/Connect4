#ifndef BOARD_H
#define BOARD_H


class Board{
	public:
		int getWidth();
		int getHeight();
		Board();
		void printBoard();
	private:
		int bWidth = 7;
		int bHeight = 6;
		char** boardArray;
		
};

#endif