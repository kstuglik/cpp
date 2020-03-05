// zad_029_przyjazn_a_szablony_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;

template<int stala>
class poletko {
	int rola[stala];
	poletko() { cout << "prywatny konstruktor\n"; }
	void funpryw() { cout << "prywatna funkcja poletka: " << stala << endl; }
	friend class rolnik;
	friend void siew();
};

class rolnik {
public:
	void rok() {
		cout << "dziala zaprzyjazniony rolnik: " << endl;
		poletko<2> zielone;
		zielone.rola[0] = 6;
		zielone.funpryw();
		poletko<10> duze;
		duze.funpryw();
	}
};

void siew() {
	cout << "dziala zaprzyjazniona funkcja siew:\n";
	poletko<1> doswiadczalne;
	doswiadczalne.funpryw();
}

int main()
{
	rolnik boryna;
	boryna.rok();
	siew();
	system("pause");
    return 0;
}

