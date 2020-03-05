// zad_037_dziedziczenie_a_szablony.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;

template<class jakis_typ>
class kumul {
protected:
	jakis_typ sejf;
public:
	kumul(jakis_typ x) :sejf(x) {}
	void schowaj(jakis_typ x) { sejf = x; }
	jakis_typ oddaj() { return sejf; }
	void dodaj(jakis_typ a) { sejf += a; }
};

template<>
class kumul<char*>
{
protected:
	char* sejf;
public:
	kumul(char* tekst = NULL) {
		sejf = NULL;
		if (tekst) {
			schowaj(tekst);
		}
	}
	void schowaj(char* x) {
		if (sejf)
			delete sejf;
		sejf = new char[strlen(x) + 1];
		strcpy(sejf, x);
	}
	char* oddaj() { return sejf; }
	void dodaj(char* co);
	~kumul(){
		if (sejf) {
			delete sejf;
		}
	}
};

void kumul<char*>::dodaj(char* co) {
	int rozmiar_nowego = strlen(sejf) + strlen(co) + 1;
	char* roboczy = new char[rozmiar_nowego];
	strcpy(roboczy, sejf);
	strcat(roboczy, co);
	if (sejf) {
		delete sejf;
	}
	sejf = roboczy;
}

template<class jakis_typ>
class bank :public kumul<jakis_typ>
{
public:
	bank(jakis_typ x) :kumul<jakis_typ> (x) {}
	void dodaj(jakis_typ co) {
		sejf += co;
		sejf += 1;
	}
};

template<>
class bank<char*> :public kumul<char*>
{
	int ile_wierszy;
public:
	bank(char* x) :kumul<char*> (x) { ile_wierszy = 0; }
	void dodaj(char* co);
};


void bank<char*>::dodaj(char* co) {
	ile_wierszy++;
	for (int i = 0; i < ile_wierszy; i++) {
		kumul<char*>::dodaj("* ");
	}
	kumul<char*>::dodaj(co);
}

int main()
{
	kumul<int> skarbonka(5);
	skarbonka.dodaj(3);
	cout << "w skarbonce jest = " << skarbonka.oddaj() << endl;

	kumul<char*> zdanie("Byc, ");
	zdanie.dodaj("albo nie byc");
	zdanie.dodaj(" oto jest pytanie");
	cout << "w zdaniu jest =\n" << zdanie.oddaj() << endl;

	bank<int> swiss(10);
	swiss.dodaj(20);
	swiss.dodaj(30);
	cout << "stan oszczednosci = " << swiss.oddaj() << endl;

	bank<char*> dramat("Teatr moj widze ogromny\n");
	dramat.dodaj("Ludzie je pelnia, nie cienie\n");
	dramat.dodaj("Ja jestem ich grze przytomny\n");
	cout << "Dramat Wywolenie:\n" << dramat.oddaj();


	system("pause");
}

