#include "Banknotes.h"


Banknotes::Banknotes(int cash5000, int cash2000, int cash1000, int cash500, int cash200, int cash100) :
	cash5000(cash5000),
	cash2000(cash2000),
	cash1000(cash1000),
	cash500(cash500),
	cash200(cash200),
	cash100(cash100)
{}

void Banknotes::Load(int cash5000, int cash2000, int cash1000, int cash500, int cash200, int cash100)
{
	this->cash5000 += cash5000;
	this->cash2000 += cash2000;
	this->cash1000 += cash1000;
	this->cash500 += cash500;
	this->cash200 += cash200;
	this->cash100 += cash100;
}