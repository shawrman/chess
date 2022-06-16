#pragma once
#include "Piece.h"
class Piece;
class Board;
class Queen :  public Piece
{
public:
	Queen(char type, int* postion);
	virtual ~Queen() {}
	virtual int move(int* postion, Board* board);
	virtual int** legelMoves(int* postion, Board* board);
	virtual bool isChecking(Board* board);

};

