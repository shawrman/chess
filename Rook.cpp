#include "Rook.h"
#include "Piece.h"
#include "King.h"
class King;
Rook::Rook(char type, int* postion) :
    Piece(type, postion)
{

}

int Rook::move(int* postion, Board* board)
{
    int i = 0;
    int input = 0;
    int myPostion[2] = {};
    bool flag1 = false, flag2 = false;

    /*for (i = 0; i < 8; i++)
    {
        myPostion[0] = postion[0];
        myPostion[1] = i;
        if (board->tryMove(myPostion, std::isupper(_type)) == 2)
        {
            if (postion[1] <= myPostion[1])
            {
                flag1 = true;
            }
            else
            {
                flag1 = false;
            }
        }
    }

    for (i = 0; i < 8; i++)
    {
        myPostion[1] = postion[1];
        myPostion[0] = i;
        if (board->tryMove(myPostion, std::isupper(_type)) == 2)
        {
            if (postion[0] <= myPostion[0])
            {
                flag2 = true;
            }
            else
            {
                flag2 = false;
            }
        }    
    }      */

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
    else if (postion[0] != _postion[0] && postion[1] != _postion[1])
    {
        return invalidMovement;
    }
    
    else
    {

        int** legelMove = legelMoves(_postion,board);
        for (i = 0; i < 14; i++)
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


int** Rook::legelMoves(int* postion,Board* board)
{
    board->update();
    
    int i = 0;
    int** legelMove;
    legelMove = (int**)calloc(14, sizeof(int*));
    for (i = 0; i < 14; i++)
    {
        legelMove[i] = (int*)calloc(2, sizeof(int));
        
    }
    
    int flag = 0;
    bool rowsN = true, rowsP = true, colN = true, colP = true;
    for (i = 1; i < 8; i++)
    {
        int pos[2] = { _postion[0] - i,_postion[1] };
        if (rowsN && _postion[0] - i > 0 && (board->tryMove(pos, std::isupper(_type)) == 1 || board->tryMove(pos, std::isupper(_type)) == 0))
        {
         
            legelMove[flag][0] = pos[0];
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

        pos[1] = _postion[1] - i;

        pos[0] = _postion[0];
        if (colN && _postion[1] - i > 0 && (board->tryMove(pos, std::isupper(_type)) == 1 || board->tryMove(pos, std::isupper(_type)) == 0))
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
        pos[0] = _postion[0] + i;
        pos[1] = _postion[1];
        if (rowsP && _postion[0] + i < 8 && (board->tryMove(pos, std::isupper(_type)) == 1 || board->tryMove(pos, std::isupper(_type)) == 0))
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

        pos[1] = _postion[1] + i;

        pos[0] = _postion[0];
        if (colP && _postion[1] + i < 8 && (board->tryMove(pos, std::isupper(_type)) == 1 || board->tryMove(pos, std::isupper(_type)) == 0))
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

bool Rook::isChecking(Board* board)
{
 
    int i = 0;
    bool rowsN = true, rowsP = true, colN = true, colP = true;
    for (i = 0; i < 8; i++)
    {
        int pos[2] = { _postion[0] - i,_postion[1] };
        if (rowsN && _postion[0] - i > 0 && board->tryMove(pos, std::isupper(_type)) == -1)
        {
            if (std::isupper(_type))
            {
                
                board->bKing->checked = true;
                return true;
            }
            else
            {
                board->wKing->checked = true;
                return true;

            }
        }
        else if (rowsN && _postion[0] - i > 0 && board->tryMove(pos, std::isupper(_type)) != -0)
        {

            rowsN = false;


        }

        pos[1] = _postion[1] - i;

        pos[0] = _postion[0];
        if (colN && _postion[1] - i > 0 && board->tryMove(pos, std::isupper(_type)) == -1)
        {
            if (std::isupper(_type))
            {
                board->bKing->checked = true;
                return true;

            }
            else
            {
                board->wKing->checked = true;
                return true;


            }
        }
        else if (colN && _postion[1] - i > 0 && board->tryMove(pos, std::isupper(_type)) != -0)
        {

            colN = false;


        }
        pos[0] = _postion[0] + i;
        pos[1] = _postion[1];
        if (rowsP && _postion[0] + i < 8 && board->tryMove(pos, std::isupper(_type)) == -1)
        {
            if (std::isupper(_type))
            {
                board->bKing->checked = true;
                return true;

            }
            else
            {
                board->wKing->checked = true;
                return true;


            }
        }
        else if (rowsP && _postion[0] + i < 8 && board->tryMove(pos, std::isupper(_type)) != -0)
        {

            rowsP = false;


        }

        pos[1] = _postion[1] + i;

        pos[0] = _postion[0];
        if (colN && _postion[1] + i < 8 && board->tryMove(pos, std::isupper(_type)) == -1)
        {
            if (std::isupper(_type))
            {
                board->bKing->checked = true;
                return true;

            }
            else
            {
                board->wKing->checked = true;
                return true;


            }
        }
        else if (colP && _postion[1] + i < 8 && board->tryMove(pos, std::isupper(_type)) != -0)
        {

            colP = false;


        }
    }
    if (colP && colN && rowsP && rowsN && std::isupper(_type))
    {
        return false;

    }
    else
    {
        return false;


    }
}


