#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows

class Banknotes
{
public:	
	int dengi5000;int dengi2000;int po_tysyache;int patsot;int dvesti;int sto;

	Banknotes(int a, int b, int c, int d, int e, int f);

	void Load(int a, int b, int c, int d, int e, int f);
};