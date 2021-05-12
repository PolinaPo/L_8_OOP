#ifndef PROGRAM_H
#define PROGRAM_H
#include <fstream>
#include <string>
using namespace std;

namespace type_phrases {
	// общий класс фраз
	class phrase {
		string content;
	public:
		//string content;
		virtual ~phrase() {};
		static phrase* phrase_Input(ifstream &ifst);
		void phrase_Output(ofstream& ofst);
		virtual void Input(ifstream& ifst) = 0;
		virtual void Output(ofstream& ofst) = 0;
	};

	class aphorism : public phrase {
		string author;
	public:
		//string author;
		void Input(ifstream& ifst);
		void Output(ofstream& ofst);
		~aphorism();
	};

	class proverb : public phrase {
		string country;
	public:
		//string country;
		void Input(ifstream& ifst);
		void Output(ofstream& ofst);
		~proverb();
	};

	class node {
	public:
		phrase* info;
		node* next;
		node* prev;
		bool node_Add(ifstream& ifst);
		bool node_Output(ofstream& ofst);
		~node();
	};

	class container {
	public:
		int size;
		node* head; // pointer to the first item in the list
		node* tail;
		void container_Clear();
		void container_Fill(ifstream& ifst);
		void container_Output(ofstream& ofst);
		container();
		~container();
	};
} // end type_phrases namespace

#endif // !PROGRAM_H

