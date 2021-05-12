#ifndef PROVERB_H
#define PROVERB_H
#include <fstream>
#include <string>
#include "phrase.h"
using namespace std;

namespace type_phrases {
	class proverb : public phrase {
		string country;
	public:
		bool Input(ifstream& ifst);
		void Output(ofstream& ofst);
		~proverb();
	};
} // end type_phrases namespace

#endif // !PROVERB_H
