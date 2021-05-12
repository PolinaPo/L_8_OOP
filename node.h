#ifndef NODE_H
#define NODE_H
#include <fstream>
#include <string>
#include "phrase.h"
using namespace std;

namespace type_phrases {
	class node {
		phrase* info;
		node* next;
		node* prev;
	public:
		bool node_Add(ifstream& ifst);
		bool node_Output(ofstream& ofst);
		bool node_OutputAphos(ofstream& ofst);
		static node* node_Next(node* cur_node, node* value, int flag);
		static node* node_Prev(node* cur_node, node* value, int flag);
		void node_Init(node* cur_node, int size_list);
		phrase* get_Info();
		void set_Info(phrase* value);
		~node();
	};
} // end type_phrases namespace

#endif // !NODE_H

