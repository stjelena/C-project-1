#include "Korisnik.h"
#include "VremenskaOznaka.h"
#include "ElektronskaPoruka.h"
#include "ElektronskaPorukaTekst.h"

#include <iostream>
using namespace std;

int main() {
	Korisnik jelena("Jelena", "jelenajecasd@gmail.com");
	cout << jelena << endl;

	Korisnik milica("Milica", "milica.ristic00.gmail.com");

	VremenskaOznaka vo1(2022, 1, 4, 12, 37);
	cout << vo1 << endl;

	ElektronskaPoruka ep(&jelena, &milica, "Projekat");
	cout << ep << endl;

	ElektronskaPorukaTekst ept(&milica, &jelena, "Porukica");
	ept.postaviTekst("poruka poruka poruka salje asadmfsnk");
	cout << ept << endl;

	cout << *ep.kopijaEP();
}