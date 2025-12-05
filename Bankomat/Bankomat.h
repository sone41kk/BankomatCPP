#pragma once
#include "Banknotes.h"

class Bankomat
{
	Banknotes banknotes = Banknotes(0, 0, 0, 0, 0, 0);
public:
	Bankomat(int b5000, int b2000, int b1000, int b500, int b200, int b100);
	void LoadBanknotes(int b5000, int b2000, int b1000, int b500, int b200, int b100);
	void Deconstruct(int& b5000, int& b2000, int& b1000, int& b500, int& b200, int& b100);
	Banknotes giveCash(int cash);
};

