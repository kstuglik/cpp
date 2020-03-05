#include "stdafx.h"
#include "iostream"
#include <string>
#include <fstream>

using namespace std;

void generateTab(int tab[5][5]){
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			tab[i][j] = (i + 1)*(j + 1);
		}
	}
}

void displayTab(int tab[5][5]){
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++){
			cout << tab[i][j] << " ";
		}
		cout << endl;                                  
	}
}

void saveToFile(string namePath, int tab[5][5], int col, int row){
	ofstream outputfile;
	outputfile.open(namePath, ios::out);
	if (!(col < 0 || col>5 || row < 0 || row>5)){
		for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < col; j++){
						outputfile << tab[i][j] << " ";   //Space between each character
					}	
					outputfile << endl;                           //New line for each row
				}
	}	
	else{
		cout << "Podales nieprawidlowe wymiary tabliy do zapisania!";
	}
	outputfile << "wymiary tablicy 2D: " << row << " x " << col;
	outputfile.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int row = 5, col = 5;
	int row2, col2, tab[row][col];
	string namePath;

	cout << "Zadanie nr 3\n";
	cout << "Tablica 2D ma teraz wymiar: "<<row<<" x "<<col<<"\n";
	cout << "Jej zawartosc zostala juz wygenerowana\n";
	generateTab(tab);
	displayTab(tab);
	cout << "Aby moc ja zapisac jestes proszony o podanie kilku parametrow: \n";
	cout << "Podaj nazwe pliku do którego maj¹ zostaæ wygenerowane wyniki: ";
	cin >> namePath;
	cout << "Jaki powinien byc rozmiar tablicy, ktora zostanie zapisana do pliku?\n";
	cout << "Liczba wierszy: ";
	cin >> row2;
	cout << "Liczba kolumn: ";
	cin >> col2;

	saveToFile(namePath+".txt", tab, col2, row2);
	cout << "Gotowe!\n";

	system("pause");
	return 0;
}
