// zad_016_szablon_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class param>
class pasja {
	char* nazwa;
	param jakis_opis;
public:
	pasja(char* na, param op);
	~pasja();
	void jaka();
	static void funstat();
};

template<class param>
pasja<param>::pasja(char* na, param op) :nazwa(na)
{
	jakis_opis = op;
	cout << "to ja konstruktor " << jakis_opis << endl;
}

template<class param>
pasja<param>::~pasja() {
	cout << "to ja destruktor " << nazwa << endl;
}

template<class param>
void pasja<param>::jaka() {
	cout << "jaka pasja: " << nazwa << ", opis: " << jakis_opis << endl;
}

template<class param>
void pasja<param>::funstat() {
	cout << "funkcja statyczna" << endl;
}

int main()
{
	pasja<int> muzyk("Sw. Mateusza", 37);
	pasja<char> szewc("Szewska", 'K');
	muzyk.jaka();
	szewc.jaka();
	
	pasja<int>::funstat();
	cout << "pocwiczmy jawne wywolanie konstruktora" << endl;
	pasja<int> *wskjan;
	wskjan = new pasja<int>("Sw.Jana", 39);
	wskjan->jaka();
	pasja<int> dyrygent = pasja<int>("Sw.Lukasza", 40);
	cout << "Pocwiczmy jawne wywolanie destruktora" << endl;

	wskjan->pasja<int>::~pasja();
	szewc.pasja<char>::~pasja();

	cout << "konczymy program, operator delete:" << endl;
	delete wskjan;
	cout << "dalej sam kompilator" << endl;
	
	system("pause");
    return 0;
}

