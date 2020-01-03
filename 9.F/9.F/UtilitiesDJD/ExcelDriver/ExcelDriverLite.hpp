// ExcelDriverLite.hpp
//
// Excel driver class. This class is for VISUALISATION only
//
// Using std::vector<double> for conveneience. The Matrix class is generic.
//
// (C) Datasim Education BV 2003 - 2017
//

#ifndef ExcelDriver_HPP
#define ExcelDriver_HPP

// !!!! PLEASE USE CORRECT VERSION OF OFFICE!!!!!!
#include "ExcelImports.cpp" // Contains all versions of Office
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"
#include "UtilitiesDJD/BitsAndPieces/StringConversions.hpp"

// STL list class.
#include <list>
#include <vector>
#include <string>

// Excel driver class definition. Contains functionality to add charts 
// and matrices. Hides all COM details. COM exceptions are re-thrown
// as STL strings.

//  Supprting functions to convert Vector <--> Matrix
template <typename Matrix, typename Vector>
		Vector CreateVector(const Matrix& mat, long row);

template <typename Matrix, typename Vector>
		Matrix CreateMatrix(const Vector& vec);

// This class is used to initialize/unitialize the COM runtime.
class COMInitializer
{
public:
	COMInitializer::COMInitializer() { 
		// Initialize COM Runtime Libraries.
		CoInitialize(NULL);
	}

	virtual COMInitializer::~COMInitializer() { 
		// Undo initialization of COM Runtime Libraries.
		CoUninitialize(); 
	}
};

// By deriving from COMInitializer, we ensure that CoInitialize is called before the xl varable is created
// and CoUninitialize is called after xl is destructed. This prevents a runtime error 
// (see https://www.quantnet.com/threads/support-for-office-15.13784/page-3#post-134681)
class ExcelDriver:COMInitializer
{
private:
	// Private member data.
	Excel::_ApplicationPtr xl;		// Pointer to Excel.

	long curDataColumn;

	// Writes label and std::vector<double> to cells in horizontal direction.
		void ToSheetHorizontal(Excel::_WorksheetPtr sheet,
								long sheetRow, long sheetColumn,
								const std::string& label,
								const std::vector<double>& values );

	// Writes label and std::vector<double> to cells in vertical direction.
		void ToSheetVertical(Excel::_WorksheetPtr sheet,
								long sheetRow, long sheetColumn,
								const std::string& label, 
								const std::vector<double> & values );


	// Throw COM error as string.
	void ThrowAsString( _com_error & error );
	
public:
	// Constructor. Starts Excel in invisible mode.
	ExcelDriver(long currentColumn = 1);
		
	// Destructor.
	virtual ~ExcelDriver();
	
	// Access to single, shared instance of ExcelDriver (Singleton pattern).
	static ExcelDriver& Instance();
	

	// Create chart with a number of functions. The arguments are:
	//  x:			std::vector<double> with input values
	//  labels:		labels for output values
	//  vectorList: list of vectors with output values.
	//  chartTitle:	title of chart
	//  xTitle:		label of x axis
	//  yTitle:		label of y axis
	void CreateChart(const std::vector<double> & x, const std::list<std::string> & labels, 
					const std::list<std::vector<double>> & vectorList,
					const std::string& chartTitle, 
					const std::string& xTitle = "X", 
					const std::string& yTitle = "Y");

	// Create chart with a number of functions. The arguments are:
	//  x:			std::vector<double> with input values
	//  y:			std::vector<double> with output values.
	//  chartTitle:	title of chart
	//  xTitle:		label of x axis
	//  yTitle:		label of y axis
	
	void CreateChart(const std::vector<double> & x, const std::vector<double>& y, 
					const std::string& chartTitle, 
					const std::string& xTitle = "X", 
					const std::string& yTitle = "Y");

	void MakeVisible( bool b);


	// Matrix visualisation
	template <typename Matrix>
			void AddMatrix(const Matrix& matrix, const std::string& name = std::string("Matrix"),
							long row = 1, long col = 1);
	
	template <typename Matrix>
			void AddMatrix(const Matrix& matrix, 
						const std::string& sheetName,
						const std::list<std::string>& rowLabels, 
						const std::list<std::string>& columnLabels,
						long row = 1, long col = 1);

	// Vector visualisation as numbers
	template <typename Matrix>
		void AddVector(const std::vector<double>& vec, 
						const std::string& sheetName = std::string("Vector"),
						long row = 1, long col = 1);

	template <typename Matrix>
		void AddVector(const std::vector<double>& vec, 
						const std::string& sheetName,
						const std::string& rowLabel, 
						const std::list<std::string>& columnLabels,
						long row = 1, long col = 1);

	// For debugging, for example; print string at a (row,col) position
	void printStringInExcel(const std::string& s,long row, long col);
	void printStringInExcel(const std::list<std::string>& s, long row, long col);
};

// Hard-coded strings
const string comma(", ");
const string bracketL("[");
const string bracketR("]");

void printOneExcel(const std::vector<double>& x,						
				   const std::vector<double>& functionResult,
				   const std::string& title = string("Title"), 
				   const std::string& horizontal = string("X"), 
				   const std::string& vertical = string("Y"),
				   const std::string& legend = string("Y")) 
{
		// N.B. Excel has a limit of 8 characters; after that you get a run-time error

	// PREC: Type I
	if (x.size() != functionResult.size())
	{
		
		string tmp = string("Sizes of vectors are X, Y: ") + getString(x.size()) + string(comma) + getString(functionResult.size());

		throw DatasimException(string("Size mismatch of two vectors"), string("PrintOneExcel"),
			tmp);
	}

	cout << "Starting Excel\n";

	ExcelDriver& excel = ExcelDriver::Instance();

	excel.MakeVisible(true);		// Default is INVISIBLE!

	// Workaround
	list<std::string> legendList; legendList.push_back(legend);
	list<std::vector<double> > functionResultList; functionResultList.push_back(functionResult);

	excel.CreateChart(x, legendList, functionResultList, title, horizontal, vertical);
}

#include "ExcelDriverLite.cpp"

#endif