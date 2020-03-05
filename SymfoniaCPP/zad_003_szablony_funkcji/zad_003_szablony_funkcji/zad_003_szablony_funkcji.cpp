// zad_003_szablony_funkcji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template <class typ1,class typ2>
typ2 wieksza(typ1 a, typ2 b) {
	return (a > b) ? a : b;
}

int main()
{
	long ll = 25L;
	double dd = 44.45;
	cout << "sposrod "<<ll<<" i "<<dd<<" wieksze jest: "<<wieksza(ll,dd)<<endl;
	cout << "w odwrotnej kolejnosci podanie parametrow zwraca,ze wieksze jest: " << wieksza(dd,ll) << endl;
	system("pause");
    return 0;
}

