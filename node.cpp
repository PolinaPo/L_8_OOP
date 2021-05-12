#include <iostream>
#include <fstream>
#include "node.h"

using namespace std;

namespace type_phrases {

	bool node::node_Add(ifstream& ifst) {
		info = phrase::phrase_Input(ifst);
		if (info == NULL) return false;
		else return true;
	}

	bool node::node_Output(ofstream& ofst) {
		info->Output(ofst);
		info->phrase_Output(ofst);
		unsigned short int check = info->num_punct_marks();
		if (check == -1) {
			cout << "|Overflow of number of punctuation marks|" << endl;
			ofst << "Overflow of number of punctuation marks." << endl;
			exit(1);
		}
		else {
			ofst << "Number of punctuation marks: " << check << "." << endl;
		}
		return true;
	}

	bool node::node_OutputAphos(ofstream& ofst) {
		if (info->OutputAphorism(ofst)) {
			info->phrase_Output(ofst);
			int check = info->num_punct_marks();
			if (check == -1) {
				cout << "|Overflow of number of punctuation marks|" << endl;
				ofst << "Overflow of number of punctuation marks." << endl;
				exit(1);
			}
			else {
				ofst << "Number of punctuation marks: " << check << "." << endl;
			}
		}
		return true;
	}

	node* node::node_Next(node* cur_node, node* value, int flag) {
		switch (flag)
		{
		case 1: // добавить ссылку на следующий элемент
			cur_node->next = value;
			return cur_node;
		case 2: // получить следующий элемент
			cur_node = cur_node->next;
			return cur_node;
		default:
			break;
		}
	}

	node* node::node_Prev(node* cur_node, node* value, int flag) {
		switch (flag)
		{
		case 1: // добавить ссылку на предыдущий элемент
			cur_node->prev = value;
			return cur_node;
		case 2: // получить предыдущий элемент
			cur_node = cur_node->prev;
			return cur_node;
		default:
			break;
		}
	}

	void node::node_Init(node* cur_node, int size_list) {
		cur_node->next = NULL;
		if (size_list == 0) cur_node->prev = NULL;
	}

	phrase* node::get_Info() {
		return info;
	}

	void node::set_Info(phrase* value) {
		info = value;
	}

	node::~node() {}
}