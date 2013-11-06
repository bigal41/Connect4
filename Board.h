#ifndef BOARD_H
#define BOARD_H


class Board{
	public:
		int getWidth();
		int getHeight();
		char getBoardPiece(int,int);
		char setBoardPiece(int,int,char);
		Board();
		void printBoard();
	private:
		int bWidth = 7;
		int bHeight = 6;
		char** boardArray;
		
};

#endif