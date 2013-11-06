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
	
	do{
		b->printBoard();git
		piece = getMove();
		place = checkPiece(piece);
		if(place != -1 && turn%2 == 0)
			b->setBoardPiece(place,piece,player1);
		if(place != -1 && turn%2 != 0)
			b->setBoardPiece(place,piece,player2);
		
		
		if(turn == 5)
			break;
		turn++;
		
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

int Game::checkPiece(int piece){
	
	for(int i = (b->getHeight()-1); i >= 0; i--){
			if(b->getBoardPiece(i,piece) == 'O')
				
				return i;
	}
	return -1;
}

bool Game::checkHorz(){
	return false;
}

bool Game::checkVert(){
	return false;
}
	
