// zad_015_szablon_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class typ>
class schowek {
	typ sejf;
public:
	void schowaj(typ x) { sejf = x; }
	typ oddaj() { return sejf; }
};


int main()
{
	schowek<int> czerwony;
	schowek<char> znakowy;
	schowek<int> d;
	czerwony.schowaj(9);
	int m = czerwony.oddaj();
	znakowy.schowaj('S');
	cout << "schowany int = " << m << ", schowany char = " << znakowy.oddaj() << endl;
	system("pause");
    return 0;
}

