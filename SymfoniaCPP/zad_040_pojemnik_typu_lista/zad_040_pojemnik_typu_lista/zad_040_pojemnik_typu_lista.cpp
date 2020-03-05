// zad_040_pokemnik_typu_lista.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;

#include "lista_poj.h"
#include "osoba.h"

int main()
{
	osoba
		matematy("matematyk"),
		muzyk("chopin"),
		biochemik("biochemik"),
		astronom("astronom");

	lista<osoba> slawni;//definicja, z szablonu lista zostanie wyprodukowana klasa pojemnika typu lista, 
	//potrafi¹ca zajmowaæ siê obiektami klasy osoba, powo³a do ¿ycia obiekt takiej klasy szablonowej - slawni
	cout << "sizeof(slawni) = " << sizeof(slawni) << endl;//3 wskazniki po 4B = 12B
	slawni.wstaw(biochemik);
	cout << slawni;

	slawni.na_poczatek();
	slawni.wstaw(matematy);
	cout << slawni;

	slawni.za_koniec();
	slawni.wstaw(astronom);
	cout << slawni;

	slawni.nty_wezel(1);
	slawni.wstaw(muzyk);
	cout << slawni;

	cout << "zle wpsiany Chopin, skorygujemy to\n";

	slawni.nty_wezel(1);
	slawni.usun();
	cout << slawni;

	slawni.nty_wezel(0);
	slawni.wstaw(muzyk);
	cout << slawni;

	cout << "wskaznik wybranyW jest na: " << slawni.co_na_wybranym();
	
	float c1 = 1.1f,
		c2 = 2.2f,
		c3 = 3.3f;
	lista<float> czynniki;
	cout << "\n---sizeof(czynniki) = " << sizeof(czynniki) << endl;
	czynniki.wstaw(c1);
	czynniki.wstaw(c2);
	czynniki.wstaw(c3);
	cout << "takie mam spisane czynniki:\n" << czynniki;
	czynniki.nty_wezel(1);
	czynniki.usun();
	cout << "teraz:\n" << czynniki;
	
	system("pause");
}

