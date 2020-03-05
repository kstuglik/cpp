// zad_039_klasy_pojemnikowe_wektor.cpp : Defines the entry point for the console application.
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

template<class typ>
class wektor {
	typ tabl[pojemnosc_wektora];
	int ile_obiektow;
public:
	wektor() :ile_obiektow(0) {}
	int wstaw(const typ &nowy, int gdzie = -1);
	void usun(int nr);
	typ &co_na(int pozycja) { return tabl[pozycja]; }
	friend ostream & operator<<(ostream &s, wektor<typ> &x);
private:
	void rozsun(int pozycja);
	void zsun(int nr);
};

template<class typ>
ostream & operator<<(ostream &s, wektor<typ> &x) {
	s << " ";
	for (int i = 0; i < x.ile_obiektow; i++) {
		s << < i << ") " << x.tabl[i] << " ";
	}
	s << endl;
	return s;
}


template<class typ>
void wektor<typ>::rozsun(int pozycja) {
	for (int i = ile_obiektow; i > pozycja; i--) {
		tabl[i] = tabl[i - 1];
	}
}

template<class typ>
void wektor<typ>::zsun(int nr) {
	for (int i = nr; i < ile_obiektow; i++) {
		tabl[i] = tabl[i + 1];
	}
}

template<class typ>
int wektor<typ>::wstaw(const typ &nowy, int gdzie) {
	if (ile_obiektow == pojemnosc_wektora) {
		cout << "wektor juz zapelniony" << endl;
		return 0;
	}
	if (gdzie < 0 || gdzie>pojemnosc_wektora) {
		gdzie = ile_obiektow;
	}
	rozsun(gdzie);
	tabl[gdzie] = nowy;
	ile_obiektow++;
	return 1;
}

template<class typ>
void wektor<typ>::usun(int nr) {
	if (nr < ile_obiektow) {
		zsun(nr);
		ile_obiektow--;
	}
}

int main()
{
	osoba
		wloch("Vivaldi"),
		niemiec("Beethoven"),
		austriak("Mozart"),
		polak("Chopin");

	cout << "Przedstawia sie wloch: " << wloch << endl;
	
	osoba *kapelmistrz = &austriak;
	cout << "Kapelmistrzem jest dzis: " << *kapelmistrz << endl;

	wektor<osoba> muzycy;
	cout << "sizeof(muzycy) = " << sizeof(muzycy) << endl;
	
	muzycy.wstaw(niemiec);
	muzycy.wstaw(wloch);
	//cout << muzycy;
	
	muzycy.wstaw(polak, 1);
	//cout << "po wpisie na poz 1\n" << muzycy;

	muzycy.wstaw(austriak, 2);
	//cout << "po wpisie na poz 2\n" << muzycy;

	muzycy.usun(1);
	//cout << "po usunieciu osoby z pozycji 1\n" << muzycy;
	//cout << "co jest na pozycji 1: " << muzycy.co_na(1) << endl;
	
	wektor<osoba> fizycy;
	osoba f1("Einstein");
	osoba f2("Bohr");

	fizycy.wstaw(f1);
	fizycy.wstaw(f2);
	//cout << "zawartosc spisu fizykow:\n" << fizycy;
	
	wektor<osoba*> filozofowie;
	cout << "pojemnik (wskaznikow do osob) " << sizeof(filozofowie) << endl;

	osoba *wskfil1;
	wskfil1 = new osoba("Kant");
	osoba * wskfil2 = new osoba("Platon");

	osoba fil3("Arystoteles");
	filozofowie.wstaw(wskfil1);
	filozofowie.wstaw(wskfil2);
	filozofowie.wstaw(&fil3, 0);

	//cout << filozofowie;
	delete wskfil1;
	delete wskfil2;
	
	cout << "----Pojemnik na rekordy sportowe(float)\n";
	wektor<float> rekordy;
	float Marek = 10.12f, Zenek = 12.5f, Piotr = 8.2f;
	rekordy.wstaw(Marek, 1);
	rekordy.wstaw(Piotr, 0);
	rekordy.wstaw(Zenek, 2);
	//cout << rekordy;
	cout << "Marek zazywal sterydy, dyskwalifikacja!\n";
	rekordy.usun(1);
	//cout << rekordy;
	
	wektor<char> literki;
	literki.wstaw('b');
	literki.wstaw('c');
	literki.wstaw('d');
	literki.wstaw('a', 0);
	//cout << "----W pojemniku na literki(char) sa:\n" << literki;
	
	system("pause");
    return 0;
}

