#include "King.h"

King::King(char type, int* postion) :
    Piece(type, postion)
{

}

int King::move(int* postion,Board* board)
{   
    int i = 0;
    int** legelMove = legelMoves(_postion,board);
    if (postion[0] > 8 || postion[1] > 8)
    {
        return invalidIndex;
    }
    else if (board->tryMove(postion, std::isupper(_type)) == 2)
    {
        return therePieceDst;
    }
    else if (postion[0] == _postion[0] && postion[1] == _postion[1])
    {
        return identicalChecker;
    }
    for (i = 0; i < 8; i++)
    {
        if (legelMove[i][0] == postion[0] && legelMove[i][1] == postion[1])
        {
            return goodMove;
            break;
        }
    }
    return 0;
}


int** King::legelMoves(int* postion ,Board* board)
{
    
    int i = 0,f = 0,t = 0;
  
    int** legelMove;
    legelMove = (int**)calloc(8, sizeof(int*));
    for (i = 0; i < 8; i++)
    {
        legelMove[i] = (int*)calloc(2, sizeof(int));

    }
    for (i = -1; i < 2; i++)
    {
        for (f = 0; f < 2; f++)
        {
            int pos[2] = { _postion[0] + i, _postion[1] + f };
            if (board->tryMove(pos, std::isupper(_type)) < 2)
            {
                if (pos[0] != _postion[0] || pos[1] != _postion[1])
                {
                    legelMove[t] = pos;
                }
                
            }
        }
    }
   
    
    return legelMove;
}

bool King::isChecking(Board* board)
{
    if (std::isupper(_type))
    {
        board->wKing = this;
    }
    else
    {
        board->bKing = this;

    }
    return false;
}
