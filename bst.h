#include <iostream>
#include <stack>
#pragma once

struct Node {
	Node* right;
	Node*  left;
	Node* parent;
	int data;

	Node(int v=0) : data(v), left(0), right(0), parent(0) { }

};

class BST {
private:
	Node* head;
	void remove(int i, Node*& node);
	Node* findMin(Node* root);
	bool insert(int i, Node* root);
	void clear(Node* n);
public:
	BST();
	~BST();
	bool insert(int i);
	Node* access(int i);
	void remove(int i);
	void print();
};