// zad_011_szablony_funkcji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;

template<class jakis_typ>
jakis_typ wieksza(jakis_typ a, jakis_typ b) {
	return (a > b) ? a : b;
}

char* wieksza(char* a, char* b) {
	cout << "pracuje wersja specjalizowana*" << endl;
	if (strlen(a) > strlen(b))return a;
	else return b;
}

int main()
{
	int m1 = 5, m2 = 4;
	char znak1 = 'k', znak2 = 's';
	cout << "wiekszy int: " << wieksza(m1, m2) << endl;
	cout << "wiekszy char: " << wieksza(znak1, znak2) << endl;
	char odys[30] = { "Muzo" };
	char ilia[30] = { "Gniew Achilla.." };
	cout << "wiekszy string: " << wieksza(ilia,odys) << endl;
	system("pause");
    return 0;
}

