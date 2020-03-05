// zad_025_param_szablonu_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class p, int nr>
class zegar {
public:
	typedef p* wskdo;
	enum kierunek{w_dol=nr,w_gore};
};

int main()
{
	zegar<int, 20>::wskdo wolny;
	int suma = 100;
	wolny = &suma;

	zegar<int, 20>::kierunek kurtyna;
	kurtyna = zegar<int, 20>::w_gore;
	cout << "wolny-->" << *wolny << " , (int)kurtyna = " << (int)kurtyna << endl;
	
	zegar<char, 30>::wskdo napis;
	char nazwa[30] = { "plik.ext" };
	napis = nazwa;

	zegar<char, 30>::kierunek pozycja;
	pozycja = zegar<char, 30>::w_gore;
	cout << "napis-->" << napis << " ,(int)pozycja = " << (int)pozycja << endl;
	//pozycja = 100;
	//cout << "straszne: pozycja = " << (int)pozycja << endl;
	//pozycja = zegar<int, 20>::w_gore;
	//cout << "o zgrozo: pozycja = " << (int)pozycja << endl;

	system("pause");
    return 0;
}

