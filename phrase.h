#ifndef PHRASE_H
#define PHRASE_H
#include <fstream>
#include <string>
using namespace std;

namespace type_phrases {
	// общий класс фраз
	class phrase {
		string content;
		short eval;
	public:
		virtual ~phrase() {};
		static phrase* phrase_Input(ifstream& ifst);
		void phrase_Output(ofstream& ofst);
		virtual bool Input(ifstream& ifst) = 0;
		virtual void Output(ofstream& ofst) = 0;
		unsigned short int num_punct_marks();
		bool compare(phrase* next);		
		virtual bool OutputAphorism(ofstream& ofst); // Вывод только афоризмов
		static string check_input_string(ifstream& ifst);
	};
} // end type_phrases namespace

#endif // !PHRASE_H

