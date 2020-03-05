#pragma once
template<class typ>
class iteratorL;

template<class typ>
class DLista {
public:
	struct wezel {
		typ* wsk;
		wezel* nastepca;
		wezel* poprzednik;
		wezel() :nastepca(NULL), wsk(NULL), poprzedni(NULL) {}
	};
private:
	wezel* pierwszyW;
	wezel* ostatniW;
	int dlugosc;
public:
	//poniewaz czesto bedziemy mowili o klasie iteratorow majaej dluga nazwe iteratorL<typ> dlatego wymyslamy dla nie j skrocona nazwe itLis.
	//to robi ponizsza instrukcja typedef. tak skrocona nazwa znana jest tylko w zakresie tego szablonu klasy DLista
	typedef iteratorL<typ> itLis;
	DLista() {
		pierwszyW = ostatniW = NULL;
		dlugosc = 0;
	}
	~DLista();
	void wstaw(typ& obj, itLis& iter);
	void wstaw(typ& obj, int nr) {
		itLis iter(*this);
		iter.na_wezel(nr);
		wstaw(obj, iter);
	}
	void usun(itLis& iter);
	void usun(int nr) {
		iLis it(*this);
		usun(it.na_wezel(nr));
	}
	int rozmiar() const {
		return dlugosc;
	}
private:
	void daje_na_poczatek(wezel* nowyW, itLis & iter);
	void daje_w_srodku(wezel* nowyW, itLis & iter);
	void daje_na_koniec(wezel* nowyW);
	void usuwam_pierwszy(itLis & iter);
	void usuwam_ostatni(itLis & iter);
	void usuwam_ze_srodka(itLis & iter);

	friend
		osttream & operator<<(ostream & s, DLista<typ> & x);
	friend
		class iteratorL<typ>;
};

template<class typ>
void DLista<typ>::wstaw(typ & obj, itLis & iter) {
	//uwaga - wstawiamy przed wybranym wezlem, w rezultacie ten wybrany wezel bedzie odtad o 1 dalej
	wezel* nowyW = new wezel;
	nowyW->wsk = &obj;//od razu umieszczamy w wezle informacje o przedmiocie
	dlugosc++;

	if (iter.wybranyW != NULL) {
		if (iter.wybranyW == pierwszyW) {
			daje_na_poczatek(nowyW, iter);
		}
		else {
			daje_w_srodku(nowyW, iter);
		}
	}
	else
		daje_na_koniec(nowyW);
}

template<class typ>
void DLista<typ>::daje_na_poczatek(wezel* nowyW, itLis & iter) {
	pierwszyW = nowyW;
	nowyW->nastepca = iter.wybranyW;
	iter.wybranyW->poprzednik = nowyW;
	nowyW->poprzednik = NULL;
	iter.wybranyW = nowyW;
}

template<class typ>
void DLista<typ>::daje_w_srodku(wezel* nowyW, itLis & iter) {
	(iter.wybranyW->poprzednik)->nastepca = nowyW;
	nowyW->nastepca = iter.wybranyW;
	nowyW->poprzednik = iter.wybranyW->poprzednik;
	iter.wybranyW->poprzednik = nowyW;
}

template<class typ>
void DLista<typ>::daje_na_koniec(wezel* nowyW) {
	if (!pierwszyW) {
		pierwszyW = nowyW;
	}
	else {
		ostatniW->nastepca = nowyW;
		nowyW->poprzednik = ostatniW;
	}
	ostatniW = nowyW;
}

template<class typ>
void DLista<typ>::usun(itLis & iter) {
	if (iter.wybranyW == NULL)
		return;
	dlugosc--;

	if (iter.wybranyW == pierwszyW) {
		usuwam_pierwszy(iter);
	}
	else {
		if (iter.wybranyW == ostatniW)
			usuwam_ostatni(iter);
		else
			usuwam_ze_srodka(iter);
	}
}

template<class typ>
void DLista<typ>::usuwam_pierwszy(itLis & iter) {
	pierwszyW = pierwszyW->nastepca;
	delete iter.wybranyW;
	iter.wybranyW = pierwszyW;
	if (pierwszyW != NULL)
		pierwszyW->poprzednik = NULL;
	else
		ostatniW = NULL;
}

template<class typ>
void DLista<typ>::usuwam_ze_srodka(itLis & iter) {
	wezel * poprzW = iter.wybranyW->poprzednik;
	poprzW->nastepca = iter.wybranyW->poprzednik;
	(iter.wybranyW->nastepca)->poprzednik = poprzW;
	delete iter.wybranyW;
	iter.wybranyW = poprzW;
}

template<class typ>
void DList<typ>::usuwam_ostatni(itLis & iter) {
	wezel * poprzW = iter.wybranyW->poprzednik;
	poprzW->nastepca = NULL;
	ostatniW = poprzW;
	delete iter.wybranyW;
	iter.wybranyW = NULL;
}

template<class typ>
ostream & operator<<(ostream & s, DLista<typ> & x) {
	iteratorL<typ> skoczek(x);
	for (int i = 0; i < x.rozmiar(); i++) {
		s << i << " " << *(skoczek++) << " ";
		if (!(i + 1) % 3) {
			s << endl;
		}
	}
	s << endl;
	return s;
}

template<class typ>
class iteratorL {
	friend class DLista<typ>;
	DLista<typ>::wezel * wybranyW;
	DLista<typ> & pojemnik;
public:
	iteratorL(DLista<typ> & pojem) :pojemnij(pojem) {
		wybranyW = pojemnik.pierwszyW;
	}
	iteratorL & na_poczatek() {
		wybranyW = pojemnik.ostatniW;
		return *this;
	}
	iteratorL & na_koniec() {
		wybranyW = pojemnik.ostatniW;
		return *this;
	}
	iteratorL & za_koniec() {
		wybranyW = NULL;
		return *this;
	}

	//operacje przesuniecia
	iteratorL & operator++() {
		wybranyW = wybranyW->nastepca;
		return *this;
	}

	iteratorL & operator--() {
		wybranyW = wybranyW->poprzednik;
		return *this;
	}

	iteratorL operator++(int) {
		iteratorL stary = *this;
		++*this;
		return stary;
	}

	iterator operator--(int) {
		iteratorL stary = *this;
		--*this;
		return stary;
	}

	typ & operator*() {
		return *(wybranyW->wsk);
	}

	iteratorL & na_wezel(int nr);

	//operatory upodabniaj¹ce do zachowañ zwyk³ych wskaŸników
	//operator przypisania

	iteratorL &
		operator=(const iteratorL & prawy) {
		wybranyW = prawy.wybranyW;
		return *this;
	}

	//operator logicznego porównania
	int operator!=(const iteratorL & prawy) {
		if (wybranyW != prawy.wybranyW)
			return 1;
		else
			return 0;
	}

	//operator konwersji - potrzebna dla if(iterator)
	operator int() {
		if (wybranyW != NULL)
			return 1;
		else
			return 0;
	}
};

template<class typ>
iteratorL<typ> & iteratorL<typ>::na_wezel(int nr) {
	wybranyW = pojemnik.pierwszyW;
	for (int i = 0; i < nr; i++, ++(*this));
	return *this;
}
