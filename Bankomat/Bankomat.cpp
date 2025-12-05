#include "Bankomat.h"

Bankomat::Bankomat(int b5000, int b2000, int b1000, int b500, int b200, int b100)
{
	banknotes.Load(b5000, b2000, b1000, b500, b200, b100);
}

void Bankomat::LoadBanknotes(int b5000, int b2000, int b1000, int b500, int b200, int b100)
{
	banknotes.Load(b5000, b2000, b1000, b500, b200, b100);
}

void Bankomat::Deconstruct(int& b5000, int& b2000, int& b1000, int& b500, int& b200, int& b100)
{
	b5000 = banknotes.cash5000;
	b2000 = banknotes.cash2000;
	b1000 = banknotes.cash1000;
	b500 = banknotes.cash500;
	b200 = banknotes.cash200;
	b100 = banknotes.cash100;
}

Banknotes Bankomat::giveCash(int count)
{
    if (count <= 0) return Banknotes(0, 0, 0, 0, 0, 0);
    Banknotes tmp = banknotes;
    int nominal[6] = { 5000, 2000, 1000, 500, 200, 100 }; // массив, содержащий доступные номиналы
    int counts[6] = { 0, 0, 0, 0, 0, 0 };

    int* available[6] = { &tmp.cash5000, &tmp.cash2000, &tmp.cash1000, &tmp.cash500, &tmp.cash200, &tmp.cash100 }; // массив указателей на значение купюр

    for (int i = 0; i < 6 && count; i++) {
        counts[i] = count / nominal[i];
        if (counts[i] > 0)
        {
            counts[i] = (*available[i] >= counts[i]) ? counts[i] : *available[i]; // проверка на количество доступных банкнот
            count -= counts[i] * nominal[i]; // изменение "баланса"
            *available[i] -= counts[i];
        }
    }
    if (count == 0)
    {
        banknotes = tmp;
        return Banknotes(counts[0], counts[1], counts[2], counts[3], counts[4], counts[5]); // возвращаем остаток купюр
    }
}
    /*b[i] = cash / 5000;
    if (b[0] > 0)
    {
        b[0] = tmp.cash5000 >= b[0] ? b[0] : tmp.cash5000;
        cash -= b[0] * 5000;
        tmp.cash5000 -= b[0];
    }

    b[1] = cash / 2000;
    if (b[1] > 0)
    {
        b[1] = tmp.cash2000 >= b[1] ? b[1] : tmp.cash2000;
        cash -= b[1] * 2000;
        tmp.cash2000 -= b[1];
    }

    b[2] = cash / 1000;
    if (b[2] > 0)
    {
        b[2] = tmp.cash1000 >= b[2] ? b[2] : tmp.cash1000;
        cash -= b[2] * 1000;
        tmp.cash1000 -= b[2];
    }

    b[3] = cash / 500;
    if (b[3] > 0)
    {
        b[3] = tmp.cash500 >= b[3] ? b[3] : tmp.cash500;
        cash -= b[3] * 500;
        tmp.cash500 -= b[3];
    }
    b[4] = cash / 200;
    if (b[4] > 0)
    {
        b[4] = tmp.cash200 >= b[4] ? b[4] : tmp.cash200;
        cash -= b[4] * 200;
        tmp.cash200 -= b[4];
    }

    b[5] = cash / 100;
    if (b[5] > 0)
    {
        b[5] = tmp.cash100 >= b[5] ? b[5] : tmp.cash100;
        cash -= b[5] * 100;
        tmp.cash100 -= b[5];
    }

    if (cash == 0)
    {
        banknotes = tmp;
        return Banknotes(b[0], b[1], b[2], b[3], b[4], b[5]);
    }
    return Banknotes(0, 0, 0, 0, 0, 0);
}*/