#include <iostream>
#include "bst.h"

using namespace std;

int main() {
	BST b;
	b.insert(15);
	b.insert(29);
	b.insert(13);
	b.insert(14);
	b.insert(17);
	b.print();
	b.remove(13);
	b.print();
	b.access(40);

	return 0;
}