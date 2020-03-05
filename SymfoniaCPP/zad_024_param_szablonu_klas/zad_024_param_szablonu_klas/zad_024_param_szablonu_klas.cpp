// zad_024_param_szablonu_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

class oceniacz {
public:
	static int wspolna_dana;
	static int szybszy(int a, int b) {
		cout << "ocena wg szybkosci..." << endl;
		return 1;
	}
};

template<int(*adr_skl)(int,int),int* www>
class biuro {
public:
	void opracuj(int m, int k) {
		cout << "pod wskazanym adresem jest: " << *www << endl;
		cout << "wywolam funkcje o wskazanym adresie" << endl;
		adr_skl(m, k);
	}
};

int grubszy(int a, int b) {
	cout << "ocena wg grubosci " << a << ", " << b << endl;
	return 3;
}

int oceniacz::wspolna_dana = 99;
int zwykla_dana = 5;

int main()
{
	cout << "parametry statyczne" << endl;
	biuro <oceniacz::szybszy, &oceniacz::wspolna_dana > b1;
	b1.opracuj(100, 200);

	cout << "zwykle parametry" << endl;

	biuro<grubszy, &zwykla_dana> b2;
	b2.opracuj(101, 201);
	system("pause");
    return 0;
}

