#pragma once
#include "Piece.h"
class Piece;
class Board;
class King :
    public Piece
{
private:
    
public:
    King(char type,int* postion); 
    bool checked;
    virtual ~King() = default;
    virtual int move(int* postion, Board* board);
    virtual int** legelMoves(int* postion, Board* board);
    virtual bool isChecking(Board* board);
};

