// zad_035_dziedziczenie_a_szablony.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string.h>  
#include <stdio.h>  
#include <stdlib.h>  
using namespace std;

template<class typ>
class schowek {
	typ sejf;
public:
	schowek(typ x) :sejf(x) {}
	void schowaj(typ x) { sejf = x; }
	typ oddaj() { return sejf; }
	void raport() {
		cout << "To ja raport schowka!\n";
	}
};

template<class typu>
class sekret :public schowek<typu>
{
	char *haslo;
public:
	sekret(typu arg, char *h) :schowek<typu>(arg) {
		haslo = h;
	}
	typu oddaj(char *h = NULL) {
		if (strcmp(haslo,h) == NULL) {
			return schowek<typu>::oddaj();
		}
		else
			return 0;
	}
};

template<class  typA, class typB>
class nosidlo :public schowek<typB> {
	typA kieszen;
public:
	nosidlo(typA a, typB b) :
		schowek<typB>(b), kieszen(a) {}
	void pokaz() {
		cout << "nosidlo [" << kieszen << ", " 
<< oddaj() << "]\n";
	}
	void raport() {
		cout << "wywolanie zaslonietego raportu: ";
		schowek<typB>::raport();
	}
};

int main()
{
	sekret<float> grota(200.5, "Sezam");
	cout << "Bez hasla: " << grota.oddaj() << endl;
	cout << "Zle haslo: " << grota.oddaj("abrakadabra") << endl;
	cout << "dobre haslo: " << grota.oddaj("Sezam") << endl;
	/*
	sekret<char*> ksiega("wyspa skarbow lezy..", "pirat");
	cout << "Bez hasla=" << ksiega.oddaj() << endl;
	cout << "Z dobrym haslem: " << ksiega.oddaj("Pirat") << endl << endl;

	nosidlo<char, char*> aria('J', "hej Halino..");
	aria.pokaz();

	nosidlo<int, char*> monolog(5, "a coz tam..");
	monolog.pokaz();

	nosidlo<float, unsigned int> biale(3.14, 1);
	biale.pokaz();
	*/
	nosidlo<long, double> zielone(123L, 7.2);
	//zielone.pokaz();

	zielone.raport();
	
	system("pause");
	
    return 0;
}

