#include <iostream>
#include <string>

#include "Game.h"

using namespace std;

void Game::init(){
	b = new Board();
	turn = 0;
	char player[2] = {'A','B'};
	player1 = 'A';
	player2 = 'B';
	win = false;
}

void Game::play(){
	init();
	
	
	do{
		b->printBoard();
		
		piece = getMove();
		place = checkPiece(piece);
		if(place != -1 && turn%2 != 0){
			b->setBoardPiece(place,piece,player2);
		}
		if(place != -1 && turn%2 == 0)
			b->setBoardPiece(place,piece,player1);
		if(place == -1)
			continue;
		
		cout << "Turn: " << turn << endl;
		if(turn >= 6){
			if(turn%2 != 0){
				win = checkHorz(place,piece,player2);
				
				if(win == true)
					break;

				win = checkVert(place,piece,player2);
				
				if(win == true)
					break;
			}
			if(turn%2 == 0){
 				win = checkHorz(place,piece,player1);
 				if(win == true)
 					break;
				win = checkVert(place,piece,player1);
				if(win == true)
					break;
			}
		}
		
		if(turn == 25)
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
	cout << "There is no room in that column." << endl;
	return -1;
}

bool Game::checkHorz(int row, int column, char player){
	int samePlayer = 0;
	int pos;
	switch(column){
		case 0:
			for(int check = column; check <= column + 3; check++){
				if(b->getBoardPiece(row,check) != player)
					samePlayer = 0;
				else
					samePlayer++;
					
				if(samePlayer == 4)
					return true;
			}
			break;
		case 1:
			for(int check = column - 1; check <= column + 3; check++){
				if(b->getBoardPiece(row,check) != player)
					samePlayer = 0;
				else
					samePlayer++;
					
				if(samePlayer == 4)
					return true;
			}
			break;
		case 2:
			for(int check = column - 2; check <= column + 3; check++){
				if(b->getBoardPiece(row,check) != player)
					samePlayer = 0;
				else
					samePlayer++;
					
				if(samePlayer == 4)
					return true;
			}
			break;
		case 3:
			for(int check = column - 3; check <= column + 3; check++){
				cout<<"Col: "<<column<<" Row: "<<check<<" Player: "<<b->getBoardPiece(row,check)<<endl;
				if(b->getBoardPiece(row,check) != player)
					samePlayer = 0;
				else
					samePlayer++;
					
				if(samePlayer == 4)
					return true;
			}
			break;
		case 4:
			for(int check = column - 3; check <= column + 2; check++){
				if(b->getBoardPiece(row,check) != player)
					samePlayer = 0;
				else
					samePlayer++;
					
				if(samePlayer == 4)
					return true;
			}
			break;
		case 5:
			for(int check = column - 3; check <= column + 1; check++){
				if(b->getBoardPiece(row,check) != player)
					samePlayer = 0;
				else
					samePlayer++;
					
				if(samePlayer == 4)
					return true;
			}
			break;
		case 6:
			for(int check = column - 3; check <= column; check++){
				if(b->getBoardPiece(row,check) != player)
					samePlayer = 0;
				else
					samePlayer++;
					
				if(samePlayer == 4)
					return true;
			}
			break;
	}
	return false;
}

bool Game::checkVert(int row,int column,char player){
		int pos = row + 3;
		if(row <= 2){
			for(int check = row; check <= pos; check++){
				if(b->getBoardPiece(check,column) != player)
					return false;
			}
			return true;
		}
		else
			return false;
}
	
