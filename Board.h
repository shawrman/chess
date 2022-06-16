#pragma once
#include <iostream>
#include "Piece.h"
class Piece;
class King;
class Board
{
private:
	bool curTurn;
	
public:
	King* bKing;
	King* wKing;

	Piece*** board;
	Piece*** bboard;
	Board(std::string setup);
	Piece* createPieace(char type, int* postion);
	void clear();
	void print();
	void update();
	int tryMove(int* pos, bool color);
	void move(int* pos, int* pos1);
	
};

