#include <iostream>
#include <string>

#include "Board.h"
#include "Game.h"

using namespace std;

void Game::init(){
	b = new Board();
	player1 = 'A';
	player2 = 'B';
	turn = 0;
	win = false;
}

void Game::play(){
	init();
	int i = 0;
	do{
		if(i == 3){
			win = true;
		}
		else{
			win = false;
		}
		i++;
	}while(win != true);
	
	b->printBoard();
	
	cout<<"I WON; I WON; I WON"<<endl;
}
	