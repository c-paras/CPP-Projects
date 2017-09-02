/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Interface for the EuclideanVector class library.
 */

#include <list>
#include <vector>
#include <iterator>

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
	EuclideanVector(std::list<Scalar>::iterator begin, std::list<Scalar>::iterator end);
	EuclideanVector(std::vector<Scalar>::iterator begin, std::vector<Scalar>::iterator end);
	EuclideanVector(std::initializer_list<Scalar> lst);
	EuclideanVector(const EuclideanVector& e);
	EuclideanVector(EuclideanVector&& e);

	//destructor
	~EuclideanVector();

	//copy assignment and move assignment
	EuclideanVector& operator=(const EuclideanVector& e);
	EuclideanVector& operator=(EuclideanVector&& e);

	//getters
	size_t getNumDimensions() const;
	Scalar get(size_t pos);
	Scalar getEuclideanNorm();
	EuclideanVector createUnitVector();

	//operators
	Scalar& operator[](int i);
	Scalar operator[](int i) const;
	EuclideanVector& operator+=(const EuclideanVector& rhs);
	EuclideanVector& operator-=(const EuclideanVector& rhs);
	EuclideanVector& operator*=(const Scalar& rhs);
	EuclideanVector& operator/=(const Scalar& rhs);
	operator std::vector<Scalar>() const;
	operator std::list<Scalar>() const;

	//friend functions
	friend std::ostream& operator<<(std::ostream &os, const EuclideanVector &v);
	friend bool operator==(const EuclideanVector& a, const EuclideanVector& b);
	friend Scalar operator*(const EuclideanVector& a, const EuclideanVector& b);

private:
	Scalar* _vector;
	size_t _dimension;
};

	//non-member functions
	bool operator!=(const EuclideanVector& a, const EuclideanVector& b);
	EuclideanVector operator+(const EuclideanVector& a, const EuclideanVector& b);
	EuclideanVector operator-(const EuclideanVector& a, const EuclideanVector& b);
	EuclideanVector operator*(const EuclideanVector& a, const Scalar& b);
	EuclideanVector operator*(const Scalar& a, const EuclideanVector& b);
	EuclideanVector operator/(const EuclideanVector& a, const Scalar& b);
}

#endif
