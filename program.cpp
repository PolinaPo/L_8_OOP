#include <iostream>
#include <fstream>
#include "program.h"

using namespace std;

namespace type_phrases {

	void aphorism::Input(ifstream& ifst) {
		getline(ifst, author);
	}

	void aphorism::Output(ofstream& ofst) {
		ofst << "Author of aphorism: " << author << ";" << endl;
	}

	void proverb::Input(ifstream& ifst) {
		getline(ifst, country);
	}

	void proverb::Output(ofstream& ofst) {
		ofst << "Proverb of country: " << country << ";" << endl;
	}

	aphorism::~aphorism() {}

	proverb::~proverb() {}

	phrase* phrase::phrase_Input(ifstream& ifst) {
		phrase* new_phrase;
		string k;
		getline(ifst, k);
		switch (atoi(k.c_str()))
		{
		case 1:
			new_phrase = new aphorism;
			break;
		case 2:
			new_phrase = new proverb;
			break;
		default:
			cout << "There are no such type of phrases!" << endl;
			return 0;
		}
		new_phrase->Input(ifst);
		getline(ifst, new_phrase->content);
		return new_phrase;
	}

	void phrase::phrase_Output(ofstream& ofst) {
		ofst << "Content: " << content << "." << endl;
	}

	node::~node() {}

	bool node::node_Add(ifstream& ifst) {
		info = phrase::phrase_Input(ifst);
		if (info == NULL) return false;
		else return true;
	}

	void container::container_Fill(ifstream& ifst) {
		if (head != NULL) {
			cout << "|List is not empty!|" << endl;
			return;
		}
		node* tmp_node = new node;
		if (tmp_node->node_Add(ifst)) {
			head = tmp_node;
			tail = tmp_node;
			tmp_node->next = NULL;
			tmp_node->prev = NULL;
			size++;
			tmp_node = NULL;
			tmp_node = new node;
		}
		while (tmp_node->node_Add(ifst)) {
			tmp_node->next = NULL;
			tmp_node->prev = tail;
			tail->next = tmp_node;
			tail = tmp_node;			
			size++;
			tmp_node = NULL;
			tmp_node = new node;
		}
		delete(tmp_node);
	}

	bool node::node_Output(ofstream& ofst) {
		info->Output(ofst);
		info->phrase_Output(ofst);
		return true;
	}

	void container::container_Output(ofstream& ofst) {
		node* currentNode;
		if (size == 0) {
			cout << "|List is empty!|" << endl;
			return;
		}
		ofst << "Container contains " << size << " element" << endl;
		cout << "|Container contains " << size << " elements.|" << endl;
		currentNode = head;
		for (int i = 0; i < size; i++) {
			currentNode->node_Output(ofst);
			currentNode = currentNode->next;
		}
	}

	void container::container_Clear() {
		if (head == NULL) return;
		else {
			node* currentNode;
			for (int i = 0; i < size; i++) {
				currentNode = tail;
				tail = tail->prev;
				currentNode->~node();
			}
			size = 0;
			head = NULL;
			tail = NULL;
		}
	}

	container::container() {
		size = 0;
		head = NULL;
		tail = NULL;
	}

	container::~container() {
		container_Clear();
	}
}