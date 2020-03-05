// zad_004_szablony_funkcji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void zielony(int);

template<class zielony>
zielony malarz(zielony a, int b) {
	::zielony(b);//wywolanie globalnej funkcji o tej nazwie
	return (a + b);
}

int main()
{
	double x = 5.5;
	malarz(x, 7);
	system("pause");
    return 0;
}

void zielony(int k) {
	cout << "mowi globalna funkcja zielony!" << endl;
}

