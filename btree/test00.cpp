/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Test case for the Generic B-Tree.
 */

#include <iostream>
#include "btree.h"

int main(int argc, char *argv[]) {

	//enable printing of booleans as "true" and "false"
	std::cout << std::boolalpha;

	//create an empty btree of characters with a node size of 4
	btree<char> t1{4};

	//insert some unique keys
	std::cout << "Insert M: " << t1.insert('M').second << std::endl;
	std::cout << "Insert X: " << t1.insert('X').second << std::endl;
	std::cout << "Insert P: " << t1.insert('P').second << std::endl;
	std::cout << "Insert G: " << t1.insert('G').second << std::endl;
	std::cout << "Insert T: " << t1.insert('T').second << std::endl;
	std::cout << "Insert B: " << t1.insert('B').second << std::endl;
	std::cout << "Insert Z: " << t1.insert('Z').second << std::endl;
	std::cout << "Insert N: " << t1.insert('N').second << std::endl;
	std::cout << "Insert R: " << t1.insert('R').second << std::endl;
	std::cout << "Insert S: " << t1.insert('S').second << std::endl;
	std::cout << "Insert W: " << t1.insert('W').second << std::endl;
	std::cout << "Insert Q: " << t1.insert('Q').second << std::endl;
	std::cout << "Insert V: " << t1.insert('V').second << std::endl;

	std::cout << "t1: " << t1 << std::endl;

	//try to re-insert the keys again
	std::cout << "Insert M: " << t1.insert('M').second << std::endl;
	std::cout << "Insert X: " << t1.insert('X').second << std::endl;
	std::cout << "Insert P: " << t1.insert('P').second << std::endl;
	std::cout << "Insert G: " << t1.insert('G').second << std::endl;
	std::cout << "Insert T: " << t1.insert('T').second << std::endl;
	std::cout << "Insert B: " << t1.insert('B').second << std::endl;
	std::cout << "Insert Z: " << t1.insert('Z').second << std::endl;
	std::cout << "Insert N: " << t1.insert('N').second << std::endl;
	std::cout << "Insert R: " << t1.insert('R').second << std::endl;
	std::cout << "Insert S: " << t1.insert('S').second << std::endl;
	std::cout << "Insert W: " << t1.insert('W').second << std::endl;
	std::cout << "Insert Q: " << t1.insert('Q').second << std::endl;
	std::cout << "Insert V: " << t1.insert('V').second << std::endl;

	std::cout << "t1: " << t1 << std::endl;

	return 0;
}
