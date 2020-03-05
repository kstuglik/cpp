//#################################################################
// Plik naglowkowy lista_poj.h ####################################

// Sprawdzony na Linuksie,
//    kompilator: GNU gcc version 4.0.2 (SuSE Linux)
//#########################################################


#include <iostream>
using namespace std;


// Dwie deklaracje zapowiadajace. Naprawde potrzebowalismy tylko deklaracji
// szablonu operatora<<, ale poniewaz w niej jest slowo "lista", wiec
// wczesniej trzeba wyjasnic, ze ta "lista" to nazwa innego szablonu

template <class typOBJ>	class lista;

template <class typOBJ> ostream & operator<<(ostream & stru, lista<typOBJ> & spis);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// szablon klasy pojemnikowej ///////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class typOBJ>								// ((1))
class lista
{

	// klasa (struktura) pomocnicza - wezel -------------------
	struct wezel
	{										// ((2))
		typOBJ * wskobj;
		wezel * nastepca;
		// ------------ konstruktor
		wezel(typOBJ & chowany) : nastepca(NULL)
		{
			wskobj = new typOBJ;
			*wskobj = chowany;
		}
		~wezel() { delete wskobj; }
	};
	//---------------------------------------------

	// od razu z tego korzystamy definiujac trzy wskazniki

	wezel *pierwszyW; 			// ((3))
	wezel *ostatniW; 				// ((4))
	wezel *wybranyW; 				// ((5))

public:
	lista()		// ------------- konstruktor
	{
		pierwszyW = wybranyW = ostatniW = NULL;
	}
	~lista();
	//--------------------------------
	void wstaw(typOBJ & obj);							// ((6))

	void usun();
	//--------------------------------------------------------------------

	typOBJ & co_na_wybranym()			// jaki obiekt przechowuje ten wezel listy
	{
		return *(wybranyW->wskobj);
	}

	// ------------------- funkcje imitujace iterator -----------------------
	void na_poczatek()						  			// ((7))
	{
		wybranyW = pierwszyW;
	}
	//---------------------------------------
	void za_koniec() 			 						// ((8))
	{
		wybranyW = NULL;
	}
	//---------------------------------------
	wezel * przejdz_na_nastepny() 					// ((9))
	{
		// ustawienie "wybranego" wezla na nastepny
		return (wybranyW = wybranyW->nastepca);
	}
	void nty_wezel(int n);

	//-----------------------------------------------------

	friend
		ostream & operator<<
		//<typOBJ>       // <--- dla VC++ te jedna linie trzeba ujac w komentarz
		(ostream & stru, lista<typOBJ> & x);


private:


	wezel* poprzedni_wezel(wezel* odnosny)
	{
		wezel * goniec;
		// petla od poczatku kolejki, by znalezc przedostatniego
		for (goniec = pierwszyW 				// stad zaczynamy
			;
			goniec->nastepca != odnosny 	 	// dotad chodzimy
			;
			goniec = goniec->nastepca);	 	// akcja przechodzenia
		return goniec;
	}

	void daje_na_poczatek(wezel* nowyW);
	void daje_w_srodku(wezel* nowyW);
	void daje_na_koniec(wezel* nowyW);

	void usuwam_pierwszy();
	void usuwam_ostatni();
	void usuwam_ze_srodka();
};

///////////////////////////////////////////////////////////////
template <class typOBJ>
void lista<typOBJ>::wstaw(typOBJ & obj)				// ((10))
{
	// uwaga wstawiamy PRZED wybranym wezlem
	// w rezultacie ten wybrany bedzie odtad o 1 dalej

	wezel * nowyW = new wezel(obj);			//definicja wezla
											// w ktorym od razu umieszczamy w nim informacje o przedmiocie


											// --------------teraz zajmujemy sie wpieciem tego wezla do listy ---
	if (wybranyW != NULL) 		// jesli to nie na koncu listy-------------
	{
		// to moga byc dwie sytuacje: 	// ((11))
		if (wybranyW == pierwszyW)
		{
			daje_na_poczatek(nowyW);
		}
		else
		{
			daje_w_srodku(nowyW); 	// jesli to gdzies w srodku listy
		}
	}
	else 					// tzn. jesli wstawiamy na koncu listy ---------
	{
		daje_na_koniec(nowyW);
	}
}
/*************************************************************/
template <class typOBJ> 					 		// ((12))
void lista<typOBJ>::daje_na_poczatek(wezel * nowyW)
{
	nowyW->nastepca = wybranyW;
	pierwszyW = nowyW;
	wybranyW = nowyW;
}
/*************************************************************/
template <class typOBJ>
void lista<typOBJ>::daje_w_srodku(wezel * nowyW)	// ((13))
{
	// znalezienie poprzednika do biezacego i wpisanie mu nowego nastepcy
	poprzedni_wezel(wybranyW)->nastepca = nowyW;
	nowyW->nastepca = wybranyW; // wybrany - to nastepca nowego
}
/*************************************************************/
template <class typOBJ>
void lista<typOBJ>::daje_na_koniec(wezel * nowyW)
{
	if (!pierwszyW)
	{ 			// jesli nic nie ma na liscie 		((14))
		pierwszyW = nowyW;
	}
	else
	{ 					// na liscie juz cos jest			((15))
		ostatniW->nastepca = nowyW;
	}
	ostatniW = nowyW;
	// (a wybranyW niech nadal ma NULL)
}

