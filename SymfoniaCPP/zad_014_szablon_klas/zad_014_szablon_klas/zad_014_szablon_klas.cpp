// zad_014_szablon_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

class skarb {
	char nazwa[20];
	int wartosc;
public:
	skarb(char* n, int w) :wartosc(w) {
		strcpy(nazwa, n);
	}
	friend ostream&operator<<(ostream& strum, const skarb& sk) {
		strum << sk.nazwa << " o wartosci " << sk.wartosc << " dukatow";
		return strum;
	}
};

const int ile_mozna = 3;

class kosz_skarbow {
	skarb *tab[ile_mozna];
	int ile_juz;
	char* opis;
public:
	kosz_skarbow(char* jaki);
	void dodaj(skarb* wsk) {
		tab[ile_juz++] = wsk;
	}
	void wyrzuc(int ktory);
	void co_mam();
	int czy_mam(skarb* wsk);
	void moze_zabierasz(skarb* wsk);
};

kosz_skarbow::kosz_skarbow(char* jaki) {
	opis = jaki;
	for (int i = 0; i < ile_mozna; i++)
		tab[i] = NULL;
	ile_juz = 0;
}

void kosz_skarbow::wyrzuc(int ktory) {
	for (int i = ktory - 1; i < ile_mozna - 1; i++) {
		tab[i] = tab[i + 1];
	}
	tab[ile_mozna - 1] = NULL;
	ile_juz--;
}

void kosz_skarbow::co_mam() {
	cout << "w koszu " << opis << " jest:"<<endl;
	for (int i = 0; i < ile_mozna; i++) {
		if (tab[i])
			cout << " " << (i + 1) << ") " << *tab[i] << endl;
	}
}

int kosz_skarbow::czy_mam(skarb* wsk) {
	for (int i = 0; i < ile_mozna; i++) {
		if (wsk == tab[i])
			return 1;
	}
	return 0;
}

void kosz_skarbow::moze_zabierasz(skarb* wsk) {
	cout << "Napotkales " << *wsk << endl << "czy zabierasz? [t/n] ";
	char odp;
	cin >> odp;
	if (tolower(odp) == 't') {
		if (ile_juz >= ile_mozna) {
			cout << "bedzie za duzo w koszu " << opis << endl;
			co_mam();
			cout << "co wyrzucic [pozycja 1-3]? : ";
			int nr;
			cin >> nr;
			wyrzuc(nr);
		}
		dodaj(wsk);
	}
	co_mam();
}

int main()
{
	skarb pierscien("pierscien", 200);
	skarb sztylet("sztylet", 70);
	skarb klucz("klucz", 30);
	skarb kompas("kompas", 100);

	kosz_skarbow k("skarbow");

	cout << "wchodzimy do labiryntu" << endl
		<< "pierwszy korytarz pusty, idziemy dalej" << endl
		<< "---komnata zielona---" << endl;
		k.moze_zabierasz(&pierscien);
		cout<< "---komnata biala---" << endl;
		k.moze_zabierasz(&sztylet);
		cout<< "---komnata fioletowa---" << endl;
		k.moze_zabierasz(&klucz);
		cout<< "---komnata zielona---" << endl;
		k.moze_zabierasz(&kompas);

		cout << "napada cie Miniotaur, potrzebujesz sztyletu" << endl;
		if (k.czy_mam(&sztylet))
			cout << "masz, wiec obroniles sie i wygrales!" << endl;
		else
			cout << "nie masz sztyletu, zginales!" << endl;
	system("pause");
    return 0;
}

