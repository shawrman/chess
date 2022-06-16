#include "Knight.h"

Knight::Knight(char type, int* postion) :
    Piece(type, postion)
{
}

int Knight::move(int* postion, Board* board)
{
    if (postion[0] > 8 || postion[1] > 8)
    {
        return invalidIndex;
    }
    else if (board->tryMove(postion, std::isupper(_type)) == 2 || board->tryMove(postion, std::isupper(_type)) == -2)
    {
        return therePieceDst;
    }
    else if (postion[0] == _postion[0] && postion[1] == _postion[1])
    {
        return identicalChecker;
    }
    else
    {
     
        int i = 0;
        int** legelMove = legelMoves(_postion, board);
        for (i = 0; i < 8; i++)
        {
            if (legelMove[i][0] == postion[0] && legelMove[i][1] == postion[1])
            {
                return goodMove;
                break;
            }
        }
        return  invalidMovement;
    }
    return 0;
}

int** Knight::legelMoves(int* postion, Board* board)
{
    int** legelMove;
    int i = 0, flag = 0;
    legelMove = (int**)calloc(8, sizeof(int*));
    for (i = 0; i < 8; i++)
    {
        legelMove[i] = (int*)calloc(2, sizeof(int));

    }
    legelMove[0][0] = postion[0] + 2;
    legelMove[0][1] = postion[1] + 1;
    legelMove[1][0] = postion[0] + 2;
    legelMove[1][1] = postion[1] - 1;
    legelMove[2][0] = postion[0] - 2;
    legelMove[2][1] = postion[1] + 1;
    legelMove[3][0] = postion[0] - 2;
    legelMove[3][1] = postion[1] - 1;
    legelMove[4][0] = postion[0] + 1;
    legelMove[4][1] = postion[1] + 2;
    legelMove[5][0] = postion[0] + 1;
    legelMove[5][1] = postion[1] - 2;
    legelMove[6][0] = postion[0] - 1;
    legelMove[6][1] = postion[1] + 2;
    legelMove[7][0] = postion[0] - 1;
    legelMove[7][1] = postion[1] - 2;
    for (i = 0; i < 8; i++)
    {
        if (legelMove[i][0] > 8 || legelMove[i][0] < 0 || legelMove[i][1] > 8 || legelMove[i][1] < 0)
        {
            if (board->tryMove(legelMove[i], std::isupper(_type)) == 2)
            {
                legelMove[i][0] = -99;
                legelMove[i][1] = -99;
            }
         

        }
        

    }
    return legelMove;
}

bool Knight::isChecking(Board* board)
{
    int i = 0;
    int** legelMove = legelMoves(_postion, board);
    for (i = 0; i < 8; i++)
    {
        if (board->tryMove(legelMove[i], std::isupper(_type)) == -1)
        {
            return true;
        }
  
    }
    return false;
}

 
