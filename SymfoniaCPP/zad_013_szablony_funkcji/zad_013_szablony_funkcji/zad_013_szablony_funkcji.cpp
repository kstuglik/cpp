// zad_013_szablony_funkcji.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void wywolanie(char** ss) {
	cout << "wywolujemy ducha " << *ss << endl
		<< "kto mnie wolal, czego chcial?" << endl
		<< "ubralem sie w com ta mial.." << endl;
}

void wywolanie(char* kto, char* x) {
	cout << "CQ,CQ de " << kto << ", wywolanie ogolne w pasmie " << x << endl;
}

template<class typ>
typ wywolanie(typ obiekt) {
	return -(obiekt);
}

template<class typek>
typek wywolanie(typek obiekt, int ile_pow) {
	return (-ile_pow * obiekt);
}



int main()
{
	cout << "rezultaty wywolania filmow" << endl;
	cout << "pierwszy: " << wywolanie(5) << endl
		<< "drugi: " << wywolanie(3.14) << endl;
	cout << "powiekszenie roznuch filmow: " << wywolanie(5, 2) << "," << wywolanie(3.14, 2) << endl;
	char* wsk[30] = { "Ludwika Filipa" };
	wywolanie(wsk);
	wywolanie("SP9CG", "3.5MHz");
	system("pause");
    return 0;
}

