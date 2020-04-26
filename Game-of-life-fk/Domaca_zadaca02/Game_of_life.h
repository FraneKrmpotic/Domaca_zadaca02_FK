#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	bool celija_zauzeta(int i, int j);
	int broj_susjeda(bool _generacija[REDAKA][STUPACA], int x, int y);

public:
	Game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};


