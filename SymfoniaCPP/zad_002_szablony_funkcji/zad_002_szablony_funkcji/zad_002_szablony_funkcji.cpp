// zad_002_szablony_funkcji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template <class typ>
void uniwersal(typ obj, int wartosc) {
	typ obiekt1(wartosc);
	typ obiekt2 = typ(wartosc);
	obiekt2.typ::~typ();
}

class liczba {
	int w;
	char opis[30];
public:
	liczba(int wart) :w(wart) {}
	~liczba() { cout << "To jest destruktor" << endl; }
};

int main()
{
	liczba biala(7);
	uniwersal(biala, 17);

	int n = 7;
	uniwersal(n, 13);
	cout << "Koniec programu" << endl;
	system("pause");
}

