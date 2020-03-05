// zad_012_szablony_funkcji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<typeinfo>

using namespace std;

class pojazd {
public:
	virtual void funkcja() {}
};

class rower : public pojazd {

};

int main()
{
	pojazd p;
	rower r1, r2;
	int m = 4;
	cout << "obiekt o nazwie m jest typu " << typeid(m).name() << endl
		<< " a obiekt i nazwie r1 jest typu " << typeid(r1).name() << endl;

	if (typeid(r1) == typeid(r2)) {
		cout << "obiekty r1 i r2 sa tego samego typu, tj " << typeid(r1).name() << endl;
	}

	if (typeid(r1) != typeid(p)) {
		cout << "obiekty r1 i p sa roznego tyou" << endl;
	}

	int *ww = &m;
	cout << "wskaznik pokazuje na obiekt typu " << typeid(*ww).name() << endl;

	pojazd *wskpoj;
	wskpoj = &p;
	cout << "wskaznik wskpoj pokazuje na obiekt typu: " << typeid(*wskpoj).name() << endl;

	wskpoj = &r2;
	cout << "a teraz wskpoj pokazuje na obiekt typu: " << typeid(*wskpoj).name() << endl;

	system("pause");
    return 0;
}