/*************************************************************/
template <class typOBJ>
void lista<typOBJ>::usun() 		// usuniecie wezla wybranego 		((16))
{
	if (!wybranyW)return; 			// NULLa nie usuwa sie

	if (wybranyW == pierwszyW)
	{ 								// czyli mamy usunac pierwszy
		usuwam_pierwszy();
	}
	else							// czyli mamy usunac pozniejszy // ((17))
	{
		// tutaj wyrozniamy dwie sytuacje:
		if (wybranyW == ostatniW) // jesli usuwany jest ostatni
		{
			usuwam_ostatni();
		}
		else
		{
			usuwam_ze_srodka(); 	// jesli to zwykle kasowanie w srodku
		}
	}
}
/*************************************************************/
template <class typOBJ>
void lista<typOBJ>::usuwam_pierwszy()			// ((18))
{
	pierwszyW = pierwszyW->nastepca;
	delete wybranyW;
	wybranyW = pierwszyW;
	if (pierwszyW == NULL) ostatniW = NULL; // gdy usuniety byl jedynym
}
/*************************************************************/
template <class typOBJ>
void lista<typOBJ>::usuwam_ostatni() 			// ((19))
{
	// dobrze najpierw znalezc poprzedni wezel
	wezel * poprzW;
	poprzW = poprzedni_wezel(wybranyW);

	poprzW->nastepca = NULL;
	ostatniW = poprzW;
	delete wybranyW;
	wybranyW = NULL;
}
/*************************************************************/
template <class typOBJ>
void lista<typOBJ>::usuwam_ze_srodka() 			// ((210))
{
	// dobrze najpierw znalezc poprzedni wezel
	wezel * poprzW;
	poprzW = poprzedni_wezel(wybranyW);

	poprzW->nastepca = wybranyW->nastepca;
	delete wybranyW; 			   					// ((21))
	wybranyW = poprzW;

}
/*************************************************************/
/*************************************************************/
template <class typOBJ> 							// ((23))
lista<typOBJ>::~lista()
{
	for (wybranyW = pierwszyW; wybranyW; )
	{
		wezel *pamietnik;
		// zanim skasuje sie wezel konieczne jest
		// odczytanie (i zapamietanie), gdzie jest jego nastepca
		pamietnik = wybranyW->nastepca;

		delete wybranyW;
		wybranyW = pamietnik; 		// skok do nastepcy
	}
}
/*************************************************************/
template <class typOBJ>
void lista<typOBJ>::nty_wezel(int n)			 	// ((24))
{
	na_poczatek();
	for (int i = 0; i < n; i++)
	{
		przejdz_na_nastepny();
	}
}
/*************************************************************/
template <class typOBJ> 							// ((25))
ostream & operator<<(ostream & stru, lista<typOBJ> & spis)
{

	typename lista<typOBJ>::wezel * skoczek = spis.pierwszyW;

	for (int i = 0; skoczek; i++, skoczek = skoczek->nastepca)
	{
		stru << i << ") " << *(skoczek->wskobj) << " ";
	}
	stru << endl;
	return stru;
}


// zalecane jest powiedzenie (w tej funkcji powyzej,
// ze lista<typOBJ>::wezel to nie jest nazwa skladnika
// tylko nazwa typu zdefiniowanego w szablonie lista
// - stad zalecane jest uzycie slowa "typename"
