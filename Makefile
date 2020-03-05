all: avl bst

avl: avl.o mainavl.o
	g++ avl.o mainavl.o -o avl -g

bst: bst.o mainbst.o
	g++ bst.o mainbst.o -o bst -g

mainavl.o: mainavl.cpp
	g++ mainavl.cpp -c -g

bst.o: bst.cpp
	g++ bst.cpp -c -g

avl.o: avl.cpp
	g++ avl.cpp -c -g

testbst.o: testbst.cpp
	g++ testbst.cpp -c -g

testavl.o: testavl.cpp
	g++  testavl.cpp -c -g

clean:
	rm *.o