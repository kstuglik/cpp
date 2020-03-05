class osoba {
public:
	char nazwisko[30];
	osoba(char* n = NULL) {
		if (n) {
			strcpy(nazwisko, n);
		}
	}
	friend ostream& operator<<(ostream &s, const osoba &o);
	friend ostream& operator<<(ostream &s, const osoba *wsk);
};

ostream& operator<<(ostream &s, const osoba &o) {
	s << o.nazwisko;
	return s;
}

ostream& operator<<(ostream &s, const osoba *wsk) {
	s << wsk->nazwisko;
	return s;
}