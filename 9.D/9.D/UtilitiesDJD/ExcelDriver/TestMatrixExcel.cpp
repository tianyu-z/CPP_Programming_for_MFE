// TestMatrixExcel.cpp
//
// Test output of a matrix in Excel. Here we 
// use the Excel Driver object directly.
//
// The output is in cell/numeric format.
//
// (C) Datasim Education BV 2006-2017
//


#include "ExcelDriverlite.hpp"
#include "Utilities.hpp"

#include <boost/numeric/ublas/matrix.hpp>
#include "UtilitiesDJD/VectorsAndMatrices/NestedMatrix.hpp"

#include <string>
#include <vector>
#include <list>

double rho = 0.5;
double NormalPdf2d(double x, double y)
{ // Bivariate normal density function
	
	double fac = 1.0 / (2.0 * 3.14159265359 * std::sqrt(1.0 - rho*rho));
	double t = x*x - 2.0*rho*x*y + y*y;
	t /= 2.0 * (1.0 - rho*rho);

	return fac * std::exp(-t);
}

template <typename Matrix>
	Matrix DiscreteNormalPdf2d(const std::vector<double>& x, const std::vector<double>& y)
{
	return CreateDiscreteFunction2d<Matrix>(x, y, NormalPdf2d);
}

int main()
{
		//	using NumericMatrix = boost::numeric::ublas::matrix<double>;
		// C++11 syntax
		//using NumericMatrix = NestedMatrix<double>;
		// using Vector = std::vector<double>
		typedef NestedMatrix<double> NumericMatrix;
		typedef std::vector<double> Vector;

		std::size_t N = 10; std::size_t M = 6; // rows and columns
		NumericMatrix matrix(N + 1, M + 1);
		for (std::size_t i = 0; i < matrix.size1(); ++i)
		{
			for (std::size_t j = 0; j < matrix.size2(); ++j)
			{
				matrix(i, j) = static_cast<double>(i + j);
			}
		}
	
		// Start Excel
		ExcelDriver& excel = ExcelDriver::Instance();
		excel.MakeVisible(true);		// Default is INVISIBLE!

		// Call Excel print function
		std::string sheetName("Test Case 101 Matrix");
		long row = 4; long col = 2;
	//	excel.AddMatrix<NumericMatrix>(matrix, sheetName, row, col);
	

		std::string sheetName2("Matrix Labels Case");

	//	ExcelDriver& excel = ExcelDriver::Instance();
	//	excel.MakeVisible(true);		// Default is INVISIBLE!

		// Labels for rows and columns of the Excel matrix.
		// Only labelled values are printed!!
		std::list<std::string> rowLabels; // C++11: {"A","B","C","D","E", "F","K","L"};
		rowLabels.push_back("A");
		rowLabels.push_back("B");
		rowLabels.push_back("C");
		rowLabels.push_back("D");
		rowLabels.push_back("E");
		rowLabels.push_back("F");
		rowLabels.push_back("K");
		rowLabels.push_back("L");

		std::list<std::string> colLabels; // C++11: {"C1", "C2", "C3", "C4","C5"};
		colLabels.push_back("C1");
		colLabels.push_back("C2");
		colLabels.push_back("C3");
		colLabels.push_back("C4");
		colLabels.push_back("C5");

		long rowPos = 4; long colPos = 3;
	//	excel.AddMatrix<NumericMatrix>(matrix, sheetName2, rowLabels, colLabels, 
		//										rowPos, colPos);
		
		{
			// Using mapping continuous space to discrete space
			std::size_t N = 20; std::size_t M = 10;
			auto x = CreateMesh(N, -4.0, 4.0);
			auto y = CreateMesh(M, -4.0, 4.0);

			NumericMatrix matrix = DiscreteNormalPdf2d<NumericMatrix>(x, y);
		
		//	ExcelDriver& excel = ExcelDriver::Instance();
			std::string sheetName("Bivariate Normal pdf");
			long row = 1; long col = 1;
			excel.AddMatrix<NumericMatrix>(matrix, sheetName, row, col);
	}


	return 0;
}
