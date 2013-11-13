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
				/*win = checkHorz();
				cout<<"Win: " << win <<endl;
				if(win == true)
					break;
				*/
				win = checkVert(place,piece,player2);
				
				if(win == true)
					break;
			}
			if(turn%2 == 0){
// 				win = checkHorz();
// 				cout<<"Win: " << win <<endl;
// 				if(win == true)
// 					break;
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

bool Game::checkHorz(){
	return false;
}

bool Game::checkVert(int place,int piece,char player){
	cout << "Place: " << place << " Piece: " <<piece<<" player:  "<<player <<endl;
		int pos = place + 3;
		if(place <= 2){
			for(int check = place; check <= pos; check++){
				if(b->getBoardPiece(check,piece) != player){
					cout<<"Check: "<<check<<"Piece: "<<piece<<"Player: "<<b->getBoardPiece(check,piece)<<endl;
					return false;
				}
				cout<<"NOT IFCheck: "<<check<<"Piece: "<<piece<<"Player: "<<b->getBoardPiece(check,piece)<<endl;
			}
			return true;
		}
		else
			return false;
}
	
