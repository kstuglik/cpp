// zad_023_param_szablonu_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<void(*wskfun)()>
class pracownik {
public:
	void uszereguj() {
		cout << "szereguje co mi kazano" << endl;
		wskfun();
	}
};

void alfabetycznie() {
	cout << "sortowanie alfabetycznie" << endl;
}

void wg_wzrostu() {
	cout << "ustawianie wg wielkosci" << endl;
}

int main()
{
	pracownik<wg_wzrostu> mirek;
	mirek.uszereguj();
	pracownik<alfabetycznie> witek;
	witek.uszereguj();
	system("pause");
    return 0;
}

