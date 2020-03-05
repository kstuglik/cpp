// zad_005_szablony_funkcji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void zamiana(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void zamiana2(int* &a, int* &b) {
	int *temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = -5, b = 10;
	int *wskA, *wskB;
	wskA = &a;
	wskB = &b;
	cout << "Przed zamiana" << endl;
	cout << "wskA zawiera adres " << (unsigned long)wskA << " i przechowuje wartosc " << *wskA << endl;
	cout << "wskB zawiera adres " << (unsigned long)wskB << " i przechowuje wartosc " << *wskB << endl;
	zamiana2(wskA, wskB);
	cout << "Po zamianie" << endl;
	cout << "wskA zawiera adres " << (unsigned long)wskA << " i przechowuje wartosc " << *wskA << endl;
	cout << "wskB zawiera adres " << (unsigned long)wskB << " i przechowuje wartosc " << *wskB << endl;

	cout << "Zamiana, najpierw a=" << a << ", b=" << b << " a po zamianie ";
	zamiana(a, b);
	cout<<endl<<"po zamianie a=" << a << ", b=" << b << endl;
	system("pause");
    return 0;
}

