#ifndef _korisnik_h_
#define _korisnik_h_

using namespace std;
#include <iostream>
#include <string>

class Korisnik {
	string ime;
	string email;

public:
	Korisnik(string i, string e) :ime(i), email(e) {};
	Korisnik(const Korisnik&) = delete;

	string getIme() const { return ime; }
	string getEmail() const { return email; }

	friend ostream& operator<<(ostream& it, const Korisnik& k) {
		it << "(" << k.ime << ")" << k.email;
		return it;
	}

};

#endif // !_korisnik_h_
