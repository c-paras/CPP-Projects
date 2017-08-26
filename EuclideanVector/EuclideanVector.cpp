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
EuclideanVector::EuclideanVector(unsigned int n_dim) :
	EuclideanVector{n_dim, 0.0} { }

//construct a vector with given # dimensions & given magnitude
EuclideanVector::EuclideanVector(unsigned int n_dim, Scalar mag) {
	_dimension = n_dim;
	_vector = new Scalar[_dimension]{mag};
}

std::ostream& operator<<(std::ostream &os, const EuclideanVector &v) {
	//TODO
	return os;
}

}
