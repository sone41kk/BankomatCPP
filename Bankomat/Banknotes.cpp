#include "Banknotes.h"


Banknotes::Banknotes(int a, int b, int c, int d, int e, int f)
{
	this->dengi5000 = a;this->dengi2000 = b;
	this->po_tysyache = c;this->patsot = d;
	this->dvesti = e;this->sto = f;
}

void Banknotes::Load(int a, int b, int c, int d, int e, int f)
{	this->dengi5000 += a;	this->dengi2000 += b;	this->po_tysyache += c;	this->patsot += d;	this->dvesti += e;
	this->sto += f;
}