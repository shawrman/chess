#include "Board.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Pawn.h"

#define ROWS 8
#define COLM 8



Piece* Board::createPieace(char type, int* postion)

{
	
	switch(type)
	{
	case 'K':
		wKing = new King(type, postion);
		return wKing;
		break;
	case 'Q':
		return new Queen(type, postion);
		break;
	case 'N':
		return new Knight(type, postion);
		break;
	case 'P':

		return new Pawn(type, postion);
		break;
	case 'B':
		
		return new Bishop(type, postion);
		break;
	case 'R':
		return new Rook(type, postion);
		break;


	case 'k':
	
		return new King(type, postion);
		break;
	case 'q':
		return new Queen(type, postion);
		break;
	case 'n':
		return new Knight(type, postion);
		break;
	case 'p':
		return new Pawn(type, postion);
		break;
	case 'b':
		return new Bishop(type, postion);
		break;
	case 'r':
		
		return new Rook(type, postion);
		break;

	default:
		return NULL;

		break;
	}
}

Board::Board(std::string setup)
{
	curTurn = true;
	int i = 0;
	int j = 0;
	int flag = 0;
	board = (Piece***)calloc(ROWS, sizeof(Piece**));
	bboard = (Piece***)calloc(ROWS, sizeof(Piece**));
	for (int i = 0; i < ROWS; i++)
	{
		board[i] = (Piece**)calloc(COLM, sizeof(Piece*));
		bboard[i] = (Piece**)calloc(COLM, sizeof(Piece*));

		for (int j = 0; j < COLM; j++)
		{
			board[i][j] = (Piece*)calloc(ROWS, sizeof(Piece));
			bboard[i][j] = (Piece*)calloc(ROWS, sizeof(Piece));
		}
	}
	for (i = 0; i < ROWS; ++i)
	{
		for (j = 0; j < COLM; ++j)
		{
			board[j][i] = createPieace(setup[flag],new int[j,i]);
			if (board[j] != NULL && board[j][i] != NULL &&( board[j][i]->getType() == 'k' || board[j][i]->getType() == 'K'))
			{
				board[j][i]->isChecking(this);
			}
			bboard[j][i] = board[j][i];
			flag++;
		}
	}
	
}

void Board::clear()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; ++i)
	{
		for (j = 0; j < COLM; ++j)
		{

			delete board[i][j];
		}
	}	 

}

void Board::print()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; ++i)
	{
		for (j = 0; j < COLM; ++j)
		{
			if (board[j][i] != NULL)
			{
				std::cout << board[j][i]->getType() << "  ;  ";

			}
			else
			{
				std::cout << "#" << "  ;  ";
			}
		}
		std::cout << std::endl;
	}
}
void Board::update()
{
	int i = 0;
	int j = 0;
	wKing->checked = false;
	bKing->checked = false;

	for (i = 0; i < ROWS; ++i)
	{
		for (j = 0; j < COLM; ++j)
		{
			if (board[i] != NULL && board[i][j] != NULL)
			{
				board[i][j]->setPostion(i,j);
				if (board[i][j]->isChecking(this))
				{
					if (std::isupper(board[i][j]->getType()))
					{
						bKing->checked = true;

					}
					else
					{
						wKing->checked = true;

					}
				}
			}
			
		}
	}
}

int Board::tryMove(int* pos,bool color)
{

	if (pos[0] < 0 || pos[0] >= 8 || pos[1] < 0 || pos[1] >= 8)
	{
		return 3;
	}
	if (board[pos[0]][pos[1]] == NULL)
	{
		
		return 0;
	}
	if (std::isupper(board[pos[0]][pos[1]]->getType()) != color)  //not same color
	{
		if (board[pos[0]][pos[1]]->getType() == 'k' || board[pos[0]][pos[1]]->getType() == 'K')
		{
			return -1;	 //check

		}
		
		return 1;
	}
	if (std::isupper(board[pos[0]][pos[1]]->getType()) == color)   //same color
	{
		if (board[pos[0]][pos[1]]->getType() == 'k' || board[pos[0]][pos[1]]->getType() == 'K')
		{
			return -2; ;

		}

		return 2;
	}
	return 99;
}


void Board::move(int* pos, int* pos1)
{

	board[pos1[0]][pos1[1]] = board[pos[0]][pos[1]];
	board[pos[0]][pos[1]] = NULL;

	
}

