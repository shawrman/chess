#pragma once
#include <iostream>
#include <string>
#include "Board.h"

class Board;
class Piece
{
protected:
	char _type;
	int* _postion;

public:

	const int goodMove = 0, checkOpponent = 1, noPieceSrc = 2, therePieceDst = 3, checkCurrentPlayer = 4, invalidIndex = 5, invalidMovement = 6, identicalChecker = 7, chess = 8;

	//constructor
	Piece(const char type, int* postion);
	Piece() = default;

	//destructor
	virtual ~Piece() = default;

	//getters
	char getType() const;
	int* getPostion() const;
	void setPostion(int x,int y);
	//method
	virtual int move(int* postion,Board* board) = 0 ;
	virtual int** legelMoves(int* postion, Board* board) = 0;
	virtual bool isChecking(Board* board) = 0;

	
};
