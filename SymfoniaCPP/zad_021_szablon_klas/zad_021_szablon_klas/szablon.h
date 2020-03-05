#pragma once
#include "stdafx.h"
#include<iostream>
using namespace std;

template<class typ>
class aktor {
	typ skladnik;
public:
	void funkcja_mala(char* t) {
		cout << "funkcja_mala: " << t << endl;
	}
	void funkcja_duza(char* opis);
};

template<class typ>
void aktor<typ>::funkcja_duza(char* opis) {
	cout << "funkcja_duza: " << opis << endl;
}