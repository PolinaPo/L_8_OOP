#ifndef APHORISM_H
#define APHORISM_H
#include <fstream>
#include <string>
#include "phrase.h"
using namespace std;

namespace type_phrases {
	class aphorism : public phrase {
		string author;
	public:
		bool Input(ifstream& ifst);
		void Output(ofstream& ofst);
		// Вывод только афоризмов
		bool OutputAphorism(ofstream& ofst);
		~aphorism();
	};
} // end type_phrases namespace

#endif // !APHORISM_H


