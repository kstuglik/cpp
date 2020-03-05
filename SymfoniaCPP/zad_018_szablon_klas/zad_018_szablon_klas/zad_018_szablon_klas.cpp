// zad_018_szablon_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

template<class typ>
class wieza {
	char* nazwa;
	typ dana;
public:
	wieza(char* na, typ d) :nazwa(na), dana(d) {}
	friend ostream & operator<<(ostream& stream, wieza<typ> & ob);
	void wypisz(){ cout << nazwa << ", dana = " << dana << endl; }
};

template<class typ>
void prostak(wieza<typ>obiekt){
	obiekt.wypisz();
}

template<class typ>
ostream & operator<<(ostream& stream, wieza<typ> & ob) {
	stream << ob.nazwa << ", dana = " << ob.dana << endl;
	return stream;
}

int main()
{
	wieza<int> tadek("ON", 123);
	wieza<int> telimena("ONA", 322);

	//wieza<char> jurand("TATA", 'J');
	//wieza<char> danuska("CORKA", 'D');

	prostak(telimena);
	//prostak(jurand);
	
	//cout << tadek;
	//cout << jurand;

	double pi = 3.14;
	//cout << tadek << pi << " i " << telimena;
	system("pause");
    return 0;
}

