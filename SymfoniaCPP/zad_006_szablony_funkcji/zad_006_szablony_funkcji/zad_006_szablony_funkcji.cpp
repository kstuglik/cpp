// zad_006_szablony_funkcji.cpp : Defines the entry point for the console application.
//
#pragma warning(disable:4996)
#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;


template<class typ>
void zamiana(typ &a, typ &b) {
	typ temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = -5, b = 10;
	cout << "Przed zamiana" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	zamiana(a, b);
	cout << "Po zamianie" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	char c1 = 'a';
	char c2 = 'b';
	cout << "Przed zamiana" << endl;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	zamiana(c1,c2);
	cout << "Po zamianie" << endl;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;

	char *wskA = new char[70];
	char *wskB = new char[70];

	strcpy(wskA, "tablica 1, Kosciol Mariacki");
	strcpy(wskB, "tablica 2, Kolegiata Sw. Anny");

	cout << "Przed zamiana" << endl;
	cout << "*wskA = " << wskA << endl;
	cout << "*wskB = " << wskB << endl;
	zamiana(wskA,wskB);
	cout << "Po zamianie" << endl;
	cout << "*wskA = " << wskA << endl;
	cout << "*wskB = " << wskB << endl;

	system("pause");
	return 0;
}

