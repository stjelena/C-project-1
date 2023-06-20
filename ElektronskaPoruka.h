#ifndef _ElektronskaPoruka_h_
#define _ElektronskaPoruka_h_

#include "Korisnik.h"

enum STANJE {U_PRIPREMI, POSLATA, PRIMLJENA};

class ElektronskaPoruka {
protected:
	Korisnik *posaljilac, *primalac;
	STANJE stanje;
	string naslov;

public:
	ElektronskaPoruka(Korisnik* po, Korisnik* pr, string n) {
		posaljilac = po;
		primalac = pr;
		naslov = n;
		stanje = STANJE::U_PRIPREMI;
	}

	//konstruktori???

	Korisnik* getPo() const { return posaljilac; }
	Korisnik* getPr() const { return primalac; }
	STANJE getStanje() const { return stanje; }
	string getNaslov() const { return naslov; }

	virtual void posaljiPor() {};

	ElektronskaPoruka* kopijaEP() {
		return new ElektronskaPoruka(posaljilac, primalac, naslov);
	}


	friend ostream& operator<<(ostream& it, ElektronskaPoruka& ep) {
		return it << ep.naslov << endl << *ep.posaljilac << endl << *ep.primalac << endl;
	}
};

#endif
