#include <iostream>
#include "bst.h"
#include <stack>
using namespace std;

BST::BST() {
	this->head = NULL;
}

BST::~BST() {
	clear(head);
}

void BST::clear(Node* root) {
	if (root) {
		clear(root -> left);
		clear(root -> right);
		delete root;
	}
}

bool BST::insert(int value) {
    // handle special case of empty tree first
    // cout << "trying to insert " << value << endl;
    if (!head) {
   	cout << "Element inserted" << endl;
    head = new Node(value);
    head -> right = NULL;
    head -> left = NULL;
    return true;
    }
    // otherwise use recursive helper
    return insert(value, head);
}

// recursive helper for insert (assumes n is never 0)
bool BST::insert(int value, Node *n) {
	// cout << n -> data << endl;
    if (value == n->data) {
    	cout << "Element already present" << endl;
       return false;
   }
    if (value < n->data) {
       if (n->left)
           return insert(value, n->left);
       else {
           n->left = new Node(value);
           n -> left -> right = NULL;
           n -> left -> left = NULL;
           n->left->parent = n;
           cout << "Element inserted" << endl;
           return true;
    }
    }
    else {
       if (n->right)
            return insert(value, n->right);
        else {
           cout << "Element inserted" << endl;
           n->right = new Node(value);
           n -> right -> right = NULL;
           n -> right -> left = NULL;
           n->right->parent = n;
           return true;
       }
    }
}

Node* BST::access(int i) {
	Node* node = head;
	while (node) {
		if (node -> data > i) {
			node = node -> left;
		}
		else if (node -> data < i) {
			node = node -> right;
		}
		else {
			cout << "Element accessed" << endl;
			return node;
		}
	}
	cout << "Element not accessed" << endl;
	return NULL;
}

void BST::remove(int i) {
	remove(i, head);
}

void BST::remove(int i, Node*& node) {
	if (node == NULL) {
		cout << "Element not found" << endl;
		return;
	}
	
	if (i < node -> data) {
		remove(i, node -> left);
	}
	else if (i > node -> data) {
		remove (i, node -> right);
	}
	// element is found ----
	else if (node -> left != NULL && node -> right != NULL) { //two nodes
		node->data = findMin(node -> right)->data;
		remove (node->data, node -> right);
	}
	else { //1 or 0 children
		Node* temp = node;
		node = (node->left != NULL) ? node->left : node->right;
		delete temp;
		cout << "Element deleted" << endl;
	}
		
}

void BST::print() {
	if (!head) {
		cout << "Empty tree" << endl;
		return;
	}
	
	// Preorder
	stack<Node *> s2; 
    s2.push(head); 
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
	curr = head;
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
	stk.push(head);

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

// ------------------------------ helper functions ----------------------------------

Node* BST::findMin(Node* node) {
	if (node -> left == NULL) return node;
	return findMin(node -> left);
}