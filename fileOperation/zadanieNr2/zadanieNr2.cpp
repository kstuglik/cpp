#include "stdafx.h"
#include "iostream"
#include <string>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	char c;
	srand(time(NULL));
	const int col = 10, row = 10;
	char tab[row][col];

	wcout << "Zadanie nr 2\n";
	cout << "W tym zadaniu do pliku 'text.txt' dopisywany jest tekst - wiersze z losowo wygenerowanymi litery\n";
	cout << "Do pliku dodano: " << row << " wierszy" << endl;

	string namePath = "test.txt";
	ofstream outputfile;
	outputfile.open(namePath, ios::app);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			n = rand() % 26;
			c = (char)(n + 65);
			tab[i][j] = c;
			outputfile << tab[i][j];
		}

		outputfile << endl;
	}

	outputfile.close();

	system("pause");
	return 0;
}
