// zad_028_specjalizacja.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class typ, int stala>
class dzialka {
	typ tabl[stala];
	static int skladnikS_int;
	static typ skladnikS_param;
public:
	void robotnik(){}
	void informuj_stat();
	void ustaw_stat(int a, int b);
};

template<class typ,int stala>
void dzialka<typ, stala>::ustaw_stat(int a, int b) {
	skladnikS_int = a;
	skladnikS_param = b;
}

template<class typ,int stala>
void dzialka<typ, stala>::informuj_stat() {
	cout << "skladnikS_int = " << skladnikS_int << ", skladnikS_param = " << skladnikS_param << endl;
}

template<class typ,int stala>
int dzialka<typ, stala>::skladnikS_int = 70;

template<class typ,int stala>
typ dzialka<typ, stala>::skladnikS_param;

int dzialka<char, 15>::skladnikS_int = 123;

template<>
class dzialka<float, 100> {
	float tabl[100];
	float dodatek;
	static int skladnikS_int;
	static float skladnikS_param;
public:
	void robotnik(){}
	void wydawca() {}
	void informuj_stat();
	void ustaw_stat(int a, float b);
};


void dzialka<float, 100>::ustaw_stat(int a, float b) {
	skladnikS_int = a;
	skladnikS_param = b;
}

void dzialka<float, 100>::informuj_stat() {
	cout << "info z klasy specjalizowanej\nskladniS_int = " << skladnikS_int << ", skladnikS_param = " << skladnikS_param << endl;
}

int dzialka<float, 100>::skladnikS_int = 101;
float dzialka<float, 100>::skladnikS_param = 3.14f;

int main()
{
	cout << "Obiekty klasy dzialka<int,10>-----" << endl;
	dzialka<int, 10> zielona;
	zielona.ustaw_stat(2, 3);
	cout << "zielona: ";
	zielona.informuj_stat();

	dzialka<int, 10> czarna;
	cout << "czarna: ";
	czarna.informuj_stat();

	cout << "Obiekty klasy dzialka<char,7>---" << endl;

	dzialka<char, 7> paryz;
	paryz.ustaw_stat(20, 'x');
	cout << "Paryz: ";
	paryz.informuj_stat();

	dzialka<char, 7> nicea;
	cout << "Nicea: ";
	nicea.informuj_stat();

	cout << "Obiekty klasy dzialka<char,8>---" << endl;
	dzialka<char, 8> rumba;
	cout << "rumba: ";
	rumba.informuj_stat();

	cout << "Obiekty klasy dzialka<char,15>---" << endl;
	dzialka<char, 15> fiolek;
	cout << "fiolek: ";
	fiolek.informuj_stat();

	cout << "specjalizowana klasa szablonowa---" << endl;
	dzialka<float, 100> burgund;
	cout << "burgund: ";
	burgund.informuj_stat();


	system("pause");
    return 0;
}

