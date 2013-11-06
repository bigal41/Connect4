#include <iostream>
#include <string>
#include <stdlib.h>

#include "Board.h"

using namespace std;

int Board::getWidth(){return bWidth;}
int Board::getHeight(){return bHeight;}
char Board::getBoardPiece(int x,int y){return boardArray[x][y]; }
char Board::setBoardPiece(int x,int y,char player){ boardArray[x][y] = player; }


Board::Board(){
	boardArray =(char**) malloc(bHeight* sizeof(char *));
	int x, y;
	
	for(x = 0; x < bHeight; x++)
		boardArray[x] = (char*) malloc(bWidth * sizeof(char *));
	
	
	for(x = 0; x < bHeight; x++){
		for(y = 0; y < bWidth; y++){
			boardArray[x][y] = 'O';
		}
	}
}

void Board::printBoard(){
	int x, y;

	cout << "\t0\t1\t2\t3\t4\t5\t6\n";
	for(x = 0; x < bHeight; x++){
		cout << x <<"\t";
		for(y = 0; y < bWidth; y++){
			cout << boardArray[x][y]<<"\t";
			
		}
		cout<<endl;
		cout<<"\t-------------------------------------------------\n";
	}
}

