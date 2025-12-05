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
	b5000 = banknotes.dengi5000;
	b2000 = banknotes.dengi2000;
	b1000 = banknotes.po_tysyache;
	b500 = banknotes.patsot;
	b200 = banknotes.dvesti;
	b100 = banknotes.sto;
}

Banknotes Bankomat::Vydat_dengi(int nalichnye)
{
    if (nalichnye <= 0) return Banknotes(0,0,0,0,0,0);
    Banknotes tmp = banknotes;
    int b[6] { 0, 0, 0, 0, 0, 0 };

    b[0] = nalichnye / 5000;
    if (b[0] > 0)
    {
        b[0] = tmp.dengi5000 >= b[0] ? b[0] : tmp.dengi5000;
        nalichnye -= b[0] * 5000;
        tmp.dengi5000 -= b[0];
    }

    b[1] = nalichnye / 2000;
    if (b[1] > 0)
    {
        b[1] = tmp.dengi2000 >= b[1] ? b[1] : tmp.dengi2000;
        nalichnye -= b[1] * 2000;
        tmp.dengi2000 -= b[1];
    }

    b[2] = nalichnye / 1000;
    if (b[2] > 0)
    {
        b[2] = tmp.po_tysyache >= b[2] ? b[2] : tmp.po_tysyache;
        nalichnye -= b[2] * 1000;
        tmp.po_tysyache -= b[2];
    }

    b[3] = nalichnye / 500;
    if (b[3] > 0)
    {
        b[3] = tmp.patsot >= b[3] ? b[3] : tmp.patsot;
        nalichnye -= b[3] * 500;
        tmp.patsot -= b[3];
    }
    b[4] = nalichnye / 200;
    if (b[4] > 0)
    {
        b[4] = tmp.dvesti >= b[4] ? b[4] : tmp.dvesti;
        nalichnye -= b[4] * 200;
        tmp.dvesti -= b[4];
    }

    b[5] = nalichnye / 100;
    if (b[5] > 0)
    {
        b[5] = tmp.sto >= b[5] ? b[5] : tmp.sto;
        nalichnye -= b[5] * 100;
        tmp.sto -= b[5];
    }

    if (nalichnye == 0)
    {
        banknotes = tmp;
        return Banknotes(b[0], b[1], b[2], b[3], b[4], b[5]);
    }
    return Banknotes(0, 0, 0, 0, 0, 0);
}