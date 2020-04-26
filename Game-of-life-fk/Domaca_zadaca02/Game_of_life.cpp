#include "Game_of_life.h"
#include <iostream>
#include <time.h>

bool Game_of_life::slucajna_vrijednost()
{
	//srand(time(NULL));
	int randNum = rand() % 4;


	if (randNum==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Game_of_life::celija_zauzeta(int i, int j)
{
	if (_generacija[i][j] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

int Game_of_life::broj_susjeda(bool _generacija[REDAKA][STUPACA], int x, int y)
{
	int sum = 0;
	/*for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			int REDAKA = (y + j + 20) % 20;
			int STUPACA = (x + i + 40) % 40;
			if (_generacija[i][j] == true)
			{
				sum++;
			}
		}
	}
	sum -= _generacija[x][y];*/
	if (!(x == 0 || y == 0)&&_generacija[y - 1][x - 1] == true)
	{
		sum ++;
	}
	if (!(x == 0) && _generacija[y][x - 1] == true)
	{
		sum ++;
	}
	if (!(x == 0 || y == STUPACA - 1)&&_generacija[y + 1][x - 1] == true)
	{
		sum ++;
	}
	if (!(y == 0) && _generacija[y - 1][x] == true)
	{
		sum ++;
	}
	if (!(y == STUPACA - 1) && _generacija[y + 1][x] == true)
	{
		sum ++;
	}

	if (!(x == REDAKA - 1 || y == 0) && _generacija[y - 1][x + 1] == true)
	{
		sum ++;
	}
	if (!(x == REDAKA - 1) && _generacija[y][x + 1] == true)
	{
		sum ++;
	}
	if (!(x == REDAKA - 1 || y == STUPACA - 1) && _generacija[y + 1][x + 1] == true)
	{
		sum ++;
	}

	return sum;
}

Game_of_life::Game_of_life()
{
	srand(time(nullptr));
	for (unsigned i = 0; i < REDAKA; i++) {
		for (unsigned j = 0; j < STUPACA; j++) {
			this->_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void Game_of_life::sljedeca_generacija()
{

	for (unsigned i = 0; i < REDAKA; i++) {
		for (unsigned j = 0; j < STUPACA; j++) {
			bool stanje = celija_zauzeta(i, j);

			int okolina = broj_susjeda(_generacija, i, j);

			if (stanje == false && okolina == 3) {
				_sljedeca_generacija[i][j] = true;
			}
			else if (stanje == true && (okolina < 2 || okolina > 3)) {
				_sljedeca_generacija[i][j] = false;
			}
			else {
				_sljedeca_generacija[i][j] = stanje;
			}

		}
	}
	for (unsigned i = 0; i < REDAKA; i++) {
		for (unsigned j = 0; j < STUPACA; j++) {
			this->_generacija[i][j] = this->_sljedeca_generacija[i][j];
		}
	}

}


void Game_of_life::iscrtaj()
{
	for (unsigned i = 0; i < REDAKA; i++) {
		for (unsigned j = 0; j < STUPACA; j++) {
			if (this->_generacija[i][j] == true)
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
			
}
