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
	EuclideanVector();
	friend std::ostream& operator<<(std::ostream &os, const EuclideanVector &v);
private:
	Scalar* _vector;
	unsigned int _dimension;
};

}

#endif
