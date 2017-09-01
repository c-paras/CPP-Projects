/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Implementation of the EuclideanVector class library.
 */

#include <cmath>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <exception>
#include "EuclideanVector.h"

namespace evec {

//construct a vector with 1 dimension & default magnitude = 0.0
EuclideanVector::EuclideanVector() :
	EuclideanVector{1, 0.0} { }

//construct a vector with given # dimensions & default magnitude = 0.0
EuclideanVector::EuclideanVector(size_t n_dim) :
	EuclideanVector(n_dim, 0.0) { }

//construct a vector with given # dimensions & given magnitude
EuclideanVector::EuclideanVector(size_t n_dim, Scalar mag) {
	_dimension = n_dim;
	_vector = new Scalar[_dimension];
	for (size_t i = 0; i < _dimension; ++i) _vector[i] = mag;
}

//construct a vector from a std::list iterator
EuclideanVector::EuclideanVector(std::list<Scalar>::iterator begin, std::list<Scalar>::iterator end) :
	_dimension{static_cast<size_t>(std::distance(begin, end))} {
	_vector = new Scalar[_dimension];
	int i = 0;
	while (begin != end) {
		_vector[i++] = *begin++;
	}
}

//construct a vector from a std::vector iterator
EuclideanVector::EuclideanVector(std::vector<Scalar>::iterator begin, std::vector<Scalar>::iterator end) :
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

//copy constructor
EuclideanVector::EuclideanVector(const EuclideanVector& e) {
	_dimension = e._dimension;
	_vector = new Scalar[_dimension];
	for (size_t i = 0; i < _dimension; ++i) _vector[i] = e._vector[i];
}

//move constructor
EuclideanVector::EuclideanVector(EuclideanVector&& e) :
	_vector{std::move(_vector)}, _dimension{std::move(_dimension)} {
	e._vector = nullptr;
	e._dimension = 0;
}

//destructor
EuclideanVector::~EuclideanVector() {
	if (_vector != nullptr) {
		delete [] _vector;
	}
}

//copy assignment operator
EuclideanVector& EuclideanVector::operator=(const EuclideanVector& e) {
	if (this != &e) {
		delete [] _vector;
		_dimension = e._dimension;
		_vector = new Scalar[_dimension];
		for (size_t i = 0; i < _dimension; ++i) _vector[i] = e._vector[i];
	}
	return *this;
}

//move assignment operator
EuclideanVector& EuclideanVector::operator=(EuclideanVector&& e) {
	if (this != &e) {
		//TODO
		/*
		delete [] _vector;
		_dimension = e._dimension;
		//_vector = std::move(e._vector);
		_vector = e._vector;
		//_vector = new Scalar[_dimension];
		//for (size_t i = 0; i < _dimension; ++i) _vector[i] = e._vector[i];
		//delete [] e._vector;
		e._vector = nullptr;
		e._dimension = 0;
		*/
	}
	return *this;
}

//return the number of dimensions
size_t EuclideanVector::getNumDimensions() const {
	return _dimension;
}

//return the magnitude in the given dimension
Scalar EuclideanVector::get(size_t pos) {
	if (pos >= _dimension) {
		throw std::invalid_argument("Position is too big for this vector");
	}
	return _vector[pos];
}

//return the Euclidean norm of the vector
Scalar EuclideanVector::getEuclideanNorm() {
	double norm = 0;
	for (size_t i = 0; i < _dimension; ++i) {
		norm += pow(_vector[i], 2);
	}
	return sqrt(norm);
}

//return the unit vector for the Euclidean vector
EuclideanVector EuclideanVector::createUnitVector() {
	Scalar norm = getEuclideanNorm();
	std::vector<Scalar> magnitudes;
	for (size_t i = 0; i < _dimension; ++i) {
		magnitudes.push_back(_vector[i]/norm);
	}
	EuclideanVector unit{magnitudes.begin(), magnitudes.end()};
	return unit;
}

//get the magnitude in the given dimension
Scalar& EuclideanVector::operator[](int i) {
	int dim = static_cast<int>(_dimension);
	if (i < 0 || i >= dim) throw std::invalid_argument("Bad index");
	return _vector[i];
}

//set the magnitude in the given dimension
Scalar EuclideanVector::operator[](int i) const {
	int dim = static_cast<int>(_dimension);
	if (i < 0 || i >= dim) throw std::invalid_argument("Bad index");
	return _vector[i];
}

//transform the first vector by applying the given operator
EuclideanVector& applyWith(EuclideanVector &a, const EuclideanVector &b, auto op) {
	if (a.getNumDimensions() != b.getNumDimensions()) {
		throw std::invalid_argument("Vectors must have same dimension");
	}
	for (size_t i = 0; i < a.getNumDimensions(); ++i) {
		a[i] = op(a[i], b[i]);
	}
	return a;
}

//overloaded += operator for adding vectors of same dimension
EuclideanVector& EuclideanVector::operator+=(const EuclideanVector& rhs) {
	return applyWith(*this, rhs, std::plus<Scalar>());
}

//overloaded -= operator for subtracting vectors of same dimension
EuclideanVector& EuclideanVector::operator-=(const EuclideanVector& rhs) {
	return applyWith(*this, rhs, std::minus<Scalar>());
}

//transform the given vector by applying the given operator
EuclideanVector& applyWith(EuclideanVector &a, const Scalar& c, auto op) {
	for (size_t i = 0; i < a.getNumDimensions(); ++i) {
		a[i] = op(a[i], c);
	}
	return a;
}

//overloaded /= operator for scalar multiplication
EuclideanVector& EuclideanVector::operator*=(const Scalar& rhs) {
	return applyWith(*this, rhs, std::multiplies<Scalar>());
}

//overloaded /= operator for scalar division
EuclideanVector& EuclideanVector::operator/=(const Scalar& rhs) {
	return applyWith(*this, rhs, std::divides<Scalar>());
}

//print vector in the form [v1 v2 v3 ...]
std::ostream& operator<<(std::ostream &os, const EuclideanVector &v) {
	std::cout << "[";
	for (size_t i = 0; i < v._dimension; ++i) {
		if (i > 0) std::cout << " ";
		std::cout << v._vector[i];
	}
	std::cout << "]";
	return os;
}

}
