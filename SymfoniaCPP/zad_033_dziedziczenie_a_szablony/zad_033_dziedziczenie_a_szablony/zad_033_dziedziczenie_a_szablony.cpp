// zad_033_dziedziczenie_a_szablony.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

class grupa {
	int ile;
public:
	grupa(int n) { ile = n; }
	void bardzo_skomplikowana_funkcja(char tonacja);
	void przywodca() { cout << "mowi przywodca grupy\n"; }
};

void grupa::bardzo_skomplikowana_funkcja(char tonacja) {
	cout << "grupa " << ile << " elementow spiewa choral gredorianski\n"
		<< "w tonacji " << tonacja << "++" << endl;
	Beep(1500 + (int)tonacja * 40,200);
	Sleep(200);
}

template<class typ>
class tuzin : public grupa {
	typ element[12];
public:
	tuzin(typ wart): grupa(12){
		for (int i = 0; i < 12; i++)
			element[i] = wart;
	}
	void przyjmij(typ a, int nr) { element[nr] = a; }
	typ oddaj(int nr) { return element[nr]; }
	void przywodca() { cout << "mowi przywodca tuzina!\n"; }
	void czarna_robota(char m) {
		bardzo_skomplikowana_funkcja(m);
		cout << "z zakresu klasy\n";
		przywodca();
		grupa::przywodca();
	}

};

int main()
{
	tuzin<char> szyfr('*');
	szyfr.przyjmij('z', 5);
	cout << "w piatym elemencie jest " << szyfr.oddaj(5) << endl;
	szyfr.czarna_robota('C');
	tuzin<int> studenci(0);
	studenci.czarna_robota('H');
	cout << "spoza zakresu klasy\n";
	studenci.przywodca();
	studenci.grupa::przywodca();
	system("pause");
    return 0;
}

