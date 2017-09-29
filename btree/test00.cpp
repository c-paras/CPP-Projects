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
	std::cout << "Create t1 of chars with node size 4" << std::endl;
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

	//create an empty btree of integers with a node size of 3
	std::cout << "Create t2 of ints with node size 3" << std::endl;
	btree<int> t2{3};

	//insert some unique keys
	std::cout << "Insert 16: " << t2.insert(16).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 4: " << t2.insert(4).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 29: " << t2.insert(29).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert -6: " << t2.insert(-6).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 17: " << t2.insert(17).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 15: " << t2.insert(15).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 20: " << t2.insert(20).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 28: " << t2.insert(28).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 19: " << t2.insert(19).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 18: " << t2.insert(18).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 0: " << t2.insert(0).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 1: " << t2.insert(1).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 5: " << t2.insert(5).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 14: " << t2.insert(14).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 3: " << t2.insert(3).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 2: " << t2.insert(2).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert -5: " << t2.insert(-5).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert -1: " << t2.insert(-1).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert -4: " << t2.insert(-4).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 6: " << t2.insert(6).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 13: " << t2.insert(13).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 12: " << t2.insert(12).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert -7: " << t2.insert(-7).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert -248: " << t2.insert(-248).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert -19: " << t2.insert(-19).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 27: " << t2.insert(27).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 24: " << t2.insert(24).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 21: " << t2.insert(21).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 11: " << t2.insert(11).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 10: " << t2.insert(10).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 9: " << t2.insert(9).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 30: " << t2.insert(30).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 672: " << t2.insert(672).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;
	std::cout << "Insert 308: " << t2.insert(308).second << std::endl;
	std::cout << "t2: " << t2 << std::endl;

	//try to re-insert the keys again
	std::cout << "Insert 16: " << t2.insert(16).second << std::endl;
	std::cout << "Insert 4: " << t2.insert(4).second << std::endl;
	std::cout << "Insert 29: " << t2.insert(29).second << std::endl;
	std::cout << "Insert -6: " << t2.insert(-6).second << std::endl;
	std::cout << "Insert 17: " << t2.insert(17).second << std::endl;
	std::cout << "Insert 15: " << t2.insert(15).second << std::endl;
	std::cout << "Insert 20: " << t2.insert(20).second << std::endl;
	std::cout << "Insert 28: " << t2.insert(28).second << std::endl;
	std::cout << "Insert 19: " << t2.insert(19).second << std::endl;
	std::cout << "Insert 18: " << t2.insert(18).second << std::endl;
	std::cout << "Insert 0: " << t2.insert(0).second << std::endl;
	std::cout << "Insert 1: " << t2.insert(1).second << std::endl;
	std::cout << "Insert 5: " << t2.insert(5).second << std::endl;
	std::cout << "Insert 14: " << t2.insert(14).second << std::endl;
	std::cout << "Insert 3: " << t2.insert(3).second << std::endl;
	std::cout << "Insert 2: " << t2.insert(2).second << std::endl;
	std::cout << "Insert -5: " << t2.insert(-5).second << std::endl;
	std::cout << "Insert -1: " << t2.insert(-1).second << std::endl;
	std::cout << "Insert -4: " << t2.insert(-4).second << std::endl;
	std::cout << "Insert 6: " << t2.insert(6).second << std::endl;
	std::cout << "Insert 13: " << t2.insert(13).second << std::endl;
	std::cout << "Insert 12: " << t2.insert(12).second << std::endl;
	std::cout << "Insert -7: " << t2.insert(-7).second << std::endl;
	std::cout << "Insert -248: " << t2.insert(-248).second << std::endl;
	std::cout << "Insert -19: " << t2.insert(-19).second << std::endl;
	std::cout << "Insert 27: " << t2.insert(27).second << std::endl;
	std::cout << "Insert 24: " << t2.insert(24).second << std::endl;
	std::cout << "Insert 21: " << t2.insert(21).second << std::endl;
	std::cout << "Insert 11: " << t2.insert(11).second << std::endl;
	std::cout << "Insert 10: " << t2.insert(10).second << std::endl;
	std::cout << "Insert 9: " << t2.insert(9).second << std::endl;
	std::cout << "Insert 30: " << t2.insert(30).second << std::endl;
	std::cout << "Insert 672: " << t2.insert(672).second << std::endl;
	std::cout << "Insert 308: " << t2.insert(308).second << std::endl;

	std::cout << "t2: " << t2 << std::endl;

	return 0;
}
