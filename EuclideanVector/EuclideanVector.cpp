/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Implementation of the EuclideanVector class library.
 */

#include <cmath>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <exception>
#include <algorithm>
#include "EuclideanVector.h"

namespace evec {

//construct a vector with 1 dimension & default magnitude = 0.0
EuclideanVector::EuclideanVector() :
	EuclideanVector(1, 0.0) { }

//construct a vector with given # dimensions & default magnitude = 0.0
EuclideanVector::EuclideanVector(size_t n_dim) :
	EuclideanVector(n_dim, 0.0) { }

//construct a vector with given # dimensions & given magnitude
EuclideanVector::EuclideanVector(size_t n_dim, Scalar mag) {
	_dimension = n_dim;
	_vector = new Scalar[_dimension];
	std::fill(_vector, _vector + _dimension, mag);
}

//construct a vector from a std::list iterator
EuclideanVector::EuclideanVector(std::list<Scalar>::iterator begin, std::list<Scalar>::iterator end) :
	_dimension{static_cast<size_t>(std::distance(begin, end))} {
	_vector = new Scalar[_dimension];
	std::copy(begin, end, _vector);
}

//construct a vector from a std::vector iterator
EuclideanVector::EuclideanVector(std::vector<Scalar>::iterator begin, std::vector<Scalar>::iterator end) :
	_dimension{static_cast<size_t>(std::distance(begin, end))} {
	_vector = new Scalar[_dimension];
	std::copy(begin, end, _vector);
}

//construct a vector from an initializer list
EuclideanVector::EuclideanVector(std::initializer_list<Scalar> lst) :
	_dimension{lst.size()} {
	_vector = new Scalar[_dimension];
	std::copy(lst.begin(), lst.end(), _vector);
}

//copy constructor
EuclideanVector::EuclideanVector(const EuclideanVector& e) {
	_dimension = e._dimension;
	_vector = new Scalar[_dimension];
	std::copy(e._vector, e._vector + e._dimension, _vector);
}

//move constructor
EuclideanVector::EuclideanVector(EuclideanVector&& e) noexcept :
	_vector(nullptr), _dimension(0) {
	_vector = e._vector;
	_dimension = e._dimension;
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
		std::copy(e._vector, e._vector + e._dimension, _vector);
	}
	return *this;
}

//move assignment operator
EuclideanVector& EuclideanVector::operator=(EuclideanVector&& e) noexcept {
	if (this != &e) {
		delete [] _vector;
		_dimension = e._dimension;
		_vector = e._vector;
		e._vector = nullptr;
		e._dimension = 0;
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
	Scalar norm = 0;
	std::for_each(_vector, _vector + _dimension, [&norm](const Scalar& mag) {
		norm += pow(mag, 2);
	});
	return sqrt(norm);
}

//return the unit vector for the Euclidean vector
EuclideanVector EuclideanVector::createUnitVector() {
	Scalar norm = getEuclideanNorm();
	std::vector<Scalar> magnitudes;
	std::for_each(_vector, _vector + _dimension, [&magnitudes, &norm](const Scalar& mag) {
		magnitudes.push_back(mag/norm);
	});
	EuclideanVector unit{magnitudes.begin(), magnitudes.end()};
	return unit;
}

//get the magnitude in the given dimension
Scalar& EuclideanVector::operator[](size_t i) {
	if (i >= _dimension) throw std::invalid_argument("Bad index");
	return _vector[i];
}

//set the magnitude in the given dimension
Scalar EuclideanVector::operator[](size_t i) const {
	if (i >= _dimension) throw std::invalid_argument("Bad index");
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

//cast a Euclidean vector to a std::vector
EuclideanVector::operator std::vector<Scalar>() const {
	return std::vector<Scalar>(_vector, _vector + _dimension);
}

//cast a Euclidean vector to a std::list
EuclideanVector::operator std::list<Scalar>() const {
	return std::list<Scalar>(_vector, _vector + _dimension);
}

//check if two vectors have the same dimension and magnitudes
bool operator==(const EuclideanVector& a, const EuclideanVector& b) {
	if (a._dimension != b._dimension) return false;
	for (size_t i = 0; i < a._dimension; ++i) {
		if (a._vector[i] != b._vector[i]) return false;
	}
	return true;
}

//check if two vectors have differing dimensions and/or magnitudes
bool operator!=(const EuclideanVector& a, const EuclideanVector& b) {
	return !(a == b);
}

//add two vectors of the same dimension
EuclideanVector operator+(const EuclideanVector& a, const EuclideanVector& b) {
	EuclideanVector c = a;
	c += b;
	return c;
}

//subtract two vectors of the same dimension
EuclideanVector operator-(const EuclideanVector& a, const EuclideanVector& b) {
	EuclideanVector c = a;
	c -= b;
	return c;
}

//perform dot-product multiplication on two vectors
Scalar operator*(const EuclideanVector& a, const EuclideanVector& b) {
	if (a._dimension != b._dimension) {
		throw std::invalid_argument("Vectors must have same dimension");
	}
	Scalar dot_product = 0;
	for (size_t i = 0; i < a._dimension; ++i) {
		dot_product += a._vector[i] * b._vector[i];
	}
	return dot_product;
}

//perform scalar multiplication on a vector
EuclideanVector operator*(const EuclideanVector& a, const Scalar& b) {
	EuclideanVector c = a;
	c *= b;
	return c;
}

//perform scalar multiplication on a vector
EuclideanVector operator*(const Scalar& a, const EuclideanVector& b) {
	EuclideanVector c = b;
	c *= a;
	return c;
}

//perform scalar division on a vector
EuclideanVector operator/(const EuclideanVector& a, const Scalar& b) {
	EuclideanVector c = a;
	c /= b;
	return c;
}

//print vector in the form [v1 v2 v3 ...]
std::ostream& operator<<(std::ostream &os, const EuclideanVector &v) {
	std::cout << "[";
	//write first n-1 magnitudes sequentially, space-delimited
	std::ostream_iterator<Scalar> out_it(std::cout, " ");
	std::copy(v._vector, v._vector + v._dimension - 1, out_it);
	//then write the last magnitude (without a trailing space)
	if (v._dimension > 0) std::cout << v._vector[v._dimension - 1];
	std::cout << "]";
	return os;
}

}
