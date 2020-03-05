#include <iostream>
#include <string.h>
// #include <stdio.h>

#include "bst.h"
using namespace std;

int main(int argc, char* argv[]) {
	string input = argv[1];
	BST q;
	for (int i = 0; i < input.length(); i ++) {
		// cout << "start of loop" << endl;
		string function; 
		int arg = 0;
		// cout << "looking at input[" << i << "] = " << input[i] << endl;
		int before = i;
		while (input[i] != ' ' && input[i] != ',' && i < input.length()) {
					// cout << "looking at input[" << i << "] = " << input[i] << endl;
			// function[i] = input[i];
			i ++;
		}
		function = input.substr(before, i - before);
		i ++;
		bool neg_flag = false;
		while (input[i] != ',' && input[i] != ' ' && i < input.length()) {
					// cout << "looking at input[" << i << "] = " << input[i] << endl;
			// cout << input[i] << endl;
			if (input[i] == '-') {
				neg_flag = true;
				i ++;
				continue;
			}
			arg *= 10;
			arg += input[i] - '0';
			if (input[i + 1] == '\0') break;
			i ++;
		} 	
		// cout << arg << endl;
		if (neg_flag == true) arg = arg * -1;
		// cout << arg << endl;
		// cout << "comparing " << function << "with accepted inputs" << endl;
		// cout << "current index is " << i << endl;
		if (function == "insert") q.insert(arg);
		if (function == "access") q.access(arg);
		if (function == "delete") q.remove(arg);
		if (function == "print") {q.print();i--;}

		i ++;
		// cout << i << " " << input[i] << endl;
	}
		
}