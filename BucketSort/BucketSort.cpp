/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Implementation of the Parallel Bucket Sort.
 *
 * Sorts a vector of unsigned integers using a parallel MSD radix sort
 * algorithm.
 */

#include <cmath>
#include <vector>
#include <string>
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
void BucketSort::simpleSort() {
	std::sort(numbersToSort.begin(), numbersToSort.end(),
	[] (const auto& x, const auto& y) {
		return aLessB(x, y, 0);
	});
}

//sort the vector by creating numCores - 1 threads
void BucketSort::sort(unsigned int numCores) {
	doSort(0); //sort recursively, starting with the most significant digit
}

//sort a bucket based on the k-th most significant digit
void BucketSort::doSort(unsigned int k) {
	//if less than 2 items or already sorted, return straight away
	if (numbersToSort.size() < 2 ||
	std::is_sorted(numbersToSort.begin(), numbersToSort.end(),
	[] (const auto& x, const auto& y) {
		return aLessB(x, y, 0);
	})) {
		return;
	}

	//create vector of 11 empty buckets
	//each bucket corresponds to a possible msd
	//the first bucket stores numbers with k-th msd equal to -1 (padding)
	unsigned int numBuckets = 11;
	std::vector<BucketSort> buckets;
	buckets.reserve(numBuckets);
	buckets.insert(buckets.begin(), numBuckets, BucketSort{});

	//place each number in the appropriate bucket
	for (const auto& n: numbersToSort) {
		//find the k-th most-significant digit
		//set to -1 for padding if less than k digits in number
		std::string s = std::to_string(n);
		unsigned int msd = (k >= s.length()) ? -1 : s[k] - '0';

		//place number in the bucket for the k-th msd
		buckets[++msd].numbersToSort.emplace_back(n);
	}

	//sort each bucket recursively
	unsigned int nextDigit = k + 1; //i.e. shift to next msd
	unsigned int i{0};
	for (; i < numBuckets; ++i) {
		if (buckets[i].numbersToSort.size() > 1) {
			buckets[i].doSort(nextDigit);
		}
	}

	//combine all sorted buckets into original bucket
	numbersToSort.clear();
	for (i = 0; i < numBuckets; ++i) {
		if (buckets[i].numbersToSort.size() > 0) {
			numbersToSort.insert(numbersToSort.end(),
			buckets[i].numbersToSort.begin(), buckets[i].numbersToSort.end());
		}
	}
}
