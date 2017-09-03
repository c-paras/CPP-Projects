/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Interface for the EuclideanVector class library.
 */

#include <list>
#include <vector>
#include <ostream>
#include <initializer_list>

#ifndef EUCLIDEAN_VECTOR_H
#define EUCLIDEAN_VECTOR_H

namespace evec {

using Scalar = double;

class EuclideanVector {
public:
	//constructors
	EuclideanVector();
	EuclideanVector(size_t dim);
	EuclideanVector(size_t dim, Scalar mag);
	EuclideanVector(std::list<Scalar>::const_iterator begin,
		std::list<Scalar>::const_iterator end);
	EuclideanVector(std::vector<Scalar>::const_iterator begin,
		std::vector<Scalar>::const_iterator end);
	EuclideanVector(std::initializer_list<Scalar> lst);
	EuclideanVector(const EuclideanVector& e);
	EuclideanVector(EuclideanVector&& e) noexcept;

	//destructor
	~EuclideanVector();

	//copy assignment and move assignment
	EuclideanVector& operator=(const EuclideanVector& e);
	EuclideanVector& operator=(EuclideanVector&& e) noexcept;

	//getters
	size_t getNumDimensions() const;
	Scalar get(size_t pos) const;
	Scalar getEuclideanNorm() const;
	EuclideanVector createUnitVector() const;

	//operators
	Scalar& operator[](size_t i);
	Scalar operator[](size_t i) const;
	EuclideanVector& operator+=(const EuclideanVector& rhs);
	EuclideanVector& operator-=(const EuclideanVector& rhs);
	EuclideanVector& operator*=(const Scalar& rhs);
	EuclideanVector& operator/=(const Scalar& rhs);
	operator std::vector<Scalar>() const;
	operator std::list<Scalar>() const;

	//friend functions
	friend std::ostream& operator<<(std::ostream& os, const EuclideanVector& v);
	friend bool operator==(const EuclideanVector& a, const EuclideanVector& b);
	friend Scalar operator*(const EuclideanVector& a, const EuclideanVector& b);
private:
	Scalar* _vector; //the magnitudes in each dimension
	size_t _dimension; //the dimension of the vector
	mutable Scalar _norm; //the Euclidean norm of the vector
	mutable bool _changed{true}; //true if _vector has changed; true initially
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
