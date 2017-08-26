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
	EuclideanVector(size_t n_dim);
	EuclideanVector(size_t n_dim, Scalar mag);
	template<class T>
	EuclideanVector(T begin, T end);
	EuclideanVector(std::initializer_list<Scalar> lst);

	friend std::ostream& operator<<(std::ostream &os, const EuclideanVector &v);

private:
	Scalar* _vector;
	size_t _dimension;
};

}

#endif
