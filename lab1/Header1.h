#pragma once
#include <stdio.h>
struct money {
	int grn;
	short int kop;
};
void sum(money* a, money* b, money* result);
void mult(money* a, int b, money* result);
void m_round(money* a, money* result);
void to_string(money* a);
void process();
void process();