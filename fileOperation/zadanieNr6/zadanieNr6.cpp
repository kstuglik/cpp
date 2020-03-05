#include "stdafx.h"
#include "iostream"
#include <string>
#include <fstream>

using namespace std;

struct User{
	string name;
	string surName;
	string noPesel;
	double value1;
	double value2;
	void printUser(){cout << name << " " << surName << " " << noPesel << " " << value1 << " " << value2;}
};

void readFromFile(string fileName, User tab[]){
	int i = 0;
	ifstream myfile;
	myfile.open(fileName, ios::in);
	string line;
	if (myfile.good() == false)
	{
		cout << "Nie udana próba otwarcia pliku!";
		getchar();
	}

	//if (myfile.is_open())
	else
	{
		while (!myfile.eof())
		{
			myfile >> tab[i].name;
			myfile >> tab[i].surName;
			myfile >> tab[i].noPesel;
			myfile >> tab[i].value1;
			myfile >> tab[i].value2;
			i += 1;
		}
		myfile.close();
	}
}

void searchYoungest(User tab[]){
	string searchYear,tempYear,searchMonth,tempMonth,searchDay,tempDay;
	int year, year2,month, month2,day, day2;
	int id = 0;
	int tempId = 0;
//substr(odIndex,ile)
	searchYear = (tab[id].noPesel).substr(0, 2);
	searchMonth = (tab[id].noPesel).substr(2, 2);
	searchDay = (tab[id].noPesel).substr(4, 2);

//atoi(convert string to int)
	year = atoi(searchYear.c_str());
	month = atoi(searchMonth.c_str());
	day = atoi(searchDay.c_str());

	for (int i = 1; (tab[i].name).length() >= 3;i++){

		tempDay = (tab[i].noPesel).substr(4, 2);
		tempMonth = (tab[i].noPesel).substr(2, 2);
		tempYear = (tab[i].noPesel).substr(0, 2);

		year2 = atoi(tempYear.c_str());
		month2 = atoi(tempMonth.c_str());
		day2 = atoi(tempDay.c_str());

		int czyNewPesel = atoi(tempMonth.c_str());
		czyNewPesel /= 20;

		if ((czyNewPesel == 0) || (czyNewPesel == 1)){

			int czyNewPesel2 = month;
			czyNewPesel2 /= 20;

			if ((czyNewPesel2 == 0) || (czyNewPesel2 == 1)){
				if (year2 > year){tempId = i;}
				if (year2 == year)
				{
					if (month2 > month){tempId = i;}
					if (month2 == month){
						if (day2 > day){tempId = i;}
						if (day2 == day){cout << "wyglada na to ze jest kilka osob o takiej samej dacie urodzin!\n";}
					}
				}
			}
			tempId = i;
		}
		if (year2 > year){tempId = i;}
		if (year2 == year)
		{
			if (month2 > month){tempId = i;}
			if (month2 == month){
				if (day2 > day){tempId = i;}
				if (day2 == day){cout << "wyglada na to ze jest kilka osob o takiej samej dacie urodzin!\n";}
			}
		}
		if (tempId > id){
			year = year2;
			month = month2;
			day = day2;
			id = tempId;
		}
	}
	cout << "Najmlodsza osoba to: " << tab[id].name << " " << tab[id].surName << endl;
}

void getUsers(User tab[]){
	cout << "W tabeli znajduja sie nastepujace osoby:\n";
	for(int i=0;i<10;i++){
		if ((tab[i].name).length()>=3){
		tab[i].printUser();
		cout << endl;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Zadanie nr 6\n";
	User tabUsers[20];
	readFromFile("test.txt", tabUsers);
	getUsers(tabUsers);
	searchYoungest(tabUsers);
	system("pause");
	return 0;
}

