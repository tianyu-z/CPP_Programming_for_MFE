// Utilities.hpp
//
// Handy functions to help with numerical linear algebra.
//
// (C) Datasim Education BV 2017
//

#ifndef Utilities_HPP
#define Utilities_HPP

#include <vector>
#include <functional>
#include <iostream>
#include <boost/lexical_cast.hpp>

void print(const std::vector<double>& v)
{
	// In C++11, use a range-based for loop.
	for (std::vector<double>::const_iterator i = v.begin(); i < v.end(); ++i)
	{
		std::cout << *i << ",";
	}
	std::cout << '\n';
}

double LInfinityNorm(const std::vector<double>& v1, const std::vector<double>& v2)
{ // Max of absolute value of elements of v1 - v2

	double result = std::abs(v1[0] - v2[0]);

	for (std::size_t j = 1; j < v1.size(); ++j)
	{
		result = std::max<double>(result, std::abs(v1[j] - v2[j]));
	}

	return result;
}

std::pair<double, std::size_t> HotSpotError(const std::vector<double>& v1, const std::vector<double>& v2)
{ // Max of absolute value of elements of v1 - v2 and identify *where* it occurs

	double result = std::abs(v1[0] - v2[0]);
	std::size_t index = 0;

	for (std::size_t j = 1; j < v1.size(); ++j)
	{
		double tmp = std::max<double>(result, std::abs(v1[j] - v2[j]));

		if (result < tmp)
		{ // Find the max difference

			result = tmp;
			index = j;
		}
	}

	return std::pair<double,std::size_t>(result, index);
}

std::size_t findAbscissa(const std::vector<double>& x, double xvar) 
{ // Will give index of LHS value <= xvar. 
  
//	std::cout << xvar; int yy; std::cin >> yy;
	if (xvar < x[0] || xvar >  x[x.size() - 1])
	{
		std::string s = "\nValue " + boost::lexical_cast<std::string>(xvar) + " not in range "
			+ "(" + boost::lexical_cast<std::string>(x[0]) + ","
			+ boost::lexical_cast<std::string>(x[x.size() - 1]) + ")";
		throw std::out_of_range(s);
	}

	auto posA = std::lower_bound(std::begin(x), std::end(x), xvar); // Log complexity
												
	std::size_t index = std::distance(std::begin(x), posA);

	return index;
}

std::vector<double> CreateMesh(std::size_t n, double a, double b)
{ // Create a mesh of size n+1 on closed interval [a,b]

	std::vector<double> x(n + 1);
	x[0] = a; x[x.size()-1] = b;
	
	double h = (b - a) / static_cast<double>(n);
	for (std::size_t j = 1; j < x.size() - 1; ++j)
	{
		x[j] = x[j - 1] + h;
	}

	return x;
}

/*
std::vector<double> CreateDiscreteFunction(std::size_t n, double a, double b, 
											const std::function<double (double)>& f)
{ // Create a discrete function from a continuous function y = f(x)

	std::vector<double> y(n + 1);

	double h = (b - a) / static_cast<double>(n);
	double x = a;
	for (std::size_t j = 0; j < y.size(); ++j)
	{
		y[j] = f(x);
		x += h;
	}

	return y;
}
*/
template <typename Vector>
	Vector CreateDiscreteFunction(const std::vector<double>& x, const std::function<double(double)>& f)
{ // Create a discrete function from a continuous function y = f(x)

	Vector y(x.size());
	
	for (std::size_t j = 0; j < y.size(); ++j)
	{
		y[j] = f(x[j]);
	}

	return y;
}

template <typename Matrix>
	Matrix CreateDiscreteFunction2d(const std::vector<double>& x , const std::vector<double>& y,
									const std::function<double (double x, double y)>& f)
{ // Create a discrete function from a continuous function m = f(x,y)

	std::size_t nr = x.size();
	std::size_t nc = y.size();

	Matrix m(nr,nc);

	for (std::size_t i = 0; i < nr; ++i)
	{
		for (std::size_t j = 0; j < nc; ++j)
		{
			m(i, j) = f(x[i],y[j]);
		}
	}

	return m;
}

#endif
