#pragma once
#include "Piece.h"
class Piece;
class Board;
class Rook : public Piece
{
public:
	// Constructor
	Rook(const char type, int* postion);
	Rook() = default;

	// Destructor
	virtual ~Rook() = default;

	//method
	virtual int move(int* postion,Board* board);

	virtual int** legelMoves(int* postion, Board* board);
	virtual bool isChecking(Board* board);
	
};
