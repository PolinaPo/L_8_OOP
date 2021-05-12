#ifndef RIDDLE_H
#define RIDDLE_H
#include <fstream>
#include <string>
#include "phrase.h"
using namespace std;

namespace type_phrases {
	class riddle : public phrase {
		string answer;
	public:
		bool Input(ifstream& ifst);
		void Output(ofstream& ofst);
		~riddle();
	};
} // end type_phrases namespace
#endif // !RIDDLE_H