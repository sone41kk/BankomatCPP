// BankomatCPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Bankomat.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int cash;
    cout << "Сколько денег выдать?: ";
    cin >> cash;
    Bankomat bankomat(2, 3, 4, 5, 6, 7);
    auto result = bankomat.giveCash(cash);
    int b5000, b2000, b1000, b500, b200, b100;
    bankomat.Deconstruct(b5000, b2000, b1000, b500, b200, b100);
    cout << "Выдано: по 5000 руб: " << result.cash5000 << " шт.\n";
    cout << "Выдано: по 2000 руб: " << result.cash2000 << " шт.\n";
    cout << "Выдано: по 1000 руб: " << result.cash1000 << " шт.\n";
    cout << "Выдано: по 500 руб: " << result.cash500 << " шт.\n";
    cout << "Выдано: по 200 руб: " << result.cash200 << " шт.\n";
    cout << "Выдано: по 100 руб: " << result.cash100 << " шт.\n";
    cout << "--------\n";
    cout << "Осталось: по 5000 руб: " << b5000 << " шт.\n";
    cout << "Осталось: по 2000 руб: " << b2000 << " шт.\n";
    cout << "Осталось: по 1000 руб: " << b1000 << " шт.\n";
    cout << "Осталось: по 500 руб: " << b500 << " шт.\n";
    cout << "Осталось: по 200 руб: " << b200 << " шт.\n";
    cout << "Осталось: по 100 руб: " << b100 << " шт.\n";

}

