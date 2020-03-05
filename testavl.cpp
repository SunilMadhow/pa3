#include <iostream>
#include "avl.h"

using namespace std;

int main() {
	AVL avl;
	avl.insert(15);
	avl.insert(29);
	avl.insert(13);
	avl.insert(14);
	avl.insert(17);
	avl.insert(15);
	avl.access(40);
	avl.access(13);
	avl.print();
	avl.remove(13);
	avl.print();
	return 0;
}