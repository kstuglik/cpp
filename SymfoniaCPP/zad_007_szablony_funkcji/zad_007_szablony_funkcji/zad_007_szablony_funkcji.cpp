// zad_007_szablony_funkcji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#define  maks(a,b) (((a)>(b))?(a):(b));
using namespace std;

template<class typ>
typ maxim(typ a, typ b)
{
	return (a > b) ? a : b;
}

int main()
{
	int a = 5, b = 10, c = 5, d = 10;
	cout << "[szablonem] " << maxim(a, b) << endl;
	cout << "++[szablonem] " << maxim(a++, b++) << endl;
	cout << "[makrodefinicja] " << maks(c, d);
	cout << "\n++[makrodefinicja] " << maks(c++, d++);
	cout << "Po eksperymentach: ";
	cout << " a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << endl;
	system("pause");
    return 0;
}

