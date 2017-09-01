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
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}

	//default constructor - no magnitude
	{
		evec::EuclideanVector a(1);
		unsigned int i{3};
		evec::EuclideanVector b(i);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}

	//constructor with # dimensions & magnitude
	{
		evec::EuclideanVector a(2, 4.0);
		unsigned int x{3};
		double y{3.24};
		evec::EuclideanVector b(x, y);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}

	//constructor using iterator
	{
		std::list<double> l{1, 3, 5, 7.5};
		evec::EuclideanVector a{l.begin(), l.end()};
		std::vector<double> v{2, 4.2, 6};
		evec::EuclideanVector b{v.begin(), v.end()};
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}

	//constructor using initializer list
	{
		evec::EuclideanVector a{1};
		evec::EuclideanVector b{1, 2};
		evec::EuclideanVector c{2, 6.4, -77.9};
		evec::EuclideanVector d{1, 2, 3.2, 4};
		evec::EuclideanVector e{3.3, 2, -5.3, 76, 5};
		evec::EuclideanVector f{9, 2.2, 3, 7.4, 33, 15};
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		std::cout << e << std::endl;
		std::cout << f << std::endl;
	}

	//copy and move constructors
	{
		evec::EuclideanVector a{3.2, -7.8, 5.5};
		evec::EuclideanVector b{1, 4, 9.9, 4, -62.8, 3};
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		evec::EuclideanVector copy_a(a);
		evec::EuclideanVector copy_b(b);
		std::cout << copy_a << std::endl;
		std::cout << copy_b << std::endl;
		evec::EuclideanVector move_a(a);
		evec::EuclideanVector move_b(b);
		std::cout << move_a << std::endl;
		std::cout << move_b << std::endl;
	}

	//copy and move assignment operators
	{
		//TODO
		/*
		evec::EuclideanVector a{72, 34, 5, -7};
		std::cout << a << std::endl;
		evec::EuclideanVector b{a};
		std::cout << b << std::endl;
		evec::EuclideanVector c{std::move(a)};
		std::cout << c << std::endl;
		*/
	}

	//getters
	{
		evec::EuclideanVector a{13};
		std::cout << "dim " << a << " = " << a.getNumDimensions() << "\n";
		evec::EuclideanVector b{13, 44};
		std::cout << "dim " << b << " = " << b.getNumDimensions() << "\n";
		evec::EuclideanVector c{13, 44, -78};
		std::cout << "dim " << c << " = " << c.getNumDimensions() << "\n";
		evec::EuclideanVector d{13, 44, -78, 3.3};
		std::cout << "dim " << d << " = " << d.getNumDimensions() << "\n";

		std::cout << a.get(0) << "\n";
		std::cout << b.get(0) << " " << b.get(1) << "\n";
		std::cout << c.get(0) << " " << c.get(1) << " " << c.get(2) << "\n";

		for (int i = 0; i < 4; ++i) std::cout << d.get(i) << " ";
		std::cout << "\n";
		try {
			d.get(5);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << "norm " << a << " = " << a.getEuclideanNorm() << "\n";
		std::cout << "norm " << b << " = " << b.getEuclideanNorm() << "\n";
		std::cout << "norm " << c << " = " << c.getEuclideanNorm() << "\n";
		std::cout << "norm " << d << " = " << d.getEuclideanNorm() << "\n";
		evec::EuclideanVector e{1, 2, 3};
		std::cout << "norm " << e << " = " << e.getEuclideanNorm() << "\n";

		std::cout << "norm " << a.createUnitVector() << " = " << a.createUnitVector().getEuclideanNorm() << "\n";
		std::cout << "norm " << b.createUnitVector() << " = " << b.createUnitVector().getEuclideanNorm() << "\n";
		std::cout << "norm " << c.createUnitVector() << " = " << c.createUnitVector().getEuclideanNorm() << "\n";
		std::cout << "norm " << d.createUnitVector() << " = " << d.createUnitVector().getEuclideanNorm() << "\n";
		std::cout << "norm " << e.createUnitVector() << " = " << e.createUnitVector().getEuclideanNorm() << "\n";
	}

	//operators
	{
		//subscript operator []
		evec::EuclideanVector a{16, -56, 3.7};
		std::cout << a << "\n";
		std::cout << a[0] << " " << a[1] << " " << a[2] << "\n";
		a[0] = 44;
		std::cout << a[0] << " " << a[1] << " " << a[2] << "\n";
		a[1] = 16;
		std::cout << a[0] << " " << a[1] << " " << a[2] << "\n";
		a[2] = 99;
		std::cout << a[0] << " " << a[1] << " " << a[2] << "\n";
		try {
			std::cout << a[3];
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			a[-3] = 5;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		//the += and -= operators
		evec::EuclideanVector b{-73, 23, -4.1};
		std::cout << a << " += " << b << " = ";
		a += b;
		std::cout << a << "\n";
		std::cout << a << " -= " << b << " = ";
		a -= b;
		std::cout << a << "\n";
		evec::EuclideanVector c{12, 60, 55, 48};
		try {
			c += a;
		} catch (std::exception& e) {
			std::cout << e.what() << "\n";
		}
		try {
			b += c;
		} catch (std::exception& e) {
			std::cout << e.what() << "\n";
		}

		//the */ and /= operators
		std::cout << a << " * 2 = ";
		a *= 2;
		std::cout << a << "\n";
		std::cout << b << " * 0 = ";
		b *= 0;
		std::cout << b << "\n";
		std::cout << c << " * -1 = ";
		c *= -1;
		std::cout << c << "\n";
		std::cout << a << " / 2 = ";
		a /= 2;
		std::cout << a << "\n";
		std::cout << b << " / 0 = ";
		b /= 0;
		std::cout << b << "\n";
		std::cout << c << " / -1 = ";
		c /= -1;
		std::cout << c << "\n";
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
