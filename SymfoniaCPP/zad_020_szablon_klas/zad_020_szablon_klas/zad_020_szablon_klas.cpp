// zad_020_szablon_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<dos.h>
using namespace std;

class zamek {
public:
	static zamek* wsk_siedziby;
	char* nazwa;
	zamek(char* n):nazwa(n){}
	void odpowiedz(void) {
		cout << "Tu " << nazwa << ", wsk_siedziby=>" << wsk_siedziby->nazwa << endl;
	}
	static void gdzie_krol() {
		cout << "funkcja statyczna informuje ze siedziba krola jest teraz\nzamek: " << wsk_siedziby->nazwa << endl;
	}
};

zamek* zamek::wsk_siedziby;

template<class T>
class szata {
public:
	static int ii;
	static T ttt;
	static szata<T>* wsk_stolicy;
	char* nazwa;
	szata(char* n) :nazwa(n) {};
	void odpowiedz() {
		cout << "Tu " << nazwa << "[" << ii << "," << ttt << "] stolica jest => " << wsk_stolicy->nazwa << endl;
	}
	static void funstat() {
		cout << "Funkcja statyczna informuje, ze stolica jest teraz: " << wsk_stolicy->nazwa << endl;
	}
};

template<class T>
int szata<T>::ii;

template<class T>
T szata<T>::ttt;

template<class T>
szata<T>* szata<T>::wsk_stolicy;

int main()
{
	cout << "Bawimy sie zwykla klasa***" << endl;
	zamek niepolomice("Niepolomice");
	zamek wawel("Wawel");

	zamek::wsk_siedziby = &wawel;

	wawel.odpowiedz();
	niepolomice.odpowiedz();
	zamek::gdzie_krol();

	cout << "\nBawimy sie teraz klasa szablonowa szata<int>\n";
	szata<int> luwr("Paryz,(Luwr)");
	szata<int> blois("Blois");

	blois.ii = 1;
	szata<int>::ttt = 555;
	szata<int>::wsk_stolicy = &luwr;

	luwr.odpowiedz();
	blois.odpowiedz();
	szata<int>::funstat();

	cout << "Krol jedzie do Blois" << endl;
	szata<int>::wsk_stolicy = &blois;
	luwr.odpowiedz();
	blois.odpowiedz();
	szata<int>::funstat();

	cout << "\nBawimy sie klasa szablonowa szata<char>\n";
	szata<char> tower("Tower");
	szata<char> windsor("Windsor");

	szata<char>::ii = 12;
	szata<char>::ttt = 'k';
	szata<char>::wsk_stolicy = &tower;

	windsor.odpowiedz();
	tower.odpowiedz();
	szata<char>::funstat();
	cout << "nie zmienilo to sytuacji w zamkach francuskich" << endl;
	luwr.odpowiedz();

	system("pause");
    return 0;
}

