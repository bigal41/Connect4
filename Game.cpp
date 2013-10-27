#include <iostream>
#include <string>

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

		placedPieced = getMove();
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

int Game::getMove(){
	int piece;
	cout << "Please specify where you want to place your piece\n";
	cin >> piece;
	return piece;
}

bool Game::checkHorz(){
	return false;
}

bool Game::checkVert(){
	return false;
}
	
