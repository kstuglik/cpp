// zad_041_pojemnik_typu_lista.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include "osoba.h"
template<class typ>
class dlista {
	struct wezel {
		typ* wsk;
		wezel* nastepca;
		wezel* poprzednik;
		wezel():wsk(NULL),nastepca(NULL),poprzednik(NULL){}
	};
	wezel* pierwszyW;
	wezel* ostatniW;
	wezel* wybranyW;
public:
	dlista() {
		pierwszyW = ostatniW = wybranyW = NULL;
	}
	~dlista();
	void wstaw(typ& obj);
	void usun();
	typ& co_na_wybranym() {
		return *(wybranyW->wsk);
	}
	void na_poczatek() {
		wybranyW = pierwszyW;
	}
	void za_koniec() {
		wybranyW = NULL;
	}
	wezel* przejdz_na_nastepny() {//ustawienie wybranego wezla na nastepny
		if (wybranyW) {//jesli rozny od NULL
			return (wybranyW = wybranyW->nastepca);
		}
		else
			return NULL;
	}
	wezel* przejdz_na_poprzedni() {
		//ustawienie wybranego wezla na poprzedni
		if (wybranyW != pierwszyW) {
			return (wybranyW = wybranyW->poprzednik);
		}
		else
			return pierwszyW;
	}

	void nty_wezel(int n);
private:
	void daje_na_poczatek(wezel* nowyW);
	void daje_w_srodku(wezel* nowyW);
	void daje_na_koniec(wezel* nowyW);

	void usuwam_pierwszy();
	void usuwam_ostatni();
	void usuwam_ze_srodka();
	template<class typ>
	friend ostream& operator<<(ostream& s, dlista<typ>& x);
private:
	wezel* poprzedni_wezel(wezel* odnosny);
};

template<class typ>
void dlista<typ>::wstaw(typ& obj) {
	//wstawiamy PRZED wybranym wezlem
	//w rezultacie ten wybrany bedzie odt¹d o 1 dalej
	wezel* nowyW = new wezel;//definicja wezla
	nowyW->wsk = &obj;//od razu umieszczamy w nim informacje o przedmiocie
	//teraz zajmujemy sie wpieciem wezla do listy
	if (wybranyW != NULL) {//jesli to nie na koncu listy
		if (wybranyW == pierwszyW) {
			daje_na_poczatek(nowyW);
		}
		else {
			daje_w_srodku(nowyW);
		}
	}
	else {
		//jesli wstawiamy na koncu listy
		daje_na_koniec(nowyW);
	}
}

template<class typ>
void dlista<typ>::daje_na_poczatek(wezel* nowyW) {
	pierwszyW = nowyW;
	nowyW->nastepca = wybranyW;
	wybranyW->poprzednik = nowyW;//!!
	nowyW->poprzednik = NULL;//!!poprzednika byc nie moze
	wybranyW = nowyW;
}

template<class typ>
void dlista<typ>::daje_w_srodku(wezel* nowyW) {
	//znalezienei poprzednika do biezacego i wpisanie mu nowego nastepcy
	(wybranyW->poprzednik)->nastepca = nowyW;//poprzednikowi wybranego wêz³¹ wype³nij sk³adnik nastêpca, 
	//wpisuj¹c tam adres wêz³a nowyW
	
	nowyW->nastepca = wybranyW;//mastepca nowego to wybrany
	nowyW->poprzednik = wybranyW->poprzednik;
	wybranyW->poprzednik = nowyW;
}

template<class typ>
void dlista<typ>::daje_na_koniec(wezel* nowyW) {
	if (!pierwszyW) {
		pierwszyW = nowyW;
	}
	else {
		ostatniW->nastepca = nowyW;
		nowyW->poprzednik = ostatniW;
	}
	ostatniW = nowyW;
}

template<class typ>
void dlista<typ>::usun() {
	if (!wybranyW)
		return;
	if (wybranyW == pierwszyW) {
		usuwam_pierwszy();
	}
	else {
		//czyli mamy usunac pozniejszy, wyrozniamy 2 sytuacje
		if (wybranyW == ostatniW) {
			usuwam_ostatni();
		}
		else {
			usuwam_ze_srodka();
		}
	}
}

template<class typ>
void dlista<typ>::usuwam_pierwszy() {
	pierwszyW = pierwszyW->nastepca;
	delete wybranyW;
	wybranyW = pierwszyW;
	if (pierwszyW) {
		pierwszyW->poprzednik = NULL;
	}
	else {
		ostatniW = NULL;
	}
}

template<class typ>
void dlista<typ>::usuwam_ostatni() {
	//dobrze najpierw znalezc poprzedni wezel
	wezel* ppp = wybranyW->poprzednik;
	ppp->nastepca = NULL;
	ostatniW = ppp;
	delete wybranyW;
	wybranyW = NULL;
}

template<class typ>
void dlista<typ>::usuwam_ze_srodka() {
	//znalezc poprzedni wezel
	wezel* ppp = wybranyW->poprzednik;
	ppp->nastepca = wybranyW->nastepca;
	(wybranyW->nastepca)->poprzednik = ppp;
	delete wybranyW;
	wybranyW = ppp;
}

template<class typ>
dlista<typ>::~dlista() {
	for (wybranyW = pierwszyW; wybranyW;) {
		wezel* pamietnik;
		//zanim skasuje sie wezel konieczne jest odczytanie i zapamietanie gdzie jest jego nastepca
		pamietnik = wybranyW->nastepca;
		delete wybranyW;
		wybranyW = pamietnik;
	}
}

template<class typ>
void dlista<typ>::nty_wezel(int n) {
	na_poczatek();
	for (int i = 0; i < n; i++) {
		przejdz_na_nastepny();
	}
}

template<class typ>
ostream& operator<<(ostream& s, dlista<typ>& x) {
	dlista<typ>::wezel* skoczek = x.pierwszyW;
	for (int i = 0; skoczek; i++, skoczek = skoczek->nastepca) {
		s << i << ") " << *(skoczek->wsk) << " ";
	}
	s << endl;
	return s;
}

int main()
{
	osoba
		matematyk("Mat"),
		muzyk("Muz"),
		biochemik("bio"),
		astronom("astro"),
		wynalazca("wyn");

	dlista<osoba> slawni;
	cout << "sizeof(slawni) = " << sizeof(slawni) << endl;
	slawni.wstaw(biochemik);
	slawni.na_poczatek();
	slawni.wstaw(matematyk);
	slawni.za_koniec();
	slawni.wstaw(wynalazca);
	cout << slawni;

	slawni.nty_wezel(1);
	slawni.wstaw(muzyk);
	cout << slawni;

	cout << "zle wpisany astro, skorygujemy to\n";
	slawni.nty_wezel(4);
	slawni.usun();
	cout << slawni;

	slawni.nty_wezel(3);
	slawni.wstaw(astronom);
	cout << slawni;
	cout << "wskaznik wybranyW jest na: " << slawni.co_na_wybranym() << endl;
	slawni.przejdz_na_poprzedni();
	cout << "obecnie wskaznik wybranyW jest na: " << slawni.co_na_wybranym()<<endl;


	system("pause");
}

