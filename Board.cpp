#include <iostream>
#include <string>
#include <stdlib.h>

#include "Board.h"

using namespace std;

int Board::getWidth(){return bWidth;}
int Board::getHeight(){return bHeight;}


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
	for(x = 0; x < bHeight; x++){
		for(y = 0; y < bWidth; y++){
			cout << boardArray[x][y]<<"\t";
			
		}
		cout<<endl;
		cout<<"\n------------------------------------------------------------\n";
	}
}

