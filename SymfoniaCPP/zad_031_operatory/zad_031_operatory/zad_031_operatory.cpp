// zad_031_operatory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class zesp {
	float re, im;
public:
	zesp(float r = 0, float i = 0) :re(r), im(i) {}
	friend ostream & operator<<(ostream &, zesp &);
};

ostream &operator<<(ostream & s, zesp & obj) {
	s << "[" << obj.re << "," << obj.im << "]";
	return s;
}

template<class typ, int stala>
class szafa {
	typ tablica[stala];
public:
	int dlug() { return stala; }
	void schowaj(typ obj, int nr) {
		tablica[nr] = obj;
	}
	typ oddaj() { return tablica[nr]; }
	friend ostream & operator<<(ostream & s, szafa<typ, stala> & obj) {
		for (int i = 0; i < obj.dlug(); i++) {
			s << obj.tablica[i] << " ";
		}
		return s;
	}

};

int main()
{
	zesp z1;
	zesp z2(1.1f, 7.5f);
	cout << "oto nasze liczby zespolone: z1 = " << z1 << ", z2 = " << z2 << endl;

	szafa<char, 3> cc;
	cc.schowaj('L', 0);
	cc.schowaj('x', 2);
	cc.schowaj('u',1);
	cout << "wewnatrz cc jest: " << cc << endl;

	szafa<float, 2> ff;
	ff.schowaj(3.14f, 0);
	ff.schowaj(2002, 1);
	cout << "wewnatz ff jest: " << ff << endl;

	szafa<zesp, 2> zzz;
	zzz.schowaj(z1, 0);
	zzz.schowaj(z2, 1);
	cout << "wewnarz zzz jest: " << zzz << endl;

	system("pause");
    return 0;
}

