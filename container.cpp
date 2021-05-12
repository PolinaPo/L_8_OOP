#include <iostream>
#include <fstream>
#include "container.h"
using namespace std;

namespace type_phrases {

	void container::container_Fill(ifstream& ifst) {
		if (head != NULL) {
			cout << "|List is not empty|" << endl;
			return;
		}

		while (!ifst.eof()) {
			if (tmp_node->node_Add(ifst)) {
				if (size == 0) {
					head = tmp_node;
					tail = tmp_node;
				}
				tmp_node->node_Init(tmp_node, size);
				if (size > 0) {
					node::node_Prev(tmp_node, tail, 1);
					node::node_Next(tail, tmp_node, 1);
					tail = tmp_node;
				}				
				size++;
				tmp_node = NULL;
				tmp_node = new node;
			}
			else {
				cout << "|Addition node #" << (size + 1) << " failed|" << endl;
			}			
		}
		delete(tmp_node);
	}

	void container::container_Output(ofstream& ofst) {
		if (size == 0) {
			cout << "|Container output failed. It's empty|" << endl;
			return;
		}
		ofst << "Container contains " << size << " element" << endl;
		cout << "|Container contains " << size << " elements|" << endl;
		tmp_node = head;
		for (int i = 0; i < size; i++) {
			ofst << (i+1) << ": ";
			if (tmp_node->node_Output(ofst)) {
				tmp_node = node::node_Next(tmp_node, NULL, 2);
			}
			else {
				cout << "|Error in node #" << i+1 << " output|" << endl;
			}
		}
	}

	void container::container_OutputAphos(ofstream& ofst) {
		if (size == 0) {
			cout << "|Container output failed. It's empty|" << endl;
			return;
		}
		tmp_node = head;
		ofst << "Only Aphorism." << endl;
		for (int i = 0; i < size; i++) {
			ofst << (i + 1) << ": ";
			tmp_node->node_OutputAphos(ofst);
			tmp_node = node::node_Next(tmp_node, NULL, 2);
		}
	}

	void container::container_Clear() {
		if (head == NULL) {
			cout << "|Container cleanup failed. It's empty|" << endl;
			return;
		}
		else {
			for (int i = 0; i < size; i++) {
				tmp_node = tail;
				tail = node::node_Prev(tail, NULL, 2);
				tmp_node->~node();
			}
			size = 0;
			head = NULL;
			tail = NULL;
		}
	}

	node* container::get_Node(int index) {
		node* returnedNode = head;
		for (int i = 0; i < index; i++) {
			returnedNode = node::node_Next(returnedNode, NULL, 2);
		}
		return returnedNode;
	}

	void container::swap(int index_first, int index_second) {
		node* temp = new node;
		temp->set_Info(get_Node(index_first)->get_Info());
		get_Node(index_first)->set_Info(get_Node(index_second)->get_Info());
		get_Node(index_second)->set_Info(temp->get_Info());
	}

	void container::sort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (get_Node(i)->get_Info()->compare(get_Node(j)->get_Info()))
				{
					swap(i, j);
				}
			}
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