#ifndef _ElektronskaPorukaTekst_h_
#define _ElektronskaPorukaTekst_h_

#include "ElektronskaPoruka.h"
#include "Greske.h"

class ElektronskaPorukaTekst : public ElektronskaPoruka{
	string tekst;
public:
	ElektronskaPorukaTekst(Korisnik* po, Korisnik* pr, string n) :
		ElektronskaPoruka(po, pr, n) {};

	void postaviTekst(string t) { 
		if (stanje == POSLATA)
			throw new GPoruka();
		tekst = t; 
	}

	void posaljiPor() override {
		stanje = POSLATA;
	}

	friend ostream& operator<<(ostream& it, ElektronskaPorukaTekst& ep) {
		return it << ep.naslov << endl << *ep.posaljilac << endl << *ep.primalac << endl << ep.tekst << endl;
	}
};

#endif
