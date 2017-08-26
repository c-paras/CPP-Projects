/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Implementation of the EuclideanVector class library.
 */

#include <iostream>
#include "EuclideanVector.h"

namespace evec {

//construct a vector with 1 dimensions & default magnitude = 0.0
EuclideanVector::EuclideanVector() :
	EuclideanVector{1, 0.0} { }

//construct a vector with given # dimensions & default magnitude = 0.0
EuclideanVector::EuclideanVector(size_t n_dim) :
	EuclideanVector(n_dim, 0.0) { }

//construct a vector with given # dimensions & given magnitude
EuclideanVector::EuclideanVector(size_t n_dim, Scalar mag) {
	_dimension = n_dim;
	_vector = new Scalar[_dimension]{mag};
}

//construct a vector from a std::list or std::vector iterator
//TODO
//template <class T>
//EuclideanVector::EuclideanVector(T begin, T end) :
EuclideanVector::EuclideanVector(std::_List_iterator<int> begin, std::_List_iterator<int> end) :
	_dimension{static_cast<size_t>(std::distance(begin, end))} {
	_vector = new Scalar[_dimension];
	int i = 0;
	while (begin != end) {
		_vector[i++] = *begin++;
	}
}

//construct a vector from an initializer list
EuclideanVector::EuclideanVector(std::initializer_list<Scalar> lst) :
	_dimension{lst.size()} {
	_vector = new Scalar[_dimension];
	int i = 0;
	for (auto begin = lst.begin(); begin != lst.end(); ++begin) {
		_vector[i++] = *begin;
	}
}

std::ostream& operator<<(std::ostream &os, const EuclideanVector &v) {
	//TODO
	return os;
}

}
