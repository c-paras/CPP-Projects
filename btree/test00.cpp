/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Test case for the Generic B-Tree.
 */

#include <iostream>
#include "btree.h"

int main(int argc, char *argv[]) {

	//enable printing of booleans as "true" and "false"
	std::cout << std::boolalpha;

	//create an empty btree
	btree<int> t1;

	//insert some unique keys
	std::cout << "Insert 1: " << t1.insert(2).second << std::endl;
	std::cout << "Insert 2: " << t1.insert(2).second << std::endl;
	std::cout << "Insert 3: " << t1.insert(3).second << std::endl;
	std::cout << "Insert 4: " << t1.insert(4).second << std::endl;
	std::cout << "Insert 5: " << t1.insert(5).second << std::endl;

	//try to re-insert the keys again
	std::cout << "Insert 1: " << t1.insert(2).second << std::endl;
	std::cout << "Insert 2: " << t1.insert(2).second << std::endl;
	std::cout << "Insert 3: " << t1.insert(3).second << std::endl;
	std::cout << "Insert 4: " << t1.insert(4).second << std::endl;
	std::cout << "Insert 5: " << t1.insert(5).second << std::endl;

	return 0;
}
