// zad_017_szablon_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class typ>
class schowek {
	typ sejf;
public:
	void schowaj(typ x) { 
		sejf = x; 
		typ &przezwisko = sejf;
	}
	typ oddaj() { return sejf; }
};

template<class typ>
class schowek_ref {
	typ sejf;
public:
	schowek_ref(typ x) :sejf(x) {};
	typ oddaj() { return sejf; }
};

int main()
{
	int m = 34;
	schowek<int> wartosc;
	wartosc.schowaj(m);
	cout << wartosc.oddaj() << endl;
	schowek<int*> wskaznikowy;
	wskaznikowy.schowaj(&m);
	cout << *wskaznikowy.oddaj() << endl;

	schowek_ref<int&> referencja(m);
	cout << referencja.oddaj() << endl;
	system("pause");
    return 0;
}

