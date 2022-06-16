#include "Piece.h"


Piece::Piece(const char type, int* postion) :
	_type(type), _postion(postion)
{

}

char Piece::getType() const
{
	return _type;
}

int* Piece::getPostion() const
{
	return _postion;
}

void Piece::setPostion(int x,int y)
{

	_postion[0] =x;
	_postion[1] = y;
}
