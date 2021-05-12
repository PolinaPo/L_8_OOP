#include <iostream>
#include <fstream>
#include "proverb.h"

using namespace std;

namespace type_phrases {

	bool proverb::Input(ifstream& ifst) {
		if ((country = check_input_string(ifst)) != "0") {
			return true;
		}
		else {
			return false;
		}
	}

	void proverb::Output(ofstream& ofst) {
		ofst << "Proverb of country: " << country << ";" << endl;
	}

	proverb::~proverb() {}
}