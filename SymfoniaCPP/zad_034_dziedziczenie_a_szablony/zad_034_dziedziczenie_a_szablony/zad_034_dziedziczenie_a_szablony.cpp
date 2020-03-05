// zad_034_dziedziczenie_a_szablony.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class typ>
class para {
protected:
	typ lewy;
	typ prawy;
	int xx;
public:
	para(typ el, typ pe) :lewy(el), prawy(pe) {
		xx = 7;
	}
};

template<class typ>
class wspolrzedne :public para<float> {
	typ coto;
	int xx;
public:
	wspolrzedne(typ c, float x = 0, float y = 0) :para<float>(x, y), coto(c) {
		xx = 1;
	}
	void przesun_o(float dx, float dy) {
		lewy += dx;
		prawy += dy;
	}
	void gdzie_jestes() {
		cout << coto << " jest w polozeniu x = " << lewy << ", y = " << prawy << endl;
	}
	void fun() {
		cout << "wlasna nazwa xx = " << xx << ", zaslonieta nazwa xx = " << para<float>::xx << endl;
	}
};

class kwadrat {
public:
	float dl_boku;
	kwadrat(float bok) :dl_boku(bok) {}
	char *czego() {
		return "kwadratu";
	}
	friend ostream& operator<<(ostream &s, kwadrat kkk) {
		s << kkk.czego() << " o boku " << kkk.dl_boku;
		return s;
	}
};

int main()
{
	wspolrzedne<char> punkt('P');
	punkt.przesun_o(10.2, 12.1);
	punkt.gdzie_jestes();


	wspolrzedne<char*> miasto("Genewa", 5, 45);
	miasto.gdzie_jestes();

	kwadrat czerwony(10);

	wspolrzedne<kwadrat> wkc(czerwony);
	wkc.gdzie_jestes();
	wkc.przesun_o(4, 3);
	wkc.gdzie_jestes();
	wkc.fun();

	system("pause");
    return 0;
}

