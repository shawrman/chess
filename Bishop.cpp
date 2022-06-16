#include "Bishop.h"
#include "Board.h"
Bishop::Bishop(char type, int* postion) :
    Piece(type, postion)
{
}
int Bishop::move(int* postion, Board* board)
{
    int i = 0;

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
    else
    {
        
        int** legelMove = legelMoves(_postion, board);
        for (i = 0; i < 13; i++)
        {
            if (legelMove[i][0] == postion[0] && legelMove[i][1] == postion[1])
            {
                return goodMove;
                break;
            }
        }
        return  invalidMovement;
    }
}

int** Bishop::legelMoves(int* postion, Board* board)
{
    int** legelMove;
    int i = 0, flag = 0;
    int pos[2] = { 0 };
    legelMove = (int**)calloc(8, sizeof(int*));
    for (i = 0; i < 13 ;i++)
    {
        legelMove[i] = (int*)calloc(2, sizeof(int));

    }
    bool rowsN = true, rowsP = true, colN = true, colP = true;
    for (i = 1; i < 8; i++)
    {
        pos[0] =_postion[0] + i;
        pos[1] = postion[1] + i;
        if (rowsN && (board->tryMove(pos, std::isupper(_type)) == 0 || board->tryMove(pos, std::isupper(_type)) == 1))
        {
            legelMove[flag][0] =pos[0];
            legelMove[flag][1] = pos[1];
            flag++;
            if (board->tryMove(pos, std::isupper(_type)) == 1)
            {
                rowsN = false;

            }
        }        
        else
        {
            rowsN = false;
        }

         
        pos[0] = postion[0] + i;
        pos[1] = postion[1] - i;

        if (rowsP && (board->tryMove(pos, std::isupper(_type)) == 0 || board->tryMove(pos, std::isupper(_type)) == 1))
        {
            legelMove[flag][0] = pos[0];
            legelMove[flag][1] = pos[1];
            flag++;
            if (board->tryMove(pos, std::isupper(_type)) == 1)
            {
                rowsP = false;

            }
        }      
        else
        {
            rowsP = false;
        }

        
        pos[0] = postion[0] - i;
        pos[1] = postion[1] + i;
        if (colN && (board->tryMove(pos, std::isupper(_type)) == 0 || board->tryMove(pos, std::isupper(_type)) == 1))
        {
            legelMove[flag][0] = pos[0];
            legelMove[flag][1] = pos[1];
            flag++;
            if (board->tryMove(pos, std::isupper(_type)) == 1)
            {
                colN = false;

            }
        }
        else
        {
            colN = false;
        }


        pos[0] = postion[0] - i;
        pos[1] = postion[1] - i;

        if (colP && (board->tryMove(pos, std::isupper(_type)) == 0 || board->tryMove(pos, std::isupper(_type)) == 1))
        {
            legelMove[flag][0] = pos[0];
            legelMove[flag][1] = pos[1];
            flag++;
            if (board->tryMove(pos, std::isupper(_type)) == 1)
            {
                colP = false;

            }
        }
        else
        {
            colP = false;
        }
     


    }
    return legelMove;
}

bool Bishop::isChecking(Board* board)
{

    int i = 0;
    int pos[2] = { 0 };
   
    bool rowsN = true, rowsP = true, colN = true, colP = true;
    for (i = 1; i < 8; i++)
    {
        pos[0] = _postion[0] + i;
        pos[1] = _postion[1] + i;
        if (rowsN && board->tryMove(pos, std::isupper(_type)) == 0 || board->tryMove(pos, std::isupper(_type)) == 1)
        {
     
            if (board->tryMove(pos, std::isupper(_type)) == 1)
            {
                rowsN = false;

            }
        }
        else  if (rowsN)
        {
            if (board->tryMove(pos, std::isupper(_type)) == -1)
            {
                return true;
            }
            rowsN = false;
        }


        pos[0] = _postion[0] + i;
        pos[1] = _postion[1] - i;

        if (rowsP && board->tryMove(pos, std::isupper(_type)) == 0 || board->tryMove(pos, std::isupper(_type)) == 1)
        {
     
            if (board->tryMove(pos, std::isupper(_type)) == 1)
            {
                rowsP = false;

            }
        }
        else  if(rowsP)
        {
            if (board->tryMove(pos, std::isupper(_type)) == -1)
            {
                return true;
            }
            rowsP = false;
        }


        pos[0] = _postion[0] - i;
        pos[1] = _postion[1] + i;
        if (colN && board->tryMove(pos, std::isupper(_type)) == 0 || board->tryMove(pos, std::isupper(_type)) == 1)
        {
          
            if (board->tryMove(pos, std::isupper(_type)) == 1)
            {
                colN = false;

            }
        }
        else if (colN)
        {
            if (board->tryMove(pos, std::isupper(_type)) == -1)
            {
                return true;
            }
            colN = false;
        }


        pos[0] = _postion[0] - i;
        pos[1] = _postion[1] - i;

        if (colP && board->tryMove(pos, std::isupper(_type)) == 0 || board->tryMove(pos, std::isupper(_type)) == 1)
        {
         
            if (board->tryMove(pos, std::isupper(_type)) == 1)
            {
                colP = false;

            }
        }
        else   if (colP)
        {
            if (board->tryMove(pos, std::isupper(_type)) == -1)
            {
                return true;
            }
            colP = false;
        }



    }
    return false;
}
