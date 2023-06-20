#pragma once
#include <exception>
using namespace std;

class GPoruka : public exception {
public:
	GPoruka() : exception("Greska: Ne sme se menjati tekst nakon sto je poruka poslata!") {}
};
