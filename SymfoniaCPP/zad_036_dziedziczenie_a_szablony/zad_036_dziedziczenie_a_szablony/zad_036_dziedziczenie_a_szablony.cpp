// zad_036_dziedziczenie_a_szablony.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class A {
protected:
	int x, y;
public:
	A(int a,int b):x(a),y(b){}
};

template<class typ>
class B : public A
{
	typ dana;
public:
	B(typ wart, int d=1,int s=1):dana(wart),A(d,s){}
	typ wazna_funkcja(typ p) {
		dana *= p;
		return dana;
	}
};

template<>
class B<char*> :public A {
	char *dana;
	int licznik;
public:
	B<char*>(char* wsk, int d,int s):dana(wsk),A(d,s){}
	void wazna_funkcja(char c);
};

void B<char*>::wazna_funkcja(char c) {
	for (int i = 0; dana[i]; i++) {
		cout << dana[i];
		cout << c;
	}
}

int main()
{
	B<float> bbb(0.5, 5, 20);
	cout << bbb.wazna_funkcja(7);
	cout<< endl;

	B<char*> slowko("Casablanca", 5, 20);
	slowko.wazna_funkcja('-');

	system("pause");
}

