#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows

class Banknotes
{
public:	
	int cash5000, cash2000, cash1000, cash500, cash200, cash100;

	Banknotes(int cash5000, int cash2000, int cash1000, int cash500, int cash200, int cash100);

	void Load(int a, int b, int c, int d, int e, int f);
};