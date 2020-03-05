// zad_026_specjalizacja.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;

template<class typ>
class akumulator {
	typ zloze;
public:
	akumulator():zloze(0){}
	void przyjm(typ co) {
		zloze = co;
	}
	typ rozladunek();
};

template<class typ>
typ akumulator<typ>::rozladunek() {
	typ pomocnik = zloze;
	zloze = 0;
	return pomocnik;
}

template<>
class akumulator<char *> {
	char* zloze;
public:
	akumulator();
	void przyjm(char* nowy);
	char* rozladunek() {
		char* chwila = zloze;
		zloze = 0;
		return chwila;
	}
	~akumulator() {
		if (zloze) {
			cout << "obiekt zmarl nie zdazywszy niczego po sobie zapisac\n";
			delete zloze;
			system("pause");
		}
	}
};

akumulator<char *>::akumulator() :zloze(NULL) {}

void akumulator<char*>::przyjm(char* nowy) {
	if (!zloze) {
		zloze = new char[strlen(nowy) + 1];
		zloze[0] = NULL;
	}
	else {
		char *stary = zloze;
		zloze = new char[strlen(stary) + strlen(nowy) + 1];
		strcpy(zloze, stary);
		delete stary;
	}
	strcat(zloze, nowy);
}

int main()
{
	akumulator<float> kasa;

	kasa.przyjm(400.00);
	float przelew = 50.50;
	kasa.przyjm(przelew);

	cout << "utarg miesieczny w styczniu = " << kasa.rozladunek() << endl;

	kasa.przyjm(320.00);
	cout << "utarg miesieczny w lutym = " << kasa.rozladunek() << endl;

	akumulator<char*> wysp;

	wysp.przyjm("przeciez juz dawno sie wyzbylem\n");
	wysp.przyjm("marzen o utraconym raju\n");

	char* zapisek_ranny = wysp.rozladunek();
	cout << "***rano Wyspianski ulozyl:***\n" << zapisek_ranny;

	wysp.przyjm("zyje, nu zwalo sie ze zylem\n");
	wysp.przyjm("nad jakas rzeka, w jakims kraju..\n");

	char* zapisek_wieczorny = wysp.rozladunek();
	cout << "***wieczorem Wyspianski ulozyl:***\n" << zapisek_wieczorny;

	delete zapisek_ranny;
	delete zapisek_wieczorny;
	wysp.przyjm("nad jakas rzeka, w jakims miescie\n");

	system("pause");
}

