/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Interface for the EuclideanVector class library.
 */

#ifndef EUCLIDEAN_VECTOR_H
#define EUCLIDEAN_VECTOR_H

namespace evec {

using Scalar = double;

class EuclideanVector {
public:
	//constructors
	EuclideanVector();
	EuclideanVector(unsigned int n_dim);
	EuclideanVector(unsigned int n_dim, Scalar mag);

	friend std::ostream& operator<<(std::ostream &os, const EuclideanVector &v);

private:
	Scalar* _vector;
	unsigned int _dimension;
};

}

#endif
