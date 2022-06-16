#pragma once
#include "Board.h"
class Piece;
class King;
#define INT_TO_INT 49
#define CH_TO_INT 97
class Controller
{
protected:
	Board* m_board;
public:
	Controller();
	~Controller();
	void run();
	Board* getBoard();
	int** translate(std::string input);

};
