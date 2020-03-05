#include "stdafx.h"
#include "iostream"
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char c, coSzukasz;
	cout << "Zadanie nr 5\n";
	
	cout << "Podaj znak, ktorego wystapienie ma byc zliczane: ";
	coSzukasz = getchar();
	int nNum = 0;

	fstream file;
	string namePath = "test.txt";
	file.open(namePath, ios::in);

	while (!file.eof())
	{
		while (file.good()){
		file.get(c);
		if (c == coSzukasz)nNum++;
		}
	}

	file.close();
	//tutaj sprawdzam wystapienia znaku w nazwie pliku
	for (int i = 0; i < namePath.size(); i++)
		if (namePath[i] == coSzukasz) nNum++;

	cout << "Znak " << coSzukasz << " wystepuje: " << nNum << " razy"<< endl;

	system("pause");
	return 0;
}

