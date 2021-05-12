#include <iostream>
#include <fstream>
#include "riddle.h"

using namespace std;

namespace type_phrases {

	bool riddle::Input(ifstream& ifst) {
		if ((answer = check_input_string(ifst)) != "0") {
			return true;
		}
		else {
			return false;
		}
	}

	void riddle::Output(ofstream& ofst) {
		ofst << "\nAnswer to riddle: " << answer << ";" << endl;
	}

	riddle::~riddle() {}
}