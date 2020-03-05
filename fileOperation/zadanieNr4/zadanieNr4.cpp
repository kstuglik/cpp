#include "stdafx.h"
#include "iostream"
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Zadanie nr 4\n";

	char c;
	int nNum = 0;
	int consonants = 0;
	int allChar = 0;

	fstream file;
	file.open("test.txt",ios::in);

	while (!file.eof())
	{
		allChar++;
		file.get(c);
		c = tolower(c);

		if (c == 'a' || c == '¹' || c == 'e' || c == 'ê' || c == 'i' || c == 'o' || c == 'u' || c == 'ó' || c == 'y'){
			nNum++;
		}
		else if ((c >= 'a'&& c <= 'z') || (c >= 'A'&& c <= 'Z')){
			++consonants;
		}
	}

	file.close();

	cout <<"Samoglosek jest: "<< nNum<<endl;
	cout << "Spolglosek jest: " << consonants << endl;
	cout << "Wszystkich znakow jest: " << allChar << endl;

	system("pause");
	return 0;
}

