/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Implementation of the EuclideanVector class library.
 */

#include <cmath>
#include <numeric>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <initializer_list>
#include "EuclideanVector.h"

namespace evec {

//construct a vector with 1 dimension & default magnitude = 0.0
EuclideanVector::EuclideanVector() :
	EuclideanVector(1, 0.0) { }

//construct a vector with given # dimensions & default magnitude = 0.0
EuclideanVector::EuclideanVector(size_t dim) :
	EuclideanVector(dim, 0.0) { }

//construct a vector with given # dimensions & given magnitude
EuclideanVector::EuclideanVector(size_t dim, Scalar mag) {
	_dimension = dim;
	_vector = new Scalar[_dimension];
	std::fill(_vector, _vector + _dimension, mag);
}

//construct a vector from a std::list iterator
EuclideanVector::EuclideanVector(std::list<Scalar>::const_iterator begin,
	std::list<Scalar>::const_iterator end) :
	_dimension{static_cast<size_t>(std::distance(begin, end))} {
	_vector = new Scalar[_dimension];
	std::copy(begin, end, _vector);
}

//construct a vector from a std::vector iterator
EuclideanVector::EuclideanVector(std::vector<Scalar>::const_iterator begin,
	std::vector<Scalar>::const_iterator end) :
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
	_vector{nullptr}, _dimension{0} {
	_vector = e._vector; //copy over pointer and dimension
	_dimension = e._dimension;
	e._vector = nullptr; //avoid multiple frees
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
		delete [] _vector; //delete existing resource
		_dimension = e._dimension;
		_vector = new Scalar[_dimension];
		std::copy(e._vector, e._vector + e._dimension, _vector);
	}
	return *this;
}

//move assignment operator
EuclideanVector& EuclideanVector::operator=(EuclideanVector&& e) noexcept {
	if (this != &e) {
		delete [] _vector; //delete existing resource
		_dimension = e._dimension; //copy over pointer and dimension
		_vector = e._vector;
		e._vector = nullptr; //avoid multiple frees
		e._dimension = 0;
	}
	return *this;
}

//return the number of dimensions
size_t EuclideanVector::getNumDimensions() const {
	return _dimension;
}

//return the magnitude in the given dimension
Scalar EuclideanVector::get(size_t pos) const {
	if (pos >= _dimension) throw std::out_of_range("Index too large");
	return _vector[pos];
}

//return the Euclidean norm of the vector
//retrieve from cache if possible
Scalar EuclideanVector::getEuclideanNorm() const {
	if (_changed == false) return _norm;
	Scalar norm = 0;

	//compute sqrt(v_1^2 + v_2^2 + ... + v_n^2)
	std::for_each(_vector, _vector + _dimension, [&norm](const Scalar& mag) {
		norm += pow(mag, 2);
	});
	_norm = sqrt(norm); //cache norm in mutable field

	_changed = false;
	return _norm;
}

//return the unit vector for the Euclidean vector
EuclideanVector EuclideanVector::createUnitVector() const {
	Scalar norm = getEuclideanNorm();
	EuclideanVector unit = *this;

	//divide all the magnitudes by the norm
	std::transform(unit._vector, unit._vector + unit._dimension,
	unit._vector, [&norm](const Scalar& mag) {
		return mag / norm;
	});

	return unit;
}

//set the magnitude in the given dimension
Scalar& EuclideanVector::operator[](size_t i) {
	if (i >= _dimension) throw std::out_of_range("Index too large"); //unnecessary
	_changed = true;
	return _vector[i];
}

//get the magnitude in the given dimension
Scalar EuclideanVector::operator[](size_t i) const {
	if (i >= _dimension) throw std::out_of_range("Index too large"); //unnecessary
	return _vector[i];
}

//transform the first vector by applying the given operator
EuclideanVector& applyWith(EuclideanVector& a, const EuclideanVector& b, auto op) {
	if (a.getNumDimensions() != b.getNumDimensions()) {
		throw std::invalid_argument("Vectors must have same dimension");
	}
	for (size_t i = 0; i < a.getNumDimensions(); ++i) {
		//update the magnitude in a[i] by applying op to a[i] and b[i]
		a[i] = op(a[i], b[i]);
	}
	return a;
}

//overloaded += operator for adding vectors of same dimension
EuclideanVector& EuclideanVector::operator+=(const EuclideanVector& rhs) {
	_changed = true;
	return applyWith(*this, rhs, std::plus<Scalar>());
}

//overloaded -= operator for subtracting vectors of same dimension
EuclideanVector& EuclideanVector::operator-=(const EuclideanVector& rhs) {
	_changed = true;
	return applyWith(*this, rhs, std::minus<Scalar>());
}

//transform the given vector by applying the given operator
EuclideanVector& applyWith(EuclideanVector& a, const Scalar& c, auto op) {
	for (size_t i = 0; i < a.getNumDimensions(); ++i) {
		//update the magnitude in a[i] by applying op to a[i] and c
		a[i] = op(a[i], c);
	}
	return a;
}

//overloaded /= operator for scalar multiplication
EuclideanVector& EuclideanVector::operator*=(const Scalar& rhs) {
	_changed = true;
	return applyWith(*this, rhs, std::multiplies<Scalar>());
}

//overloaded /= operator for scalar division
EuclideanVector& EuclideanVector::operator/=(const Scalar& rhs) {
	_changed = true;
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
	return std::equal(a._vector, a._vector + a._dimension,
	b._vector, b._vector + b._dimension);
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
	return std::inner_product(a._vector, a._vector + a._dimension, b._vector, 0.0);
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

//print the Euclidean vector in the form [v_1 v_2 v_3 ... v_n]
std::ostream& operator<<(std::ostream& os, const EuclideanVector& v) {
	std::cout << "[";

	//write first n-1 magnitudes sequentially, space-delimited
	std::ostream_iterator<Scalar> output(std::cout, " ");
	std::copy(v._vector, v._vector + v._dimension - 1, output);

	//then write the last magnitude (without a trailing space)
	if (v._dimension > 0) std::cout << v._vector[v._dimension - 1];

	std::cout << "]";
	return os;
}

}
