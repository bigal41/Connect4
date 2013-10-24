all: hello

hello: main.o Board.o Game.o
	g++ main.o Board.o Game.o -o hello

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp
	g++ -c Game.cpp
	
Board.o: Board.cpp
	g++ -c Board.cpp
	

clean: rm -rf *o hello
