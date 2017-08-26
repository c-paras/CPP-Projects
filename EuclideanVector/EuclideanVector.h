/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Interface for the EuclideanVector class library.
 */

#include <list>
#include <vector>

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
	//template<class Iter>
	//EuclideanVector(Iter begin, Iter end);
	EuclideanVector(std::_List_iterator<Scalar> begin, std::_List_iterator<Scalar> end);
	EuclideanVector(std::vector<Scalar>::iterator begin, std::vector<Scalar>::iterator end);
	EuclideanVector(std::initializer_list<Scalar> lst);

	friend std::ostream& operator<<(std::ostream &os, const EuclideanVector &v);

private:
	Scalar* _vector;
	size_t _dimension;
};

}

#endif
