// zad_032_dziedziczenie_a_szablony.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class typ>
class schowek {
	typ sejf;
public:
	schowek(typ x) :sejf(x) {}
	void schowaj(typ x) { sejf = x; }
	typ oddaj() { return sejf; }
	void raport() { cout << "to ja raport schowka!\n"; }
};

class portmonetka :public schowek<float> {
	const int rozmiar;
public:
	portmonetka(int roz):schowek<float>(0.10),rozmiar(roz){}
	void raport() { cout << "w portmonetce o rozmiarze " << rozmiar << " cm jest " << oddaj() << " zlotych\n"; }
};

int main()
{
	portmonetka skorzana(12);
	float ile_mam = skorzana.oddaj();
	skorzana.raport();
	skorzana.schowaj(ile_mam + 100);
	skorzana.raport();
	skorzana.schowek<float>::raport();
	system("pause");
    return 0;
}

