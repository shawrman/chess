#include "Queen.h"

Queen::Queen(char type, int* postion) :
    Piece(type, postion)
{
}

int Queen::move(int* postion, Board* board)
{
    return 0;
}

int** Queen::legelMoves(int* postion, Board* board)
{
    board->update();
    int pos[2] = { 0 };
    int i = 0;
    int** legelMove;
    legelMove = (int**)calloc(30, sizeof(int*));
    for (i = 0; i < 30; i++)
    {
        legelMove[i] = (int*)calloc(2, sizeof(int));

    }

    int flag = 0;
    bool rowsN = true, rowsP = true, colN = true, colP = true;
    for (i = 1; i < 8; i++)
    {
        pos[0] = _postion[0] - i;
        pos[1] = _postion[1];
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
        pos[0] = _postion[0] + i;
        pos[1] = postion[1] + i;
        if (rowsN && (board->tryMove(pos, std::isupper(_type)) == 0 || board->tryMove(pos, std::isupper(_type)) == 1) )
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


        pos[0] = postion[0] + i;
        pos[1] = postion[1] - i;

        if (rowsP &&( board->tryMove(pos, std::isupper(_type)) == 0 || board->tryMove(pos, std::isupper(_type)) == 1)    )
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
        if (colN && (board->tryMove(pos, std::isupper(_type)) == 0 || board->tryMove(pos, std::isupper(_type)) == 1) )
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

        if (colP && (board->tryMove(pos, std::isupper(_type)) == 0 || board->tryMove(pos, std::isupper(_type)) == 1) )
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

bool Queen::isChecking(Board* board)
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
        else if (rowsN)
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
        else  if (rowsP)
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
        else  if (colN)
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
        else  if (colP)
        {
            if (board->tryMove(pos, std::isupper(_type)) == -1)
            {
                return true;
            }
            colP = false;
        }

         int pos[2] = { _postion[0] - i,_postion[1] };
        if (rowsN && _postion[0] - i > 0 && board->tryMove(pos, std::isupper(_type)) == -1)
        {
          
             
            return true;

        }
        else if (rowsN && _postion[0] - i > 0 && board->tryMove(pos, std::isupper(_type)) != -0)
        {

            rowsN = false;


        }

        pos[1] = _postion[1] - i;

        pos[0] = _postion[0];
        if (colN && _postion[1] - i > 0 && board->tryMove(pos, std::isupper(_type)) == -1)
        {
             
              return true;

        }
        else if (colN && _postion[1] - i > 0 && board->tryMove(pos, std::isupper(_type)) != -0)
        {

            colN = false;


        }
        pos[0] = _postion[0] + i;
        pos[1] = _postion[1];
        if (rowsP && _postion[0] + i < 8 && board->tryMove(pos, std::isupper(_type)) == -1)
        {
        
             return true;

        }
        else if (rowsP && _postion[0] + i < 8 && board->tryMove(pos, std::isupper(_type)) != -0)
        {

            rowsP = false;


        }

        pos[1] = _postion[1] + i;

        pos[0] = _postion[0];
        if (colN && _postion[1] + i < 8 && board->tryMove(pos, std::isupper(_type)) == -1)
        {
         
             return true;

        }
        else if (colP && _postion[1] + i < 8 && board->tryMove(pos, std::isupper(_type)) != -0)
        {

            colP = false;


        }

    }
    return false;
}
