// zad_030_przyjazn_a_szablony_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class typ>
class krol{
	typ budzet;
public:
	krol(typ kwota) :budzet(kwowa) {}
	void fundusze() { cout << "Mam w skarbcu " << budzet << endl; }
	friend void sprawdzenie(krol<typ> obj);
	friend class skarbnik<typ>;
};

template<class typ>
void sprawdzenie(krol<typ> obj) {
	cout << "z funkcji zaprzyjaznionej:\nW kasie krolewskiej ejst " << obj.budzet << endl;
}

template<class typ>
class skarbnik {
	krol<typ> * wladca;
public:
	skarbnik(krol<typ> * wsk) : wladca(wsk) {}
	void stan_panstwa() { 
		cout << "z klasy zaprzyjaznionej\nBudzet wladcy " << wladca->budzet << endl; 
	}
};

int main()
{
	krol<int> ramzes(300);
	ramzes.fundusze();
	//sprawdzenie(ramzes);
	//skarbnik<int> sinue(&ramzes);
	//sinue.stan_panstwa();
	system("pause");
    return 0;
}

