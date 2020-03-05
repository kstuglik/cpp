// zad_009_szablony_funkcji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class typ1, class typ2, class rezultat>
rezultat funkcja(typ1 a, typ2 b,rezultat) {
	return (a + b);
}

int main()
{
	double x = 200.5;
	cout << "gdy osatnim argumentem jest: " << endl
		<< funkcja(100.14, 1, 0) << endl
		<< "(int)7 = " << funkcja(100.14, 1, (int)7) << endl
		<< "obiekt typu double = " << funkcja(100.14, 1, x) << endl
		<< "(char)0 = " << funkcja(100.14, 1, (char)0) << endl;
	system("pause");
    return 0;
}

