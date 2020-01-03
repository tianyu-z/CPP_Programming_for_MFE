// TestVectorExcel.cpp
//
// Test output of a vector in Excel. Here we 
// use the Excel Driver object directly.
//
// The output is in cell/numeric format.
//
// (C) Datasim Education BV 2006-2017
//


#include "ExcelDriverlite.hpp"
#include "Utilities.hpp"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

#include <string>
#include <vector>
#include <list>

double rho = 0.5;
double NormalPdf1d(double x)
{ // Univariate normal density function
	
	double fac = 1.0 / std::sqrt(2.0 * 3.14159265359);
	return fac * std::exp(-x*x/2);
}

template <typename Vector>
	Vector DiscreteNormalPdf1d(const std::vector<double>& x)
{
	return CreateDiscreteFunction< std::vector<double>>(x, NormalPdf1d);
}

int main()
{

	// C++11 syntax
	//using NumericMatrix = boost::numeric::ublas::matrix<double>;
	// using Vector = std::vector<double>
	typedef boost::numeric::ublas::matrix<double> NumericMatrix;
	typedef std::vector<double> Vector;
	//	auto xarr = CreateMesh(N + 1, 0.0, 10.0);
	
	std::string sheetName("Vector Case");

	ExcelDriver& excel = ExcelDriver::Instance();
	excel.MakeVisible(true);		// Default is VISIBLE!

	// Labels for columns of the Excel vector.
	// Only labelled values are printed!!
	
	std::string rowLabel("row1");
	std::list<std::string> colLabels; // C++11: {"C1", "C2", "C3", "C4","C5"};
	colLabels.push_back("C1");
	colLabels.push_back("C2");
	colLabels.push_back("C3");
	colLabels.push_back("C4");
	colLabels.push_back("C5");

	Vector myVector(colLabels.size());
	for (std::size_t i = 0; i < myVector.size(); ++i)
	{

		myVector[i] = static_cast<double>(i);
	}

	try
	{
		long row = 4; long col = 3;
		excel.AddVector<NumericMatrix>(myVector, sheetName, rowLabel, colLabels, row, col);
	}
	catch(std::out_of_range& e)
	{
		std::cout << e.what() << '\n';
	}
	catch (...)
	{
		// Catches everything else
		std::cout << "oop";
	}


	{
		// Using mapping continuous space to discrete space
		std::size_t N = 10;
		auto x = CreateMesh(N, -4.0, 4.0);

		std::vector<double> vec = DiscreteNormalPdf1d<std::vector<double>>(x);

		try
		{

			ExcelDriver& excel = ExcelDriver::Instance();
			std::string sheetName("Bivariate Normal pdf");
			long row = 3; long col = 2;
			//excel.AddVector<NumericMatrix>(vec, sheetName, row, col);
		}
		catch (std::out_of_range& e)
		{
			std::cout << e.what() << '\n';
		}
		catch (...)
		{
			// Catches everything else
			std::cout << "oop";
		}
	}


	return 0;
}
