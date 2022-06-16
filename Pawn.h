#pragma once
#include "Piece.h"
class Pawn : public Piece
{
private:
	bool _playedAiready;
public:

	// Constructor
	Pawn(char type, int* postion);
	Pawn() = default;

	// Destructor
	virtual ~Pawn() = default;

	//getters
	bool getPlayedAiready() const;

	//setters
	void setPlayedAiready(const bool playedAiready);

	//method
	virtual int move(int* postion, Board* board);
	virtual bool isChecking(Board* board);
	virtual int** legelMoves(int* postion, Board* board);

};