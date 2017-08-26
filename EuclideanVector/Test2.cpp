/*
 * Copyright (C) 2017 Costa Paraskevopoulos.
 * Test case 2 for EuclideanVector class library.
 */

#include <iostream>
#include <vector>
#include <list>
#include "EuclideanVector.h"

int main() {

	//default constructor - no # dimensions & no magnitude
	{
		evec::EuclideanVector a;
		evec::EuclideanVector b{};
	}

	//default constructor - no magnitude
	{
		evec::EuclideanVector e1(1);
		unsigned int i{3};
		evec::EuclideanVector e2(i);
	}

	//constructor with # dimensions & magnitude
	{
		evec::EuclideanVector a(2, 4.0);
		unsigned int x{3};
		double y{3.24};
		evec::EuclideanVector b(x, y);
	}

	//constructor using iterator
	{
		std::list<double> l{1, 3, 5, 7.5};
		evec::EuclideanVector a{l.begin(), l.end()};
		std::vector<double> v{2, 4.2, 6};
		evec::EuclideanVector b2{v.begin(), v.end()};
	}

	//constructor using initializer list
	{
		evec::EuclideanVector a{1};
		evec::EuclideanVector b{1, 2};
		evec::EuclideanVector c{2, 6.4, -77.9};
		evec::EuclideanVector d{1, 2, 3.2, 4};
		evec::EuclideanVector e{3.3, 2, -5.3, 76, 5};
		evec::EuclideanVector f{9, 2.2, 3, 7.4, 33, 15};
	}

	//copy and move constructors
	{
		evec::EuclideanVector a{3.2, -7.8, 5.5};
		evec::EuclideanVector b{1, 4, 9.9, 4, -62.8, 3};
		evec::EuclideanVector copy_a(a);
		evec::EuclideanVector copy_b(b);
		evec::EuclideanVector move_a(a);
		evec::EuclideanVector move_b(b);
	}

/*
	std::list<double> l {1,2,3};
	evec::EuclideanVector b{l.begin(),l.end()};

	std::vector<double> v2 {4,5,6,7};
	evec::EuclideanVector c{v2.begin(),v2.end()};

	std::vector<double> a1 {5,4,3,2,1};
	evec::EuclideanVector d{a1.begin(),a1.end()};

	std::list<double> a2 {9,0,8,6,7};
	evec::EuclideanVector e{a2.begin(),a2.end()};

	//use the copy constructor
	evec::EuclideanVector f{e};
	std::cout << a.getNumDimensions() << ": " << a << std::endl;
	std::cout << "D1:" << b.get(1) << " " << b << std::endl;
	std::cout << c << " Euclidean Norm = " << c.getEuclideanNorm() << std::endl;
	std::cout << d << " Unit Vector: " << d.createUnitVector() << " L = " << d.createUnitVector().getEuclideanNorm() << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;

	//test the move constructor
	evec::EuclideanVector g = std::move(f);
	std::cout << g << std::endl;
	std::cout << f << std::endl;

	//try operator overloading
	e += d;
	std::cout << e << std::endl;

	evec::EuclideanVector h = e - g;
	std::cout << h << std::endl;

	//test scalar multiplication
	h *= 2;
	std::cout << h << std::endl;

	evec::EuclideanVector j = b / 2;
	std::cout << j << std::endl;

	std::cout << "dot product = " << j * b << std::endl;

	if (g == (e - d)) std::cout << "true" << std::endl;
	if (j != b ) std::cout << "false" << std::endl;

	j[0] = 1;
	std::cout << j << std::endl;

	//type cast from EuclideanVector to a std::vector
	std::vector<double> vj = j;

	//type cast from EuclideanVector to a std::vector
	std::list<double> lj = j;
	for (auto d: lj) {
		std::cout << d << std::endl;
	}

	//list initialisation
	evec::EuclideanVector k {1, 2, 3};
	std::cout << k << std::endl;
*/
}
