// zad_038_klasy_pojemnikowe_wektor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;

class osoba {
	char nazwisko[20];
public:
	osoba(char* n = NULL) {
		if (n)
			strcpy(nazwisko, n);
	}
	friend ostream & operator<<(ostream &s, const osoba &o);
	friend ostream & operator<<(ostream &s, const osoba *wsk);
};

ostream & operator<<(ostream &s, const osoba &o) {
	s << o.nazwisko;
	return s;
}

ostream  & operator<<(ostream &s, const osoba *wsk) {
	s << wsk->nazwisko;
	return s;
}

const int pojemnosc_wektora = 15;

class wektor {
	osoba tabl[pojemnosc_wektora];
	int ile_obiektow;
public:
	wektor() :ile_obiektow(0) {}
	int wstaw(const osoba &nowy, int gdzie = -1);
	void usun(int nr);
	osoba & co_na(int pozycja) { return tabl[pozycja]; }
	friend ostream & operator<<(ostream &s, wektor &x);
private:
	void rozsun(int pozycja);
	void zsun(int nr);
};

ostream & operator<<(ostream &s, wektor &x) {
	s << " ";
	for (int i = 0; i < x.ile_obiektow; i++) {
		s << i << ") " << x.tabl[i] << " ";
	}
	s << endl;
	return s;
}

void wektor::rozsun(int pozycja) {
	for (int i = ile_obiektow; i > pozycja; i--) {
		tabl[i] = tabl[i - 1];
	}
}

void wektor::zsun(int nr) {
	for (int i = nr; i < ile_obiektow; i++) {
		tabl[i] = tabl[i + 1];
	}
}

int wektor::wstaw(const osoba & nowy, int gdzie) {
	if (ile_obiektow == pojemnosc_wektora) {
		cout << "wektor juz zapelniony\n";
		return 0;
	}
	if (gdzie<0 || gdzie>ile_obiektow) {
		gdzie = ile_obiektow;
	}
	rozsun(gdzie);
	tabl[gdzie] = nowy;
	ile_obiektow++;
	return 1;
}

void wektor::usun(int nr) {
	if (nr < ile_obiektow) {
		zsun(nr);
		ile_obiektow--;
	}
}

int main()
{
	osoba wloch("Vivaldi"), niemiec("Beethoven"),
		austriak("Mozart"), polak("Chopin");
	cout << "Przedstawia sie wloch: " << wloch << endl;
	osoba *kapelmistrz = &austriak;
	cout << "kapelmistrz jest dziœ: " << *kapelmistrz << endl;
	wektor muzycy;
	cout << "sizeof(muzycy) = " << sizeof(muzycy) << endl;

	muzycy.wstaw(niemiec);
	muzycy.wstaw(wloch);
	cout << muzycy;

	muzycy.wstaw(polak, 1);
	cout << "po wspisie na poz. 1\n" << muzycy;
	muzycy.wstaw(austriak, 2);
	cout << "po wpisie na poz. 2\n" << muzycy;

	muzycy.usun(1);
	cout << "po usunieciu osoby z pozycji 1\n" << muzycy;
	cout << "co jest na pozycji 1: " << muzycy.co_na(1) << endl;
	wektor fizycy;
	osoba f1("Einstein");
	osoba f2("Bohr");
	fizycy.wstaw(f1);
	fizycy.wstaw(f2);
	cout << "zawartosc spisu fizykow:\n" << fizycy;
	system("pause");
}

