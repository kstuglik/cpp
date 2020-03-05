//szablon klasy pojemnikowej

template<class typ>
class lista {//szablon klasy lista jednokierunkowa, lub inaczej mówi¹c pojedynczo ³¹czona
	//klasa pomocnicza - wezel
	struct wezel//jest szablonem klas
	{
		typ* wsk;//do wpisania adresu jakiegos z obiektow
		wezel* nastepca;//do wpisania adresu nastepnego wezla, wskaznik do innego wezla tego samego typu
		wezel():nastepca(NULL),wsk(NULL){}//konstruktor
	};
	//wsrod skladnikow pojemnika nie ma wezlow a jedynie  3 wskazniki do nich
	//3 wskazniki sa potrzebne do zarzadzania obiektami
	wezel* pierwszyW;//wskaznik do wezla uznawanego za pierwszy wezel listy
	wezel* ostatniW;//wskaznik do ostatniego wezla na liscie
	wezel* wybranyW;//wskaznik pomocniczy, uzywany do przemieszczania sie po roznych wezlach
	//np by wskazac wezel, ktory nastepnie zostanie usuniety
	//jestli chodzi o dodanie, to po wskazaniu miejsca, nowy zostanie dodany PRZED pokazywanym wezlem
	//dopisanie na samym koncu, wskaznik wybranyW powinien zawierac NULL
public:
	lista() {
		pierwszyW = wybranyW = ostatniW = NULL;
	}
	~lista();
	void wstaw(typ& obj);//deklaracja; argumentem jest referencja chowanego przedmiotu
	void usun();
	typ& co_na_wybranym(){
		return *(wybranyW->wsk);
	}
	//funkcje imituj¹ce iterator
	void na_poczatek() {
		wybranyW = pierwszyW;
	}
	void za_koniec() {//chodzi np wstawiania za ostatnim elementem listy
		wybranyW = NULL;
	}
	wezel* przejdz_na_nastepny() {//przesuniecie wskaznika wybranyW na nastepny po nim wezel
		//ustawienie wybranego wezla na nastepny
		return (wybranyW = wybranyW->nastepca);
	}
	void nty_wezel(int n);
	template<class typ>
	friend ostream& operator << (ostream& s, lista<typ>& x);
private:
	wezel* poprzedni_wezel(wezel* odnosny)
	{
		//znalezienie wezla poprzedniego do tego, którego adres wyslemy jej jako argument
		//harcerzowi polecono przebiegnac trase gry terenowej, ma on poszukac wezla poprzedzajacego odnosny wezel
		wezel* goniec;
		//petla od poczatku kolejki, by znalezc przedostatniego
		//skakanie z wezla na wezel
		for (goniec = pierwszyW
			;//stad zaczynamy
			goniec->nastepca != odnosny
			;//dotad chodzimy
			goniec = goniec->nastepca);
		return goniec;//funkcja zwraca adres wezla poprzedzajacego
	}
	void daje_na_poczatek(wezel* nowyW);
	void daje_w_srodku(wezel* nowyW);
	void daje_na_koniec(wezel* nowyW);

	void usuwam_pierwszy();
	void usuwam_ostatni();
	void usuwam_ze_srodka();
};

template<class typ>
void lista<typ>::wstaw(typ& obj) {
	wezel* nowyW = new wezel;//nowy wezel
	nowyW->wsk = &obj;//wpisujemy adres chowanego obiektu/przedmiotu
	//jest wezel, ale jeszczenie wpiety do listy
	//wpiecie wezla do listy
	//wybranyW - w ktorym miejscu postanowilismy umiescic nowy przedmiot
	if (wybranyW != NULL) {//jesli to nie na koncu listy
		//PRZED wezlem o podanym adresie chcemy wstawiæ ten swój wêze³
		if (wybranyW == pierwszyW) {//sam poczatek listy
			daje_na_poczatek(nowyW);
		}
		else {//inne miejsce w œrodku listy
			daje_w_srodku(nowyW);
		}
	}
	else {//wybranyW==NULL
		daje_na_koniec(nowyW);
	}
}

template<class typ>
void lista<typ>::daje_na_poczatek(wezel* nowyW) {
	nowyW->nastepca = wybranyW;//wpisanie nowemu wezlowi jako nastepcy adres tego, ktory dotychczas byl pierwszym wezlem
	//pokazywal tez na niego wskaznik wybranyW
	pierwszyW = nowyW;//pierwszyW dostaje adres tego nowego wezla
	wybranyW = nowyW;
}

