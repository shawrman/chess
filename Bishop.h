#pragma once
#include "Piece.h"
class Piece;
class Board;
class Bishop : public Piece
{
public:
	// Constructor
	Bishop(char type, int* postion);
	Bishop() = default;

	// Destructor
	virtual ~Bishop() = default;

	//method
	virtual int move(int* postion,Board* board);
	virtual int** legelMoves(int* postion, Board* board);
	virtual bool isChecking(Board* board);
};