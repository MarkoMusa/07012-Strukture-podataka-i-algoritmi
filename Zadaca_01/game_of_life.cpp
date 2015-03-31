#include "game_of_life.h"
#include <sstream>
#include <iostream>
#include <ctime>

game_of_life::game_of_life()
{
	int survavialChance = 20;
	int uncaringUniverse = 0;

	srand(time(nullptr));

	for (int i = 0; i < this->REDAKA; ++i)
	{
		for (int j = 0; j < this->STUPACA; ++j)
		{
			uncaringUniverse = rand() % 100;
			if ( uncaringUniverse > survavialChance )
				_generacija[i][j] = false;
			else
			_generacija[i][j] = true;
		}
	}
}


void game_of_life::sljedeca_generacija() 
{

	for (int i = 0; i < this->REDAKA; ++i)
	{
		for (int j = 0; j < this->STUPACA; ++j)
		{
			int count = broj_susjeda(i, j);

			if(_generacija[i][j] == true) 
			{
				if (count == 2 || count == 3) 
					_sljedeca_generacija[i][j] = true;
				else
					_sljedeca_generacija[i][j] = false;
			}
			else
			{
				if (count == 3)
					_sljedeca_generacija[i][j] = true;
				else
					_sljedeca_generacija[i][j] = false;
			}
		}
	}
	 memcpy(_generacija, _sljedeca_generacija, sizeof(_generacija));
}

void game_of_life::iscrtaj() 
{
	system("cls");

	stringstream ss;
	for (int i = 0; i < this->REDAKA; ++i)
	{
		for (int j = 0; j < this->STUPACA; ++j)
		{
			if(_generacija[i][j])
				ss << "#";
			else
				ss << "-";
		}
		ss << endl;
	}
	cout << ss.str();
}

int game_of_life::broj_susjeda(int x, int y)
{
	int count = 0;
	for (int i = x-1; i <= x+1; i++)
	{
		for (int j = y-1; j <= y+1; j++)
		{
			if (celija_zauzeta(i,j))
			{
				count++;
			}
		}
	}
	return count;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if( i < 0 || j < 0 || i >= REDAKA || j >= STUPACA)
		return false;
	return _generacija[i][j];
}