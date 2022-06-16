#include "Pawn.h"

Pawn::Pawn(char type, int* postion) :
    Piece(type, postion), _playedAiready(false)
{

}

bool Pawn::getPlayedAiready() const
{
    return _playedAiready;
}

void Pawn::setPlayedAiready(const bool playedAiready)
{
    _playedAiready = playedAiready;
}

int Pawn::move(int* postion,Board* board)
{
    if (postion[0] > 8 || postion[1] > 8)
    {
        return invalidIndex;
    }
    else if (postion[0] == _postion[0] && postion[1] == _postion[1])
    {
        return identicalChecker;
    }
    else  if (board->tryMove(postion,std::isupper(_type)) == 2 )
    {
        return therePieceDst;
    }
    else
    {

    

        if (!getPlayedAiready())
        {
            if (std::isupper(_type))
            {
                if (postion[1] == (1 + _postion[1]) &&
                    (postion[0] - _postion[0] == 1 || postion[0] - _postion[0] == -1) &&
                    (board->tryMove(postion, std::isupper(_type)) == 1))
                {
                    setPlayedAiready(true);
                    return goodMove;

                }
                else if(postion[0] == _postion[0] &&  postion[1] == (2 + _postion[1]) && board->tryMove(postion, std::isupper(_type)) == 0)
                {
                    setPlayedAiready(true);
                    return goodMove;
                }
                else if (postion[0] == _postion[0] && postion[1] == (1 + _postion[1]) && board->tryMove(postion, std::isupper(_type)) == 0)
                {
                    setPlayedAiready(true);
                    return goodMove;
                }
                else
                {
                    return invalidMovement;
                }
            }
            else
            {

                if (postion[1] == (1 + _postion[1]) &&
                    (postion[0] - _postion[0] == 1 || postion[0] - _postion[0] == -1) &&
                    ( board->tryMove(postion, std::isupper(_type)) == 1))
                {
                    setPlayedAiready(true);
                    return goodMove;

                }
                else if (postion[1] == (-2 + _postion[1]) && postion[0] ==_postion[0] && board->tryMove(postion, std::isupper(_type)) == 0)
                {
                    setPlayedAiready(true);
                    return goodMove;
                }
                else if ( postion[1] == (-1 + _postion[1]) && postion[0] == _postion[0] && board->tryMove(postion, std::isupper(_type)) == 0)
                {
                    setPlayedAiready(true);
                    return goodMove;
                }
                else
                {
                    return invalidMovement;
                }
            }
          
        }
        else if (getPlayedAiready())
        {
            if (std::isupper(_type))
            {
               
                if (postion[1] == (1 + _postion[1]) &&
                    (postion[0] - _postion[0] == 1 || postion[0] - _postion[0] == -1) &&
                    (board->tryMove(postion, std::isupper(_type)) == 1))
                {
                    return goodMove;

                }
                else if (postion[0] == _postion[0] && postion[1] == (1 + _postion[1]) && board->tryMove(postion, std::isupper(_type)) == 0)
                {
                      
                    return goodMove;
                }
                  
                return invalidMovement;
                          
            }
            else
            {
               

                if (postion[1] == (- 1 + _postion[1]) &&
                    (postion[0] - _postion[0] == 1 || postion[0] - _postion[0] == -1) &&
                    ( board->tryMove(postion, std::isupper(_type)) == 1))
                {
                    return goodMove;

                }
                else if (postion[0] == _postion[0] && postion[1] == (-1 + _postion[1]) && board->tryMove(postion, std::isupper(_type)) == 0)
                {

                    return goodMove;
                }

                return invalidMovement;
                
            }
        }
       

         
            return goodMove;
     
    }
}

bool Pawn::isChecking(Board* board)
{
    int pos[2] = { _postion[0],_postion[1] };
    if (std::isupper(_type))
    {
        pos[0]++;
       
    }
    else
    {
        pos[0]--;

    }
    pos[1]++;
    if (board->tryMove(pos, std::isupper(_type)) == -1)
    {
        return true;
    }
    pos[1] -= 2;
    if (board->tryMove(pos, std::isupper(_type)) == -1)
    {
        return true;
    }
    return false;
}

int** Pawn::legelMoves(int* postion, Board* board)
{
    return nullptr;
}
