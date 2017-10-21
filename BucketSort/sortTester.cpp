/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Test client code for the Parallel Bucket Sort.
 */

#include <thread>
#include <random>
#include <chrono>
#include <iostream>
#include <algorithm>
#include "BucketSort.h"

int main() {
	unsigned int nums[] = {32, 53, 3, 134, 643, 3, 5, 12, 52, 501, 98};
	unsigned int totalNumbers = sizeof(nums)/sizeof(unsigned int);
	//unsigned int totalNumbers = 100;

	//use current time as seed for the uniform distribution
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 mt(seed);
	std::uniform_int_distribution<unsigned int>
		dist(1, std::numeric_limits<unsigned int>::max());

	//print number of numbers being sorted
	std::cout << "Sorting " << totalNumbers << " numbers" << std::endl;

	//create two sort objects
	BucketSort pbs1;
	BucketSort pbs2;

	//insert the numbers from the nums array into both objects' vectors
	for (unsigned int i = 0; i < totalNumbers; ++i) {
		pbs1.numbersToSort.push_back(nums[i]);
		pbs2.numbersToSort.push_back(nums[i]);
		//unsigned int n = dist(mt);
		//pbs1.numbersToSort.push_back(n);
		//pbs2.numbersToSort.push_back(n);
	}

	//get the total number of cores available
	const unsigned int numCores = std::thread::hardware_concurrency();

	//get current time
	auto start1 = std::chrono::high_resolution_clock::now();

	//call single-threaded sort
	pbs1.simpleSort();

	//get current time and print difference
	auto end1 = std::chrono::high_resolution_clock::now();
	auto millis1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);
	std::cout << "Execution time for single-threaded: " << millis1.count() << " milliseconds\n";

	//get current time
	auto start2 = std::chrono::high_resolution_clock::now();

	//call multi-threaded sort
	pbs2.sort(numCores);

	//get current time and print difference
	auto end2 = std::chrono::high_resolution_clock::now();
	auto millis2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
	std::cout << "Execution time for multi-threaded: " << millis2.count() << " milliseconds\n";

	//print the number of cores used
	std::cout << "Number of cores: " << numCores << std::endl;

	//check if output matches
	std::cout << std::endl;
	if (pbs1.numbersToSort == pbs2.numbersToSort) {
		std::cout << "Output is correct" << std::endl;
	} else {
		std::cout << "Output is incorrect" << std::endl;
	}

	//print output from single-threaded sort
	std::cout << std::endl;
	std::cout << "Result of single-threaded sort:" << std::endl;
	bool first = true;
	for (const auto& num: pbs1.numbersToSort) {
		if (first == true) {
			std::cout << num;
			first = false;
		} else {
			std::cout << " " << num;
		}
	}
	std::cout << std::endl;

	//print output from multi-threaded sort
	std::cout << std::endl;
	std::cout << "Result of multi-threaded sort:" << std::endl;
	first = true;
	for (const auto& num: pbs2.numbersToSort) {
		if (first == true) {
			std::cout << num;
			first = false;
		} else {
			std::cout << " " << num;
		}
	}
	std::cout << std::endl;

	/*
	unsigned int totalNumbers = 500000;
	unsigned int printIndex = 259000;

	//use totalNumbers required as the seed for the random number generator
	std::mt19937 mt(totalNumbers);
	std::uniform_int_distribution<unsigned int>
	dist(1, std::numeric_limits<unsigned int>::max());

	//create a sort object
	BucketSort pbs;

	//insert random numbers into the sort object
	for (unsigned int i = 0; i < totalNumbers; ++i) {
		pbs.numbersToSort.push_back(dist(mt));
	}

	//call sort giving the number of cores available
	const unsigned int numCores = std::thread::hardware_concurrency();
	pbs.sort(numCores);

	std::cout << "Number of cores used: " << numCores << std::endl;

	//print certain values from the buckets
	std::cout << "Demonstrating that all the numbers that start with 1 come first:" <<
	std::endl;
	std::cout << pbs.numbersToSort[0] << " " <<
	pbs.numbersToSort[printIndex - 10000] << " " <<
	pbs.numbersToSort[printIndex] << " " <<
	pbs.numbersToSort[pbs.numbersToSort.size() - 1] <<
	std::endl;
	*/
}
