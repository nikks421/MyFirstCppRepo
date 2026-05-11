#include "Header1.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void sum(money* a, money* b, money* result) {
    result->kop = a->kop + b->kop;
    result->grn = a->grn + b->grn;

    if (result->kop >= 100) {
        result->grn += 1;
        result->kop -= 100;
    }
}

void mult(money* a, int b, money* result) {
    result->kop = a->kop * b;
    result->grn = a->grn * b;

    if (result->kop >= 100) {
        result->grn += result->kop / 100;
        result->kop = result->kop % 100;
    }
}

void m_round(money* a, money* result) {
    result->grn = a->grn;
    result->kop = a->kop;

    if (result->kop % 10 >= 5) {
        result->kop += 10 - (result->kop % 10);
    }
    else {
        result->kop -= result->kop % 10;
    }

    if (result->kop >= 100) {
        result->grn += result->kop / 100;
        result->kop = result->kop % 100;
    }
}

void to_string(money* a) {
    cout << a->grn << " грн " << a->kop << " коп" << endl;
}

void process() {
    FILE* text;
    fopen_s(&text, "text.txt", "rt");
    char name[50];
    money price = { 0,0 };
    int count;
    money totalMoney = { 0,0 };

    while (fscanf_s(text, "%s %d %hd %d", name, (unsigned)_countof(name), &price.grn, &price.kop, &count) == 4)
    {
        cout << "Продукт: " << name << endl;
        cout << "Ціна: ";
        to_string(&price);

        cout << "Кількість: " << count << endl << endl;

        money temp;
        mult(&price, count, &temp);
        sum(&totalMoney, &temp, &totalMoney);
    }

    fclose(text);

    cout << "Загальна сума: ";
    to_string(&totalMoney);

    money roundedMoney;
    m_round(&totalMoney, &roundedMoney);

    cout << "Сума після округлення: ";
    to_string(&roundedMoney);
}