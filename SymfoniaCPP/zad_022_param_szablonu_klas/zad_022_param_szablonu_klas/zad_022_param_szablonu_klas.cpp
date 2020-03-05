// zad_022_param_szablonu_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct zwierze {
	char* imie;
	zwierze(char* txt) { imie = txt; }
	void rea_swiatlo() { cout << imie << " slinie sie!" << endl; }
};

template<class zwierze* adres>
class laborant {
public:
	void dreczenie(){}
	void badaj_odr_warnukowe() {
		cout << "sprawdzam czy reaguje na swiatlo!" << endl;
		adres->rea_swiatlo();
	}
};

zwierze krolik_bug("Bugs");
zwierze myszka_miki("Miki");
zwierze mis_uszatek("Uszatek");

int main()
{
	cout << "zespol ds dreczenia Krolika Bugsa ----------\n";
	laborant<&krolik_bug> zenek, jacek;
	zenek.badaj_odr_warnukowe();
	jacek.badaj_odr_warnukowe();

	cout << "zespol ds dreczenia Myszki Miki ----------\n";
	laborant<&myszka_miki> anna,zosia;
	anna.badaj_odr_warnukowe();
	zosia.badaj_odr_warnukowe();

	laborant<&mis_uszatek> maryla;

	system("pause");
    return 0;
}

