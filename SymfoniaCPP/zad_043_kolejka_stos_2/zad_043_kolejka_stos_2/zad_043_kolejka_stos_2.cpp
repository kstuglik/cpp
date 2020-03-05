// zad_043_kolejka_stos_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;

#include "lista_poj.h"


//dziedziczenie szablonu lista do szablonu kolejka
template<class typOBJ>
class kolejka : public lista<typOBJ> 
{
public:
	void wstaw_do_kolejki(typOBJ nowy) {
		za_koniec();
		wstaw(nowy);
	}
	typOBJ wez_z_kolejki() {
		na_poczatek();
		typOBJ obiekt = co_na_wybranym();
		usun();
		return obiekt;
	}
};

int main()
{
	kolejka<float> k;
	k.wstaw_do_kolejki(1.f);
	k.wstaw_do_kolejki(2.f);
	k.wstaw_do_kolejki(3.f);

	cout << k.wez_z_kolejki() << endl;
	cout << k.wez_z_kolejki() << endl;

	k.wstaw_do_kolejki(55.f);
	k.wstaw_do_kolejki(65.f);

	cout << k.wez_z_kolejki() << endl;
	cout << k.wez_z_kolejki() << endl;

	system("pause");
}