template<class typ>
void lista<typ>::daje_w_srodku(wezel* nowyW) {
	//znalezienie poprzednika do biezacego i wpisanie mu nowego nastepcy
	poprzedni_wezel(wybranyW)->nastepca = nowyW;//trzeba znalezc wezel poprzedzajacy i tam wpisac adres nowego nastepcy - nowego wezla
	//karteczki-wezly nie zawieraja adresu poprzednika
	nowyW->nastepca = wybranyW;//w nowym wezle wpisujemy jako adres nastepcy adres tego wybranego
	//wybrany to nastepca nowego
}

template<class typ>
void lista<typ>::daje_na_koniec(wezel* nowyW) {
	if (!pierwszyW) {//jesli nic nie ma na liœcie
		pierwszyW = nowyW;//nowyW jest jednoczesnie pierwszym i ostatnim wezlem
	}
	else {//na liœcie ju¿ coœ jest
		ostatniW->nastepca = nowyW;//dotychczasowemu ostatniemu wezlowi wpisujemy jako adres nastepnego - adres tego nowego
	}
	ostatniW = nowyW;
	//a wybrabyW nadal niech ma NULL
}

template<class typ>
void lista<typ>::usun() {//usuniecie wybranego wezla - wybranyW
	if (!wybranyW)return;//NULLa nie usuwa sie
	//jezeli wybranyW zawiera adres jakiegos konkretnego wezla to
	if (wybranyW == pierwszyW) {
		usuwam_pierwszy();
	}
	else {
		if (wybranyW == ostatniW) {
			usuwam_ostatni();
		}
		else {
			usuwam_ze_srodka();//jesli to zwykle kasowanie w srodku
		}
	}
}

template<class typ>
void lista<typ>::usuwam_pierwszy() {
	pierwszyW = pierwszyW->nastepca;//ustawiamy tak by pokazywal na nastepce
	delete wybranyW;//likwidujemy wybrany wezel
	wybranyW = pierwszyW;
	if (pierwszyW == NULL) {
		ostatniW = NULL;//gdy usuniety byl jedynym
	}
}

template<class typ>
void lista<typ>::usuwam_ostatni() {
	//dobrze najpierw znalezc poprzedni wezel
	wezel* poprzW;
	poprzW = poprzedni_wezel(wybranyW);

	poprzW->nastepca = NULL;
	ostatniW = poprzW;
	delete wybranyW;
	wybranyW = NULL;
}

template<class typ>
void lista<typ>::usuwam_ze_srodka() {
	//dobrze najpierw znalezc poprzedni wezel
	wezel* poprzW;
	poprzW = poprzedni_wezel(wybranyW);

	poprzW->nastepca = wybranyW->nastepca;//poprzednikowi mowimy, ze jego nowy nastepca jest nastepca wybranego wezla
	delete wybranyW;//likwidujemy nie potrzebny wezel
	wybranyW = poprzW;
}

template<class typ>
lista<typ>::~lista() //to tak jakby druzynowy przeszedl ostatni raz trase i niszczyl napotkane kartki, 
//wczesniej musial zapamietac gdzie ma szukac nastepnej
{
	for (wybranyW = pierwszyW; wybranyW;) 
	{
		wezel *pamietnik;//zanim skasuje sie wezel konieczne jest
		//odczytanie i zapamietanie gdzie jest jego nastepca
		pamietnik = wybranyW->nastepca;
		delete wybranyW;
		wybranyW = pamietnik;//skok do nastepnego
	}
}

template<class typ>
void lista<typ>::nty_wezel(int n) {//pozwala ustawic wskaznik na okreslony wezel
	na_poczatek();//wskaznik wybranyW ustawiony na poczatek
	for (int i = 0; i < n; i++) {
		przejdz_na_nastepny();
	}
}

template<class typ>
ostream& operator << (ostream& s, lista<typ>& x) {
	lista<typ>::wezel* skoczek = x.pierwszyW;//definicja roboczego wskaznika wezlow skoczek
	for (int i = 0; skoczek; i++, skoczek = skoczek->nastepca) {//przedstawienie wszystkich kolejnych obiektów na ekranie
		s << i << ") " << *(skoczek->wsk) << " ";//obiekt przchowywany - *(skoczek->wsk)
	}
	s << endl;
	return s;
}