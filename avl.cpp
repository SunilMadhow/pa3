#include <iostream>
#include <stack>
#include "avl.h"
using namespace std;

AVL::AVL() {
	root = NULL;
}

AVL::~AVL() {
	clear(root);
}

void AVL::clear(Node* root) {
	if (root) {
		clear(root -> left);
		clear(root -> right);
		delete root;
	}
}

void AVL::insert(int i) {
	insert(i, root);
}

void AVL::insert(int i, Node*& root) {
	if (root == NULL) {
		root = new Node();
		root -> data = i;
		root -> left = NULL;
		root -> right = NULL;
		root -> height = 0;
		cout << "Element inserted" << endl;
	}
	else if (i < root -> data)
		insert(i, root -> left);
	else if (i > root -> data)
		insert(i, root -> right);
	else {
		cout << "Element already present" << endl;
	}
	balance(root);
} 

void AVL::access(int i) {
	access(i, root);
}

void AVL::access(int i, Node* root) {
	if (root == NULL) {
		cout << "Element not found" << endl;
		return;
	}
	else if (root-> data < i) {
		access(i, root -> right);
	}
	else if (root -> data > i) {
		access(i, root -> left);
	}
	else {
		cout << "Element accessed" << endl;
	}
}

void AVL::remove(int i) {
	remove(i, root);
}

void AVL::remove(int i, Node*& root) {
	if (root == NULL)
		cout << "Element not found" << endl;
	else if (i < root -> data)
		remove(i, root -> left);
	else if (i > root -> data)
		remove(i, root -> right);
	else if (root -> left != NULL && root -> right != NULL) {
		root -> data = findMin(root -> right) -> data;
		remove (root -> data, root -> right);
	}
	else {
		Node* temp = root;
		root = (root->left != NULL) ? root -> left : root->right;
		delete temp;
		cout << "Element deleted" << endl;
	}
	balance(root);
}

void AVL::balance(Node*& t) {
	if (t == NULL)
		return;
	if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE) {
		if (height(t -> left -> left) >= height (t->left -> right)) {
			rotateWithLeftChild(t);
		}
		else {
			doubleWithLeftChild(t);
		}
	}
	else {
		if (height(t -> right) - height(t->left) > ALLOWED_IMBALANCE) {
			if (height(t->right->right) >= height(t->right->left)) {
				rotateWithRightChild(t);
			}
			else {
				doubleWithRightChild(t);
			}

		}
	}
	t->height = height(t->left) > height(t->right) ? height(t->left) + 1 : height(t -> right) + 1;
}

void AVL::rotateWithLeftChild(Node *& k2)
{
	Node* k1 = k2 -> left;
	k2 -> left = k1->right;
	k1 -> right = k2;
	k2->height = height(k2->left) > height(k2->right) ? height(k2->left) + 1 : height(k2 -> right) + 1;
	k1->height = height(k1->left) > k2 ->height ? height(k1->left) + 1 : k2->height + 1;
	k2 = k1;
}

void AVL::rotateWithRightChild(Node *& k1)
{
	Node* k2 = k1 -> right;
	k1 -> right = k2->left;
	k2 -> left = k1;
	k1->height = height(k1->left) > height(k1->right) ? height(k1->left) + 1 : height(k1 -> right) + 1;
	k2->height = height(k2->right) > k1 ->height ? height(k2->right) + 1 : k1->height + 1;
	k1 = k2;
}

void AVL::doubleWithLeftChild(Node *& k3)
{
	rotateWithRightChild(k3 -> left);
	rotateWithLeftChild(k3);
}

void AVL::doubleWithRightChild(Node *& k1)
{
	rotateWithLeftChild(k1 -> right);
	rotateWithRightChild(k1);
}

void AVL::print() {
	if (!root) {
		cout << "Empty tree" << endl;
		return;
	}
	// Preorder
	stack<Node *> s2; 
    s2.push(root); 
  	Node* curr;
  	while (!s2.empty()) {
  		curr = s2.top();
  		s2.pop();
  		cout << curr->data << " ";
  		if (curr -> right != NULL) {
  			s2.push(curr -> right);
  		}
  		if (curr -> left != NULL) {
  			s2.push(curr -> left);
  		}
  	}
  	cout << endl;

  	// Inorder
	stack<Node*> s;
	curr = root;
	while (curr != NULL || s.empty() == false) 
    { 
        /* Reach the left most Node of the 
           curr Node */
        while (curr !=  NULL) 
        { 
            /* place pointer to a tree node on 
               the stack before traversing 
              the node's left subtree */
            s.push(curr); 
            curr = curr->left; 
        } 
  
        /* Current must be NULL at this point */
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->data << " "; 
  
        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        curr = curr->right; 
  	}
  	cout << endl;
	
	// Postorder
	stack<Node*> stk;
	stk.push(root);

	// create another stack to store post-order traversal
	stack<int> out;

	// run till stack is not empty
	while (!stk.empty())
	{
		// we pop a node from the stack and push the data to output stack
		Node *curr = stk.top();
		stk.pop();

		out.push(curr->data);

		// push left and right child of popped node to the stack
		if (curr->left)
			stk.push(curr->left);

		if (curr->right)
			stk.push(curr->right);
	}

	// print post-order traversal
	while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
	cout << endl;
}