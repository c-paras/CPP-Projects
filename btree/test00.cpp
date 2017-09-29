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

	for (btree<char>::iterator it = t1.begin(); it != t1.end(); ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}
