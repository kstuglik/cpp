// zad_010_szablony_funkcji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class T>
void fiolek(T arg) {
	static int licznik_pracy;
	licznik_pracy++;
	cout << "Arg = " << arg << "\t funkcja pracuje " << licznik_pracy << " raz" << endl;
}

int main()
{
	fiolek(1);
	fiolek(1);
	fiolek(3.14);
	fiolek(0);
	fiolek('x');
	system("pause");
    return 0;
}

