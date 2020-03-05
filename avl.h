#include <iostream>
#include <stack>
#pragma once

struct Node {
	int data;
	Node* left;
	Node* right;
	int height;	
};

class AVL{
private:
	int ALLOWED_IMBALANCE = 1;

	Node* root;
	int height(Node* n) {
		return (n == NULL) ? -1 : n -> height;
	}
	void insert(int i, Node*& root);
	void remove(int i, Node*& root);
	void access(int i, Node* root);

	void balance(Node*& n);

	void rotateWithLeftChild(Node*& n);
	void rotateWithRightChild(Node*& n);
	void doubleWithLeftChild(Node*& n);
	void doubleWithRightChild(Node*& n);

	Node* findMin(Node* root) {
		if (root == NULL) return NULL;
		if (root->left == NULL) return root; 
		findMin(root -> left);
	}

	void clear(Node* root);
public:
	AVL();
	~AVL();
	void insert(int i);
	void access(int i);
	void remove(int i);
	void print();
};