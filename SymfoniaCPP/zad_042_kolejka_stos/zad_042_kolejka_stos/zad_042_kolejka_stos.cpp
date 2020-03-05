// zad_042_kolejka_stos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class typ>
class stos {
	typ *tab;
	int pojemnosc;
public:
	int ile_obiektow;
	stos() {
		ile_obiektow = 0;
		pojemnosc = 10;
		tab = new typ[pojemnosc];
	}
	~stos() {
		delete[] tab;
	}
	void push(typ nowy);
	typ pop();
	friend ostream& operator<<(ostream& s, stos<typ>& x) {
		for (int i = 0; i < x.ile_obiektow; i++) {
			s << x.tab[i] << " ";
		}
		s << endl;
		return s;
	}
private:
	int powieksz_rozmiar_stosu();
};

template<class typ>
void stos<typ>::push(typ nowy) {
	if (ile_obiektow == pojemnosc) {
		cout << "(stos sie zapelnil, rozszerzam sie)\n";
		powieksz_rozmiar_stosu();
	}
	tab[ile_obiektow++] = nowy;
}

template<class typ>
typ stos<typ>::pop() {
	if (ile_obiektow <= 0) {
		cout << "***Alarm, ze na stosie jest pusto!***\n";
		return 0;
	}
	return (tab[--ile_obiektow]);
}

template<class typ>
int stos<typ>::powieksz_rozmiar_stosu() {
	int dodatek = 10;
	typ* nowaTAB = new typ[pojemnosc + dodatek];
	if (nowaTAB == NULL) {
		return 0;
	}
	for (int i = 0; i < ile_obiektow; i++) {
		nowaTAB[i] = tab[i];
	}
	pojemnosc += dodatek;
	delete tab;
	tab = nowaTAB;
	return 1;
}

int main()
{
	stos<int> sss;
	sss.push(0);
	sss.push(1);
	sss.push(2);
	sss.push(3);
	for (int i = 4; i < 24; i++) {
		sss.push(i);
	}
	cout << sss;
	int m = sss.pop();
	int k = sss.pop();
	cout << "zdjelismy ze stosu liczby m=" << m << " i k=" << k << endl;
	cout << "kolejno zdejmujemy nastepne\n";
	cout << sss.pop() << endl;;
	cout << sss.pop() << endl;
	cout << sss.pop() << endl;
	while (sss.ile_obiektow) {
		cout << sss.pop() << " ";
	}
	cout << "probujemy zdjac jeszcze jedea\n";
	cout << sss.pop() << " ";
	
	cout << "-----------jeszcze raz cos ladujemy..\n";
	for (int i = 0; i < 50; i++) {
		sss.push(10 * i);
	}
	
	stos<int> drugi;
	cout << "przeladowujemy zdejmujac z pierwszego stosu\ni ladujac na drugi\n";
	for (int i = 0; i < 10; i++) {
		drugi.push(sss.pop());
	}
	cout << "oto kolejne zdejmowania z drugiego stosu:\n";
	for (int i = 0; i < 7; i++) {
		cout << drugi.pop() << " ";
	}
	char* slowo[] = { "stolica","Nepalu","jest","kathamandu" };
	
	stos<char*> zzzz;
	for (int i = 0; i < 4; i++) {
		zzzz.push(slowo[i]);
	}
	cout << "\nprzy zdejmowaniu ze stosu czytamy\n";
	for (int i = 0; i < 4; i++) {
		cout<<zzzz.pop()<<" ";
	}
	cout << endl;
	system("pause");
}

