#pragma once
#include "piece.h"
class Piece;
class Board;
class Knight : public Piece
{
public:
	Knight(char type, int* postion);
	virtual ~Knight() {}

	virtual int move(int* postion, Board* board);
	int** legelMoves(int* postion, Board* board);
	bool isChecking(Board* board);
};

