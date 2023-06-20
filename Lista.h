#ifndef _lista_h_
#define _lista_h_

#include <exception>
using namespace std;

class GNemaTek : public exception {
public:
	GNemaTek() : exception("Greska: Ne postoji tekuci element!") {}
};

template<typename T>
class Lista {
	struct Elem {
		T t;
		Elem* sled = nullptr;

		Elem(const T& tt) : t(tt) {}
	};
	Elem* prvi = nullptr, * posl = nullptr;
	mutable Elem* tek = nullptr;
	int br = 0;

	void kopiraj(const Lista& l);
	void premesti(Lista& l) {
		prvi = l.prvi;
		posl = l.posl;
		tek = l.tek;
		l.prvi = l.tek = l.posl = nullptr;
		br = l.br;
		l.br = 0;
	}
	void brisi();

public:
	Lista() {};
	Lista(const Lista& l) {
		kopiraj(l);
	}
	Lista(Lista&& l) {
		premesti(l);
	}
	Lista& operator=(const Lista& l) {
		if (this != l) {
			brisi();
			kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l) {
		if (this != l) {
			brisi();
			premesti(l);
		}
		return *this;
	}
	virtual ~Lista() {
		brisi();
	}


	Lista& dodaj(const T& t) {
		br++;
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		return *this;
	}

	int brEl() const { return br; }

	void naPrvi() { tek = prvi; }
	void naSled() { tek = tek->sled; }
	bool imaTek() const { return tek; }
	T& dohvTek() {
		if (!tek) throw GNemaTek();
		return *tek->t;
	}
};

template<typename T>
void Lista<T>::kopiraj(const Lista& l) {
	prvi = posl = tek = nullptr;
	for (l.tek = prvi; l.tek; l.tek = l.tek->sled) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(tek->t);
	}
	br = l.br;
}

template<typename T>
void Lista<T>::brisi() {
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	tek = posl = nullptr;
	br = 0;
}
#endif
