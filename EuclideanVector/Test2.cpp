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
		evec::EuclideanVector a{72, 34, 5, -7};
		std::cout << a << std::endl;
		evec::EuclideanVector b{a};
		std::cout << b << std::endl;
		evec::EuclideanVector c{std::move(a)};
		std::cout << c << std::endl;
	}

	//getters
	{
		//getNumDimensions
		evec::EuclideanVector a{13};
		std::cout << "dim " << a << " = " << a.getNumDimensions() << "\n";
		evec::EuclideanVector b{13, 44};
		std::cout << "dim " << b << " = " << b.getNumDimensions() << "\n";
		evec::EuclideanVector c{13, 44, -78};
		std::cout << "dim " << c << " = " << c.getNumDimensions() << "\n";
		evec::EuclideanVector d{13, 44, -78, 3.3};
		std::cout << "dim " << d << " = " << d.getNumDimensions() << "\n";

		//get (at an index)
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

		//getEuclideanNorm
		std::cout << "norm " << a << " = " << a.getEuclideanNorm() << "\n";
		std::cout << "norm " << b << " = " << b.getEuclideanNorm() << "\n";
		std::cout << "norm " << c << " = " << c.getEuclideanNorm() << "\n";
		std::cout << "norm " << d << " = " << d.getEuclideanNorm() << "\n";
		evec::EuclideanVector e{1, 2, 3};
		std::cout << "norm " << e << " = " << e.getEuclideanNorm() << "\n";

		//createUnitVector
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
		std::cout << a << "\n";
		try {
			std::cout << a[3];
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			a[7] = -3;
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
			b -= c;
		} catch (std::exception& e) {
			std::cout << e.what() << "\n";
		}

		//the *= and /= operators
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

	//type casting
	{
		evec::EuclideanVector a{14, -32, 6.7};
		std::cout << a << "\n";
		std::vector<double> vec = a;
		for (auto v: vec) std::cout << v << " ";
		std::cout << std::endl;
		std::list<double> lst = a;
		for (auto l: lst) std::cout << l << " ";
		std::cout << std::endl;
	}

	//nonmember functions
	{
		evec::EuclideanVector a{};
		evec::EuclideanVector b{1, 2};
		evec::EuclideanVector c{1, 2, 3};
		evec::EuclideanVector d{1, 2};
		evec::EuclideanVector e = c;

		//equality
		std::cout << a << " == " << b << " = " << (a == b) << std::endl;
		std::cout << a << " == " << c << " = " << (a == c) << std::endl;
		std::cout << a << " == " << d << " = " << (a == d) << std::endl;
		std::cout << a << " == " << e << " = " << (a == e) << std::endl;
		std::cout << b << " == " << c << " = " << (b == c) << std::endl;
		std::cout << b << " == " << d << " = " << (b == d) << std::endl;
		std::cout << b << " == " << e << " = " << (b == e) << std::endl;
		std::cout << c << " == " << d << " = " << (c == d) << std::endl;
		std::cout << c << " == " << e << " = " << (c == e) << std::endl;
		std::cout << d << " == " << e << " = " << (d == e) << std::endl;

		std::cout << a << " != " << b << " = " << (a != b) << std::endl;
		std::cout << a << " != " << c << " = " << (a != c) << std::endl;
		std::cout << a << " != " << d << " = " << (a != d) << std::endl;
		std::cout << a << " != " << e << " = " << (a != e) << std::endl;
		std::cout << b << " != " << c << " = " << (b != c) << std::endl;
		std::cout << b << " != " << d << " = " << (b != d) << std::endl;
		std::cout << b << " != " << e << " = " << (b != e) << std::endl;
		std::cout << c << " != " << d << " = " << (c != d) << std::endl;
		std::cout << c << " != " << e << " = " << (c != e) << std::endl;
		std::cout << d << " != " << e << " = " << (d != e) << std::endl;

		//addition of vectors
		evec::EuclideanVector add1 = b + d;
		std::cout << b << " + " << d << " = " << add1 << std::endl;
		evec::EuclideanVector add2 = d + b;
		std::cout << d << " + " << b << " = " << add2 << std::endl;
		evec::EuclideanVector add3 = e + c;
		std::cout << e << " + " << c << " = " << add3 << std::endl;
		evec::EuclideanVector add4 = c + e;
		std::cout << c << " + " << e << " = " << add4 << std::endl;
		try {
			evec::EuclideanVector add5 = b + c;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		//subtraction of vectors
		evec::EuclideanVector sub1 = b - d;
		std::cout << b << " - " << d << " = " << sub1 << std::endl;
		evec::EuclideanVector sub2 = d - b;
		std::cout << d << " - " << b << " = " << sub2 << std::endl;
		evec::EuclideanVector sub3 = e - c;
		std::cout << e << " - " << c << " = " << sub3 << std::endl;
		evec::EuclideanVector sub4 = c - e;
		std::cout << c << " - " << e << " = " << sub4 << std::endl;
		try {
			evec::EuclideanVector sub5 = b - c;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		//dot product of vectors
		{
			double dot1 = b * d;
			std::cout << b << " * " << d << " = " << dot1 << std::endl;
			double dot2 = d * b;
			std::cout << d << " * " << b << " = " << dot2 << std::endl;
			double dot3 = e * c;
			std::cout << e << " * " << c << " = " << dot3 << std::endl;
			double dot4 = c * e;
			std::cout << c << " * " << e << " = " << dot4 << std::endl;
			try {
				dot4 = b * c;
			} catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		}

		//scalar multiplication (with scalar on right)
		{
			evec::EuclideanVector scalarX1 = b * 2;
			std::cout << b << " * 2" << " = " << scalarX1 << std::endl;
			evec::EuclideanVector scalarX2 = b * 0;
			std::cout << b << " * 0" << " = " << scalarX2 << std::endl;
			evec::EuclideanVector scalarX3 = c * -1;
			std::cout << c << " * -1" << " = " << scalarX3 << std::endl;
			evec::EuclideanVector scalarX4 = c * 5;
			std::cout << c << " * 5" << " = " << scalarX4 << std::endl;
		}

		//scalar multiplication (with scalar on left)
		{
			evec::EuclideanVector scalarX1 = 2 * b;
			std::cout << "2 * " << b << " = " << scalarX1 << std::endl;
			evec::EuclideanVector scalarX2 = 0 * b;
			std::cout << "0 * " << b << " = " << scalarX2 << std::endl;
			evec::EuclideanVector scalarX3 = -1 * c;
			std::cout << "-1 * " << c << " = " << scalarX3 << std::endl;
			evec::EuclideanVector scalarX4 = 5 * c;
			std::cout << "5 * " << c << " = " << scalarX4 << std::endl;
		}

		//scalar division
		{
			evec::EuclideanVector scalarD1 = b / 2;
			std::cout << b << " / 2" << " = " << scalarD1 << std::endl;
			evec::EuclideanVector scalarD2 = b / 0;
			std::cout << b << " / 0" << " = " << scalarD2 << std::endl;
			evec::EuclideanVector scalarD3 = c / -1;
			std::cout << c << " / -1" << " = " << scalarD3 << std::endl;
			evec::EuclideanVector scalarD4 = c / 5;
			std::cout << c << " / 5" << " = " << scalarD4 << std::endl;
		}

	}

}
