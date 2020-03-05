// zad_021_szablon_klas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "szablon.h"
using namespace std;

void poslaniec();

int main()
{
	aktor<int> obj1;
	obj1.funkcja_mala(" z main");
	obj1.funkcja_duza(" z main");
	poslaniec();
    return 0;
}

