// zad_027_specjalizacja.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class typ>
class akumulator {
	typ zloze;
public:
	akumulator() :zloze(0) {}
	void przyjm(typ co);
	typ rozladunek();
};

template<class typ>
typ akumulator<typ>::rozladunek() {
	typ pomocnik = zloze;
	zloze = 0;
	return pomocnik;
}

template<class typ>
void akumulator<typ>::przyjm(typ co) {
	zloze = co;
}

void akumulator<long>::przyjm(long co) {
	zloze = zloze + co;
	cout << "Przyjmuje " << co << " wiec jest juz " << zloze << endl;
}

int main()
{
	akumulator<float> kasa;
	kasa.przyjm(400.00);
	kasa.przyjm(505.50);

	cout << "utarg = " << kasa.rozladunek() << endl;
	akumulator<long> konto;
	konto.przyjm(12345L);
	konto.przyjm(77777L);
	cout << "Saldo = " << konto.rozladunek() << endl;
	system("pause");
    return 0;
}

