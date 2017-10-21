/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Interface for the Parallel Bucket Sort.
 */

#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include <vector>

struct BucketSort {
	//vector of numbers
	std::vector<unsigned int> numbersToSort;

	//single-threaded sorting function
	void simpleSort(); //TODO: comment out

	//multi-threaded sorting function
	void sort(unsigned int numCores);
};

#endif
