// zad_019_szablon_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class typ1,class typ2>
class duza {
	typ1 skladnik;
	class pomocnicza {
	public:
		typ1 lewy;
		typ2 prawy;
		void wypisz() {
			cout << "Lewy: " << lewy << ", Prawy: " << prawy << endl;
		}
	};
	pomocnicza pomagier;
	pomocnicza *wskpom;
public:
	duza(typ1 a, typ2 b) {
		skladnik = a;
		pomagier.lewy = a;
		pomagier.prawy = b;
	}
	void pokaz() {
		cout << "skladnik = " << skladnik << endl;
		pomagier.wypisz();
	}
};

int main()
{
	duza<int, char> a(10, 'f');
	a.pokaz();
	duza<float, char*> k(3.14, "Carmen");
	k.pokaz();
	system("pause");
    return 0;
}

