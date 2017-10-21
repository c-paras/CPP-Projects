/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Implementation of the Parallel Bucket Sort.
 *
 * Sorts a vector of unsigned integers using a parallel MSD radix sort
 * algorithm.
 */

#include <cmath>
#include <iostream>
#include <algorithm>
#include "BucketSort.h"

bool aLessB(const unsigned int& x, const unsigned int& y, unsigned int pow) {
	//if x and y are the same, then one is not less than the other
	if (x == y) return false;

	unsigned int a = x;
	unsigned int b = y;

	//work out the digit currently being compared
	if (pow == 0) {
		while (a / 10 > 0) {
			a = a / 10;
		}
		while (b / 10 > 0) {
			b = b / 10;
		}
	} else {
		while (a / 10 >= (unsigned int) std::round(std::pow(10, pow))) {
			a = a / 10;
		}
		while (b / 10 >= (unsigned int) std::round(std::pow(10, pow))) {
			b = b / 10;
		}
	}

	if (a == b) {
		return aLessB(x, y, pow + 1); //recurse if this digit is the same
	} else {
		return a < b; //otherwise, compare the digits
	}
}

//sort the vector using a single-threaded sorting algorithm
//TODO: comment out
void BucketSort::simpleSort() {
	std::sort(numbersToSort.begin(), numbersToSort.end(),
	[] (const unsigned int& x, const unsigned int& y) {
		return aLessB(x, y, 0);
	});
}

//sort the vector by creating numCores - 1 threads
void BucketSort::sort(unsigned int numCores) {
	std::sort(numbersToSort.begin(), numbersToSort.end(),
	[] (const unsigned int& x, const unsigned int& y) {
		return aLessB(x, y, 0);
	});
}
