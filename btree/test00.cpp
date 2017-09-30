/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Test case for the Generic B-Tree.
 */

#include <iostream>
#include "btree.h"

//custom class for testing
class Car {
public:
	Car() : brand{""}, price{0} { }
	Car(const std::string& b, double p) : brand{b}, price{p} { }
	~Car() = default;
	Car(const Car& c) = default;
	Car& operator=(const Car& c) = default;
	std::string get_brand() const { return brand; }
	double get_price() const { return price; }
	friend bool operator<(const Car& a, const Car& b) { return a.price < b.price; }
	friend bool operator==(const Car& a, const Car& b) { return a.price == b.price; }
	friend std::ostream& operator<<(std::ostream& os, const Car& b) {
		std::cout << "(" << b.brand << ", " << b.price << ")";
		return os;
	}
private:
	std::string brand;
	double price;
};

int main(int argc, char *argv[]) {

	//enable printing of booleans as "true" and "false"
	std::cout << std::boolalpha;

	//create an empty btree of strings with a node size of 1000
	std::cout << "Create t0 of strings with node size 1000" << std::endl;
	btree<std::string> t0{1000};
	std::cout << "t0: " << t0 << std::endl;

	//create an empty btree of characters with a node size of 4
	std::cout << "Create t1 of chars with node size 4" << std::endl;
	btree<char> t1{4};
	std::cout << "t1: " << t1 << std::endl;

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
	std::cout << "t2: " << t2 << std::endl;

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

	//create an empty btree of strings with a node size of 40 (default)
	std::cout << "Create t3 of strings with node size 40" << std::endl;
	btree<std::string> t3{};
	std::cout << "t3: " << t3 << std::endl;

	//insert some unique keys, namely
	//A, B, C, D, ..., T, AA, BB, CC, DD, ..., TT, AAA, BBB, CCC, DDD, ..., TTT
	char chars[20] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};
	for (int len = 1; len <= 4; ++len) {
		for (int i = 0; i < 20; ++i) {
			std::string str = std::string{chars[i]};
			for (int j = 1; j < len; ++j) str += chars[i];
			std::cout << "Insert " << str << ": " << t3.insert(str).second << std::endl;
			std::cout << "t3: " << t3 << std::endl;
		}
	}

	//try to re-insert the keys again
	for (int len = 1; len <= 4; ++len) {
		for (int i = 0; i < 20; ++i) {
			std::string str = std::string{chars[i]};
			for (int j = 1; j < len; ++j) str += chars[i];
			std::cout << "Insert " << str << ": " << t3.insert(str).second << std::endl;
		}
	}

	std::cout << "t3: " << t3 << std::endl;

	//create an empty btree of Car objects with a node size of 9
	std::cout << "Create t4 of Car objects with node size 9" << std::endl;
	btree<Car> t4{9};
	std::cout << "t4: " << t4 << std::endl;

	//insert some unique keys
	std::cout << "Insert (Toyota, 15000): " << t4.insert(Car("Toyota", 15000)).second << std::endl;
	std::cout << "Insert (Nissan, 27000): " << t4.insert(Car("Nissan", 27000)).second << std::endl;
	std::cout << "Insert (Ford, 38000): " << t4.insert(Car("Ford", 38000)).second << std::endl;
	std::cout << "Insert (Honda, 19000): " << t4.insert(Car("Honda", 19000)).second << std::endl;
	std::cout << "Insert (Hyundai, 42000): " << t4.insert(Car("Hyundai", 42000)).second << std::endl;
	std::cout << "t4: " << t4 << std::endl;
	std::cout << "Insert (Toyota, 15001): " << t4.insert(Car("Toyota", 15001)).second << std::endl;
	std::cout << "Insert (Nissan, 27001): " << t4.insert(Car("Nissan", 27001)).second << std::endl;
	std::cout << "Insert (Ford, 38001): " << t4.insert(Car("Ford", 38001)).second << std::endl;
	std::cout << "Insert (Honda, 19001): " << t4.insert(Car("Honda", 19001)).second << std::endl;
	std::cout << "Insert (Hyundai, 42001): " << t4.insert(Car("Hyundai", 42001)).second << std::endl;
	std::cout << "t4: " << t4 << std::endl;
	std::cout << "Insert (Toyota, 14999): " << t4.insert(Car("Toyota", 14999)).second << std::endl;
	std::cout << "Insert (Nissan, 26999): " << t4.insert(Car("Nissan", 26999)).second << std::endl;
	std::cout << "Insert (Ford, 37999): " << t4.insert(Car("Ford", 37999)).second << std::endl;
	std::cout << "Insert (Honda, 18999): " << t4.insert(Car("Honda", 18999)).second << std::endl;
	std::cout << "Insert (Hyundai, 41999): " << t4.insert(Car("Hyundai", 41999)).second << std::endl;
	std::cout << "t4: " << t4 << std::endl;

	//try to re-insert the keys again
	std::cout << "Insert (Toyota, 15000): " << t4.insert(Car("Toyota", 15000)).second << std::endl;
	std::cout << "Insert (Nissan, 27000): " << t4.insert(Car("Nissan", 27000)).second << std::endl;
	std::cout << "Insert (Ford, 38000): " << t4.insert(Car("Ford", 38000)).second << std::endl;
	std::cout << "Insert (Honda, 19000): " << t4.insert(Car("Honda", 19000)).second << std::endl;
	std::cout << "Insert (Hyundai, 42000): " << t4.insert(Car("Hyundai", 42000)).second << std::endl;
	std::cout << "Insert (Toyota, 15001): " << t4.insert(Car("Toyota", 15001)).second << std::endl;
	std::cout << "Insert (Nissan, 27001): " << t4.insert(Car("Nissan", 27001)).second << std::endl;
	std::cout << "Insert (Ford, 38001): " << t4.insert(Car("Ford", 38001)).second << std::endl;
	std::cout << "Insert (Honda, 19001): " << t4.insert(Car("Honda", 19001)).second << std::endl;
	std::cout << "Insert (Hyundai, 42001): " << t4.insert(Car("Hyundai", 42001)).second << std::endl;
	std::cout << "Insert (Toyota, 14999): " << t4.insert(Car("Toyota", 14999)).second << std::endl;
	std::cout << "Insert (Nissan, 26999): " << t4.insert(Car("Nissan", 26999)).second << std::endl;
	std::cout << "Insert (Ford, 37999): " << t4.insert(Car("Ford", 37999)).second << std::endl;
	std::cout << "Insert (Honda, 18999): " << t4.insert(Car("Honda", 18999)).second << std::endl;
	std::cout << "Insert (Hyundai, 41999): " << t4.insert(Car("Hyundai", 41999)).second << std::endl;

	std::cout << "t4: " << t4 << std::endl;

	//create an empty btree of characters with a node size of 1 (binary tree)
	std::cout << "Create t5 of chars with node size 1" << std::endl;
	btree<char> t5{1};
	std::cout << "t5: " << t5 << std::endl;

	//insert some unique keys
	std::cout << "Insert C: " << t5.insert('C').second << std::endl;
	std::cout << "Insert B: " << t5.insert('B').second << std::endl;
	std::cout << "Insert A: " << t5.insert('A').second << std::endl;
	std::cout << "Insert G: " << t5.insert('G').second << std::endl;
	std::cout << "Insert E: " << t5.insert('E').second << std::endl;
	std::cout << "Insert D: " << t5.insert('D').second << std::endl;
	std::cout << "Insert F: " << t5.insert('F').second << std::endl;

	std::cout << "t5: " << t5 << std::endl;

	//try to re-insert the keys again
	std::cout << "Insert C: " << t5.insert('C').second << std::endl;
	std::cout << "Insert B: " << t5.insert('B').second << std::endl;
	std::cout << "Insert A: " << t5.insert('A').second << std::endl;
	std::cout << "Insert G: " << t5.insert('G').second << std::endl;
	std::cout << "Insert E: " << t5.insert('E').second << std::endl;
	std::cout << "Insert D: " << t5.insert('D').second << std::endl;
	std::cout << "Insert F: " << t5.insert('F').second << std::endl;

	std::cout << "t5: " << t5 << std::endl;

	//create an empty btree of characters with a node size of 1 (binary tree)
	std::cout << "Create t6 of chars with node size 1" << std::endl;
	btree<char> t6{1};
	std::cout << "t6: " << t6 << std::endl;

	//insert some unique keys
	std::cout << "Insert J: " << t6.insert('J').second << std::endl;
	std::cout << "Insert H: " << t6.insert('H').second << std::endl;
	std::cout << "Insert L: " << t6.insert('L').second << std::endl;
	std::cout << "Insert G: " << t6.insert('G').second << std::endl;
	std::cout << "Insert N: " << t6.insert('N').second << std::endl;
	std::cout << "Insert E: " << t6.insert('E').second << std::endl;
	std::cout << "Insert P: " << t6.insert('P').second << std::endl;
	std::cout << "Insert C: " << t6.insert('C').second << std::endl;
	std::cout << "Insert R: " << t6.insert('R').second << std::endl;
	std::cout << "Insert A: " << t6.insert('A').second << std::endl;
	std::cout << "Insert T: " << t6.insert('T').second << std::endl;

	std::cout << "t6: " << t6 << std::endl;

	//try to re-insert the keys again
	std::cout << "Insert J: " << t6.insert('J').second << std::endl;
	std::cout << "Insert H: " << t6.insert('H').second << std::endl;
	std::cout << "Insert L: " << t6.insert('L').second << std::endl;
	std::cout << "Insert G: " << t6.insert('G').second << std::endl;
	std::cout << "Insert N: " << t6.insert('N').second << std::endl;
	std::cout << "Insert E: " << t6.insert('E').second << std::endl;
	std::cout << "Insert P: " << t6.insert('P').second << std::endl;
	std::cout << "Insert C: " << t6.insert('C').second << std::endl;
	std::cout << "Insert R: " << t6.insert('R').second << std::endl;
	std::cout << "Insert A: " << t6.insert('A').second << std::endl;
	std::cout << "Insert T: " << t6.insert('T').second << std::endl;

	std::cout << "t6: " << t6 << std::endl;

	//create an empty btree of unsigned integers with a node size of 3
	std::cout << "Create t7 of unsigned integers with node size 3" << std::endl;
	btree<unsigned long> t7{3};
	std::cout << "t7: " << t7 << std::endl;

	//insert some unique keys
	std::cout << "Insert 4: " << t7.insert(4).second << std::endl;
	std::cout << "Insert 8: " << t7.insert(8).second << std::endl;
	std::cout << "Insert 12: " << t7.insert(12).second << std::endl;
	std::cout << "Insert 14: " << t7.insert(14).second << std::endl;
	std::cout << "Insert 70: " << t7.insert(70).second << std::endl;
	std::cout << "Insert 138: " << t7.insert(138).second << std::endl;
	std::cout << "Insert 13: " << t7.insert(13).second << std::endl;
	for (unsigned long i = 15; i < 70; ++i) {
		std::cout << "Insert " << i << ": " << t7.insert(i).second << std::endl;
	}

	std::cout << "t7: " << t7 << std::endl;

	//try to re-insert the keys again
	std::cout << "Insert 4: " << t7.insert(4).second << std::endl;
	std::cout << "Insert 8: " << t7.insert(8).second << std::endl;
	std::cout << "Insert 12: " << t7.insert(12).second << std::endl;
	std::cout << "Insert 14: " << t7.insert(14).second << std::endl;
	std::cout << "Insert 70: " << t7.insert(70).second << std::endl;
	std::cout << "Insert 138: " << t7.insert(138).second << std::endl;
	std::cout << "Insert 13: " << t7.insert(13).second << std::endl;
	for (unsigned long i = 15; i < 70; ++i) {
		std::cout << "Insert " << i << ": " << t7.insert(i).second << std::endl;
	}

	std::cout << "t7: " << t7 << std::endl;

	//create an empty btree of integers with a node size of 100
	std::cout << "Create t8 of integers with node size 100" << std::endl;
	btree<long long int> t8{100};
	std::cout << "t8: " << t8 << std::endl;

	//insert some unique keys
	for (long long int i = 1; i <= 300; ++i) {
		std::cout << "Insert " << i << ": " << t8.insert(i).second << std::endl;
	}

	std::cout << "t8: " << t8 << std::endl;

	//try to re-insert the keys again
	for (long int i = 1; i <= 300; ++i) {
		std::cout << "Insert " << i << ": " << t8.insert(i).second << std::endl;
	}

	std::cout << "t8: " << t8 << std::endl;

	//create an empty btree of integers with a node size of 100
	std::cout << "Create t9 of integers with node size 100" << std::endl;
	btree<long long int> t9{100};
	std::cout << "t9: " << t9 << std::endl;

	//insert some unique keys
	for (long long int i = 300; i >= 1; --i) {
		std::cout << "Insert " << i << ": " << t9.insert(i).second << std::endl;
	}

	std::cout << "t9: " << t9 << std::endl;

	//try to re-insert the keys again
	for (long int i = 300; i >= 1; --i) {
		std::cout << "Insert " << i << ": " << t9.insert(i).second << std::endl;
	}

	std::cout << "t9: " << t9 << std::endl;

	//create an empty btree of integers with a node size of 40 (default)
	std::cout << "Create t10 of integers with node size 40" << std::endl;
	btree<int> t10;
	std::cout << "t10: " << t10 << std::endl;

	//insert some unique keys
	std::cout << "Insert: " << t10.insert(16).second << std::endl;
	std::cout << "Insert: " << t10.insert(42).second << std::endl;
	std::cout << "Insert: " << t10.insert(-18).second << std::endl;
	std::cout << "Insert: " << t10.insert(0).second << std::endl;
	std::cout << "Insert: " << t10.insert(934).second << std::endl;
	std::cout << "Insert: " << t10.insert(113).second << std::endl;
	std::cout << "Insert: " << t10.insert(-392).second << std::endl;

	std::cout << "t10: " << t10 << std::endl;

	//try to re-insert the keys again
	std::cout << "Insert: " << t10.insert(16).second << std::endl;
	std::cout << "Insert: " << t10.insert(42).second << std::endl;
	std::cout << "Insert: " << t10.insert(-18).second << std::endl;
	std::cout << "Insert: " << t10.insert(0).second << std::endl;
	std::cout << "Insert: " << t10.insert(934).second << std::endl;
	std::cout << "Insert: " << t10.insert(113).second << std::endl;
	std::cout << "Insert: " << t10.insert(-392).second << std::endl;

	std::cout << "t10: " << t10 << std::endl;

	//do an in-order traversal of all the trees
	std::cout << "t1 traversal:";
	for (auto it = t1.begin(); it != t1.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << "t2 traversal:";
	for (auto it = t2.begin(); it != t2.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << "t3 traversal:";
	for (auto it = t3.begin(); it != t3.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << "t4 traversal:";
	for (auto it = t4.begin(); it != t4.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << "t5 traversal:";
	for (auto it = t5.begin(); it != t5.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << "t6 traversal:";
	for (auto it = t6.begin(); it != t6.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << "t7 traversal:";
	for (auto it = t7.begin(); it != t7.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << "t8 traversal:";
	for (auto it = t8.begin(); it != t8.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << "t9 traversal:";
	for (auto it = t9.begin(); it != t9.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	std::cout << "t10 traversal:";
	for (auto it = t10.begin(); it != t10.end(); ++it) {
		std::cout << " " << *it;
	}
	std::cout << std::endl;

	//validate the iterator code
	std::cout << "Check that begin() and end() return the right thing" << std::endl;
	btree<std::string>::iterator beg0 = t0.begin();
	btree<char>::iterator beg1 = t1.begin();
	btree<int>::iterator beg2 = t2.begin();
	btree<std::string>::iterator beg3 = t3.begin();
	btree<Car>::iterator beg4 = t4.begin();
	btree<char>::iterator beg5 = t5.begin();
	btree<char>::iterator beg6 = t6.begin();
	btree<unsigned long>::iterator beg7 = t7.begin();
	btree<long long int>::iterator beg8 = t8.begin();
	btree<long long int>::iterator beg9 = t9.begin();
	btree<int>::iterator beg10 = t10.begin();

	btree<std::string>::iterator end0 = t0.end();
	btree<char>::iterator end1 = t1.end();
	btree<int>::iterator end2 = t2.end();
	btree<std::string>::iterator end3 = t3.end();
	btree<Car>::iterator end4 = t4.end();
	btree<char>::iterator end5 = t5.end();
	btree<char>::iterator end6 = t6.end();
	btree<unsigned long>::iterator end7 = t7.end();
	btree<long long int>::iterator end8 = t8.end();
	btree<long long int>::iterator end9 = t9.end();
	btree<int>::iterator end10 = t10.end();

	std::cout << "Check that the dereference operator works:" << std::endl;
	std::cout << "First in char tree: " << *beg1 << std::endl;
	std::cout << "First in int tree: " << *beg2 << std::endl;
	std::cout << "First in string tree: " << *beg3 << std::endl;
	std::cout << "First in Car tree: " << *beg4 << std::endl;
	std::cout << "First in char tree: " << *beg5 << std::endl;
	std::cout << "First in char tree: " << *beg6 << std::endl;
	std::cout << "First in unsigned long tree: " << *beg7 << std::endl;
	std::cout << "First in long long int tree: " << *beg8 << std::endl;
	std::cout << "First in long long int tree: " << *beg9 << std::endl;
	std::cout << "First in int tree: " << *beg10 << std::endl;

	std::cout << "Check that the arrow operator works:" << std::endl;
	std::cout << "First brand: " << beg4->get_brand() << std::endl;
	std::cout << "First price: " << beg4->get_price() << std::endl;

	std::cout << "Check that the (in)equality operators work:" << std::endl;
	std::cout << (beg0 == end0) << std::endl; //true since tree is empty
	std::cout << (beg1 == end1) << std::endl;
	std::cout << (beg2 == end2) << std::endl;
	std::cout << (beg3 == end3) << std::endl;
	std::cout << (beg4 == end4) << std::endl;
	std::cout << (beg5 == end5) << std::endl;
	std::cout << (beg6 == end6) << std::endl;
	std::cout << (beg7 == end7) << std::endl;
	std::cout << (beg8 == end8) << std::endl;
	std::cout << (beg9 == end9) << std::endl;
	std::cout << (beg10 == end10) << std::endl;

	std::cout << (beg0 != end0) << std::endl; //false since tree is empty
	std::cout << (beg1 != end1) << std::endl;
	std::cout << (beg2 != end2) << std::endl;
	std::cout << (beg3 != end3) << std::endl;
	std::cout << (beg4 != end4) << std::endl;
	std::cout << (beg5 != end5) << std::endl;
	std::cout << (beg6 != end6) << std::endl;
	std::cout << (beg7 != end7) << std::endl;
	std::cout << (beg8 != end8) << std::endl;
	std::cout << (beg9 != end9) << std::endl;
	std::cout << (beg10 != end10) << std::endl;

	//check that find() works
	std::cout << "Search for keys in the btrees" << std::endl;

	std::cout << (*t1.find('M') == 'M') << std::endl;
	std::cout << (*t1.find('X') == 'X') << std::endl;
	std::cout << (*t1.find('P') == 'P') << std::endl;
	std::cout << (*t1.find('G') == 'G') << std::endl;
	std::cout << (*t1.find('T') == 'T') << std::endl;
	std::cout << (*t1.find('B') == 'B') << std::endl;
	std::cout << (*t1.find('Z') == 'Z') << std::endl;
	std::cout << (*t1.find('N') == 'N') << std::endl;
	std::cout << (*t1.find('R') == 'R') << std::endl;
	std::cout << (*t1.find('S') == 'S') << std::endl;
	std::cout << (*t1.find('W') == 'W') << std::endl;
	std::cout << (*t1.find('Q') == 'Q') << std::endl;
	std::cout << (*t1.find('V') == 'V') << std::endl;

	std::cout << (*t2.find(16) == 16) << std::endl;
	std::cout << (*t2.find(-248) == -248) << std::endl;
	std::cout << (*t2.find(672) == 672) << std::endl;

	std::cout << (*t3.find("A") == "A") << std::endl;
	std::cout << (*t3.find("BB") == "BB") << std::endl;
	std::cout << (*t3.find("CCC") == "CCC") << std::endl;

	Car c1 = Car("Toyota", 15000);
	std::cout << (*t4.find(c1) == c1) << std::endl;
	Car c2 = Car("Nissan", 26999);
	std::cout << (*t4.find(c2) == c2) << std::endl;
	Car c3 = Car("Honda", 18999);
	std::cout << (*t4.find(c3) == c3) << std::endl;

	std::cout << (*t5.find('C') == 'C') << std::endl;
	std::cout << (*t5.find('B') == 'B') << std::endl;
	std::cout << (*t5.find('A') == 'A') << std::endl;
	std::cout << (*t5.find('G') == 'G') << std::endl;
	std::cout << (*t5.find('E') == 'E') << std::endl;
	std::cout << (*t5.find('D') == 'D') << std::endl;
	std::cout << (*t5.find('F') == 'F') << std::endl;

	std::cout << (*t6.find('J') == 'J') << std::endl;
	std::cout << (*t6.find('G') == 'G') << std::endl;
	std::cout << (*t6.find('R') == 'R') << std::endl;

	std::cout << (*t7.find(4) == 4) << std::endl;
	std::cout << (*t7.find(8) == 8) << std::endl;
	std::cout << (*t7.find(12) == 12) << std::endl;
	std::cout << (*t7.find(14) == 14) << std::endl;
	std::cout << (*t7.find(70) == 70) << std::endl;
	std::cout << (*t7.find(138) == 138) << std::endl;
	std::cout << (*t7.find(13) == 13) << std::endl;
	for (unsigned long i = 15; i < 70; ++i) {
		std::cout << (*t7.find(i) == i) << std::endl;
	}

	bool error = false;
	for (long long int i = 1; i <= 300; ++i) {
		if (t8.find(i) == t8.end() || *t8.find(i) != i) {
			std::cout << "Error: key " << i << " not in t8" << std::endl;
			error = true;
		}
	}
	if (error == false) std::cout << "All keys in t8 found" << std::endl;

	error = false;
	for (long long int i = 1; i <= 300; ++i) {
		if (t9.find(i) == t9.end() || *t9.find(i) != i) {
			std::cout << "Error: key " << i << " not in t9" << std::endl;
			error = true;
		}
	}
	if (error == false) std::cout << "All keys in t9 found" << std::endl;

	std::cout << (*t10.find(16) == 16) << std::endl;
	std::cout << (*t10.find(42) == 42) << std::endl;
	std::cout << (*t10.find(-18) == -18) << std::endl;
	std::cout << (*t10.find(0) == 0) << std::endl;
	std::cout << (*t10.find(934) == 934) << std::endl;
	std::cout << (*t10.find(113) == 113) << std::endl;
	std::cout << (*t10.find(-392) == -392) << std::endl;

	std::cout << "Search for keys not in the btrees" << std::endl;

	std::cout << (t1.find('A') == t1.end()) << std::endl;
	std::cout << (t1.find('C') == t1.end()) << std::endl;
	std::cout << (t1.find('D') == t1.end()) << std::endl;
	std::cout << (t1.find('E') == t1.end()) << std::endl;
	std::cout << (t1.find('F') == t1.end()) << std::endl;
	std::cout << (t1.find('H') == t1.end()) << std::endl;
	std::cout << (t1.find('I') == t1.end()) << std::endl;
	std::cout << (t1.find('J') == t1.end()) << std::endl;
	std::cout << (t1.find('K') == t1.end()) << std::endl;
	std::cout << (t1.find('L') == t1.end()) << std::endl;
	std::cout << (t1.find('O') == t1.end()) << std::endl;
	std::cout << (t1.find('U') == t1.end()) << std::endl;
	std::cout << (t1.find('Y') == t1.end()) << std::endl;

	std::cout << (t2.find(31) == t2.end()) << std::endl;
	std::cout << (t2.find(999) == t2.end()) << std::endl;
	std::cout << (t2.find(-42) == t2.end()) << std::endl;

	std::cout << (t3.find("AAAAA") == t3.end()) << std::endl;
	std::cout << (t3.find("ABAB") == t3.end()) << std::endl;
	std::cout << (t3.find("CCA") == t3.end()) << std::endl;

	Car c4 = Car("Toyota", 23499);
	std::cout << (t4.find(c4) == t4.end()) << std::endl;
	Car c5 = Car("Honda", 45699);
	std::cout << (t4.find(c5) == t4.end()) << std::endl;
	Car c6 = Car("Suzuki", 12999);
	std::cout << (t4.find(c6) == t4.end()) << std::endl;

	std::cout << (t5.find('X') == t5.end()) << std::endl;
	std::cout << (t5.find('Z') == t5.end()) << std::endl;
	std::cout << (t5.find('Q') == t5.end()) << std::endl;
	std::cout << (t5.find('Y') == t5.end()) << std::endl;
	std::cout << (t5.find('W') == t5.end()) << std::endl;
	std::cout << (t5.find('V') == t5.end()) << std::endl;
	std::cout << (t5.find('M') == t5.end()) << std::endl;

	std::cout << (t6.find('Z') == t6.end()) << std::endl;
	std::cout << (t6.find('Q') == t6.end()) << std::endl;
	std::cout << (t6.find('F') == t6.end()) << std::endl;

	std::cout << (t7.find(1) == t7.end()) << std::endl;
	std::cout << (t7.find(2) == t7.end()) << std::endl;
	std::cout << (t7.find(3) == t7.end()) << std::endl;
	std::cout << (t7.find(5) == t7.end()) << std::endl;
	std::cout << (t7.find(6) == t7.end()) << std::endl;
	std::cout << (t7.find(7) == t7.end()) << std::endl;
	std::cout << (t7.find(9) == t7.end()) << std::endl;
	std::cout << (t7.find(10) == t7.end()) << std::endl;
	std::cout << (t7.find(11) == t7.end()) << std::endl;
	for (unsigned long i = 71; i < 138; ++i) {
		std::cout << (t7.find(i) == t7.end()) << std::endl;
	}
	for (unsigned long i = 139; i < 150; ++i) {
		std::cout << (t7.find(i) == t7.end()) << std::endl;
	}

	std::cout << (t8.find(-1) == t8.end()) << std::endl;
	std::cout << (t8.find(301) == t8.end()) << std::endl;
	std::cout << (t8.find(994) == t8.end()) << std::endl;

	std::cout << (t9.find(-1) == t9.end()) << std::endl;
	std::cout << (t9.find(301) == t9.end()) << std::endl;
	std::cout << (t9.find(994) == t9.end()) << std::endl;

	std::cout << (t10.find(44) == t10.end()) << std::endl;
	std::cout << (t10.find(68) == t10.end()) << std::endl;
	std::cout << (t10.find(-4) == t10.end()) << std::endl;

	return 0;
}
