#include "controller.h"
#include "King.h"

Controller::Controller()
{
	m_board = new Board("RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr1");

}

Controller::~Controller()
{
	delete m_board;
}

void Controller::run()
{
	std::string str;
	int** translated;
	int pos1[2];
	int pos2[2];
	int mode = 0;
	bool color = true;
	m_board->print();
	while (true)
	{
		if (color == true)
		{
			std::cout << "The White Actor's Turn" << std::endl;
		}
		else
		{
			std::cout << "The Black Actor's Turn" << std::endl;
		}

		std::cout << "Please enter a motion string" << std::endl;
		std::cin >> str;
		if (str.length() == 4)
		{
			translated = translate(str);
			pos1[0] = translated[0][0];
			pos1[1] = translated[0][1];
			pos2[0] = translated[1][0];
			pos2[1] = translated[1][1];
		}
		else
		{
			pos1[0] = 9;

		}
		if (pos1[0] >= 8 || pos1[0] < 0 ||
			pos1[1] >= 8 || pos1[1] < 0 ||
			pos2[0] >= 8 || pos2[0] < 0 ||
			pos2[1] >= 8 || pos2[1] < 0 )
		{
			mode = -1;
		}
		else
		{
			m_board->update();
			mode = -1;
			if (m_board->board[pos1[0]][pos1[1]])
			{
				mode = m_board->board[pos1[0]][pos1[1]]->move(pos2, m_board);

			}
		}
		

		if (mode == 0 && std::isupper(m_board->board[pos1[0]][pos1[1]]->getType()) == color )
		{
			Piece* temp = m_board->board[pos2[0]][pos2[1]];
			m_board->move(pos1, pos2);
			m_board->update();
			if (std::isupper(m_board->board[pos2[0]][pos2[1]]->getType()))
			{
				if (m_board->wKing->checked)
				{
					m_board->move(pos2, pos1);

					m_board->board[pos2[0]][pos2[1]] = temp;
					std::cout << "error!!" << std::endl;

			    }
				else
				{
					m_board->print();
					color = !color;
				}
			}
			else
			{
				if (m_board->bKing->checked)
				{
					m_board->move(pos2, pos1);

					m_board->board[pos2[0]][pos2[1]] = temp;
					std::cout << "error!!" << std::endl;
				}
				else
				{
					m_board->print();
					color = !color;

				}
			}
			
		}
		else
		{
			std::cout << "error!!" << std::endl;
		}
	}
}

Board* Controller::getBoard()
{
	return m_board;
}

int** Controller::translate(std::string input)
{
	
	int i = 0;
	int flag = 0;
	int** translated;
	translated = (int**)calloc(2, sizeof(int*));
	for (int j = 0; j < 2; j++)
	{
		translated[j] = (int*)calloc(2, sizeof(int));
	}
	for (i = 0; i < 4; i += 2)
	{

		translated[flag][0] = input[i] - CH_TO_INT;
		translated[flag][1] = input[i + 1] - INT_TO_INT;
		flag++;
	}
	if (input.size() != 4 )
	{
		translated[0][0] = 99;

	}
	return translated;

}
