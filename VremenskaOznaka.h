#ifndef _VremenskaOznaka_h_
#define _VremenskaOznaka_h_

using namespace std;
#include <iostream>

class VremenskaOznaka {
	int god, dan, mes, sat, min;

public:
	
	VremenskaOznaka(int g, int m, int d, int s, int mm) :
		god(g), mes(m), dan(d), sat(s), min(mm) {};

	friend ostream& operator<<(ostream& it, VremenskaOznaka& vo) {
		return it << vo.dan << "." << vo.mes << "." << vo.god << "-" << vo.sat << ":" << vo.min;
	}
};

#endif
