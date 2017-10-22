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
	//test 1: ensure multi-threaded version matches single-threaded version
	{
		std::cout << "Testing output correctness on pre-defined vectors:" << std::endl;
		unsigned int nums[12][50] = {
			{1}, {2, 3}, {5, 8, 1}, {3, 3, 3, 3}, {6, 6, 9, 1, 5, 6},
			{9, 8, 6, 5, 4, 2, 1}, {5, 5, 4, 4, 8, 8, 1, 1, 2, 3, 5},
			{4356, 1262, 24342, 82427, 53347, 1336, 8803, 8335, 953},
			{1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0}, {54, 86, 13, 1, 79},
			{32, 53, 3, 134, 643, 3, 5, 12, 52, 501, 98}
		};
		unsigned int sizes[12] = {1, 2, 3, 4, 6, 7, 11, 9, 5, 6, 5, 11};

		//get the total number of cores available
		const unsigned int numCores = std::thread::hardware_concurrency();

		//print the number of cores used
		std::cout << "Number of cores: " << numCores << std::endl;

		for (unsigned int i = 0; i < 12; ++i) {
			unsigned int totalNumbers = sizes[i];

			//create two sort objects
			BucketSort pbs1;
			BucketSort pbs2;

			//insert the numbers from the nums array into both objects' vectors
			for (unsigned int j = 0; j < totalNumbers; ++j) {
				pbs1.numbersToSort.push_back(nums[i][j]);
				pbs2.numbersToSort.push_back(nums[i][j]);
			}

			pbs1.simpleSort(); //call single-threaded sort
			pbs2.sort(numCores); //call multi-threaded sort

			//check if output matches
			if (pbs1.numbersToSort == pbs2.numbersToSort) {
				std::cout << "Output is correct" << std::endl;
			} else {
				std::cout << "Output is incorrect" << std::endl;

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
			}
		}
	}

	//test 2: compare single-threaded and multi-threaded versions
	{
		//sort a random number of numbers
		std::srand(std::time(0));
		const unsigned int totalNumbers = 500 + (std::rand() % 99999);

		//use current time as seed for the uniform distribution
		const unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 mt(seed);
		std::uniform_int_distribution<unsigned int>
			dist(1, std::numeric_limits<unsigned int>::max());

		//print number of numbers being sorted
		std::cout << std::endl << "Sorting " << totalNumbers << " numbers:" << std::endl;

		//create two sort objects
		BucketSort pbs1;
		BucketSort pbs2;

		//insert the uniform distribution numbers into both objects' vectors
		for (unsigned int i = 0; i < totalNumbers; ++i) {
			unsigned int n = dist(mt);
			pbs1.numbersToSort.push_back(n);
			pbs2.numbersToSort.push_back(n);
		}

		//get the total number of cores available
		const unsigned int numCores = std::thread::hardware_concurrency();

		for (unsigned int ncores = 1; ncores <= numCores; ++ncores) {
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
			pbs2.sort(ncores);

			//get current time and print difference
			auto end2 = std::chrono::high_resolution_clock::now();
			auto millis2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);
			std::cout << "Execution time for multi-threaded: " << millis2.count() << " milliseconds\n";

			//print the number of cores used
			std::cout << "Number of cores: " << ncores << std::endl;

			//check if output matches
			if (pbs1.numbersToSort == pbs2.numbersToSort) {
				std::cout << "Output is correct" << std::endl;
			} else {
				std::cout << "Output is incorrect" << std::endl;
			}
		}
	}

	//test 3 (speed test): with 8 cores (on wagner), single-threaded version
	//takes 23 seconds and multi-threaded version takes 6 seconds
	{
		const unsigned int totalNumbers = 500000;
		const unsigned int printIndex = 259000;

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
		std::cout << std::endl << "Speed test:" << std::endl;
		const unsigned int numCores = std::thread::hardware_concurrency();
		auto start = std::chrono::high_resolution_clock::now();

		//pbs.simpleSort(); //single-threaded version
		pbs.sort(numCores); //multi-threaded version

		//get current time and print difference
		auto end = std::chrono::high_resolution_clock::now();
		auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		std::cout << "Total execution time: " << millis.count() << " milliseconds\n";

		//print number of cores used
		std::cout << "Number of cores: " << numCores << std::endl;

		//print certain values from the buckets
		std::cout << "Demonstrating that all the numbers that start with 1 come first:" <<
		std::endl;
		std::cout << pbs.numbersToSort[0] << " " <<
		pbs.numbersToSort[printIndex - 10000] << " " <<
		pbs.numbersToSort[printIndex] << " " <<
		pbs.numbersToSort[pbs.numbersToSort.size() - 1] <<
		std::endl;
	}

	return 0;
}
