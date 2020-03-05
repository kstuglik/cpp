// zad_001_szablony_funkcji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template <class typ>
typ wieksze(typ a, typ b) {
	return(a > b) ? a : b;
}

int main()
{
	cout << "Nastapi porownanie dwoch liczb" << endl;
	double a = 9.0, b = 9.1;
	cout << "Wynik porownania liczb "<<a<<" i "<<b<<" wykazuje, ze wieksze jest "<<wieksze(a,b)<<endl;
	cout << "Wynik porownania kodu ASCII liter a i b  wykazuje, ze wieksze jest " << wieksze('a','b') << endl;
	system("pause");
    return 0;
}

