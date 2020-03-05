// Sprawdzony na Linuksie,   kompilator: GNU gcc version 4.0.2 (SuSE Linux)
#include <iostream>
using namespace std;
#include <cstring>      // dla funkcji strcpy

/////////////////////////////////////////////////
class osoba												// ((1))
{
	char nazwisko[30] ;
public:
	osoba(const char* n= NULL)
	{
	  if(n) strcpy(nazwisko, n);
	  else nazwisko[0] = 0;
	}
	//----------------------------------
	friend
	ostream & operator<<(ostream &s, const osoba & o);

	friend
	ostream & operator<<(ostream &s, const osoba * wsk);
};
/////////////////////////////////////////////////
ostream& operator<<(ostream &s, const osoba & o)  		// ((2))
{
	s << o.nazwisko ;
	return s ;
}
/*************************************************************/
ostream& operator<<(ostream &s, const osoba* wsk) 		// ((3))
{
	s << wsk->nazwisko ;
	return s ;
}
