#include <iostream>
#include <fstream>
#include "phrase.h"
#include "aphorism.h"
#include "proverb.h"
#include "riddle.h"

using namespace std;

namespace type_phrases {

	string phrase::check_input_string(ifstream& ifst)
	{
		string temp = "";
		if (!ifst.eof()) {
			getline(ifst, temp);
			return temp;
		}
		else {
			cout << "|Input file ended|" << endl;
			return "0";
		}
	}

	phrase* phrase::phrase_Input(ifstream& ifst) {
		phrase* new_phrase;
		string k = "";
		getline(ifst, k);
		if (k == "") {
			cout << "|Missing an empty string|" << endl;
			return 0;
		}
		else {
			switch (atoi(k.c_str()))
			{
			case 1:
				new_phrase = new aphorism;
				break;
			case 2:
				new_phrase = new proverb;
				break;
			case 3:
				new_phrase = new riddle;
				break;
			default:
				cout << "|There are no such type of phrases|" << endl;
				for (unsigned short i = 0; i < 3; i++) {
					k = check_input_string(ifst);
					if (k == "0") {
						break;
					}
				}
				return 0;
			}
			//new_phrase->Input(ifst);
			if (!new_phrase->Input(ifst)) {
				return 0;
			}
			if ((new_phrase->content = check_input_string(ifst)) == "0") {
				return 0;
			}
			string ev = "";
			if ((ev = check_input_string(ifst)) == "0") {
				return 0;
			}
			try {
				new_phrase->eval = stoi(ev);
				if (new_phrase->eval < 0 || new_phrase->eval > 10) {
					cout << "|Evaluetion value is not in the range 0-10|" << endl;
					return 0;
				}
			}
			catch (invalid_argument e) {
				cout << "|Caught Invalid Argument Exception for evaluetion|" << endl;
				return 0;
			}
			return new_phrase;
		}
	}

	void phrase::phrase_Output(ofstream& ofst) {
		ofst << "Content: " << content << "\n" << "Evaluation: " << eval << "." << endl;
	}

	unsigned short int phrase::num_punct_marks() {
		string punctM = ".,;:\"!?()-";
		unsigned short int cnt = 0; // от 0 до 65535
		for (unsigned int i = 0; i < content.length(); i++) {
			for (unsigned j = 0; j < punctM.length(); j++) {
				if (content[i] == punctM[j]) {
					if (cnt > 65535) {
						return -1;
					}
					cnt++;
				}
			}
		}
		return cnt;
	}

	bool phrase::compare(phrase* next)
	{
		return num_punct_marks() > next->num_punct_marks(); // в порядке неубывания
	}
	// Вывод данных только для афоризмов
	bool phrase::OutputAphorism(ofstream& ofst) {
		ofst << endl;
		return false;
	}
}