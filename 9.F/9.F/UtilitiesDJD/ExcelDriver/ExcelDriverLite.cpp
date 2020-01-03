// ExcelDriverLite.cpp
//
// Excel driver class.
//
// Datasim Education BV (c) 2003
// 
// Modification dates:
// 23 July 2003 - MB - Started.
// ...
// 2017-3-5 DD code C++11 update.
//
//
// (C) Datasim Education BV 2003 - 2017
//

#ifndef ExcelDriver_CPP
#define ExcelDriver_CPP

#include "ExcelDriverLite.hpp"

#include <stdexcept>
#include <boost/lexical_cast.hpp>

template <typename Matrix, typename Vector>
	Vector CreateVector(const Matrix& mat, long row)
{

	Vector result(mat.size2());
	for (std::size_t i = 0; i < result.size(); ++i)
	{
		result[i] = mat(row, i);
	}

	return result;
}

template <typename Matrix, typename Vector>
	Matrix CreateMatrix(const Vector& vec)
{
		Matrix result(1, vec.size());
		for (std::size_t j = 0; j < result.size2(); ++j)
		{
			result(0,j) = vec[j];
		}
		return result;
}


// Writes label and vector to cells in horizontal direction.

void ExcelDriver::ToSheetHorizontal( Excel::_WorksheetPtr sheet, 
									long sheetRow, long sheetColumn,
									const std::string& label, const std::vector<double>& values )
{
		// Get cells.
		Excel::RangePtr pRange=sheet->Cells;
	
		// First cell contains the label.
		Excel::RangePtr item = pRange->Item[sheetRow][sheetColumn];
	//	item->Value = label.c_str();
		item->Value2 = label.c_str();
	
		sheetColumn++;

		// Next cells contain the values.
		for(std::size_t i= 0; i < values.size(); i++)
		{
			Excel::RangePtr item = pRange->Item[sheetRow][sheetColumn];
//			item->Value = values[i];			
			item->Value2 = values[i];			
	
			sheetColumn++;
		}
		
}


// Writes label and vector to cells in vertical direction.

void ExcelDriver::ToSheetVertical( Excel::_WorksheetPtr sheet,
														long sheetRow, long sheetColumn,
														const std::string& label, const std::vector<double>& values )
{
		// Get cells.
		Excel::RangePtr pRange=sheet->Cells;
	
		// First cell contains the label.
		Excel::RangePtr item = pRange->Item[sheetRow][sheetColumn];
		// item->Value = label.c_str();
		item->Value2 = label.c_str();
	
		sheetRow++;

		// Next cells contain the values.
		for(std::size_t i=0; i < values.size(); i++)
		{
			Excel::RangePtr item = pRange->Item[sheetRow][sheetColumn];
			//item->Value = values[i];			
			item->Value2 = values[i];
			sheetRow++;
		}
}

// Throw COM error as string.

void ExcelDriver::ThrowAsString( _com_error & error )
{
		bstr_t description = error.Description();
		if( !description )
		{
			description = error.ErrorMessage();
		}

		throw std::string(description);
}

// Constructor. Starts Excel in invisible mode.

ExcelDriver::ExcelDriver(long currentColumn) : COMInitializer(), curDataColumn (currentColumn)
{
		try
		{
			// Start excel application.
			xl.CreateInstance(L"Excel.Application");
			xl->Workbooks->Add((long) Excel::xlWorksheet);

			// Rename "Sheet1" to "Chart Data".
			Excel::_WorkbookPtr pWorkbook = xl->ActiveWorkbook;

			// Can also GetItem by sheet name, but this may not work on non-English versions of Excel.
			// Excel::_WorksheetPtr sheet = workbook->Worksheets->GetItem("Sheet1"); //Language-dependent
			Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->GetItem(1);
			pSheet->Name = "Chart Data";
		}
		catch( _com_error & error )
		{
			ThrowAsString(error);
		}
}

// Destructor.

ExcelDriver::~ExcelDriver()
{
}

// Access to single, shared instance of ExcelDriver (singleton).

ExcelDriver& ExcelDriver::Instance()
{
		static ExcelDriver singleton;
		return singleton;
}

// Create chart with a number of functions. The arguments are:
//  x:			vector with input values
//  labels:		labels for output values
//  vectorList: list of vectors with output values.
//  chartTitle:	title of chart
//  xTitle:		label of x axis
//  yTitle:		label of y axis
void ExcelDriver::CreateChart(const std::vector<double>& x, const std::list<std::string> & labels, 
											const std::list<std::vector<double>> & vectorList, 
											const std::string& chartTitle, const std::string& xTitle, 
											const std::string& yTitle)
{
		try
		{
	
			// Activate sheet with numbers.
			Excel::_WorkbookPtr pWorkbook = xl->ActiveWorkbook;
			Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->GetItem("Chart Data");
			
			// Calculate range with source data.
			// The first row contains the labels shown in the chart's legend.
			long beginRow = 1;
			long beginColumn = curDataColumn;
			long endRow = x.size() + 1;								// +1 to include labels.
			long endColumn = beginColumn + vectorList.size();		// 1st is input, rest is output.

			// Write label + input values to cells in vertical direction.
			ToSheetVertical(pSheet, 1, curDataColumn, xTitle, x);		// X values.
			curDataColumn++;

			// Write label + output values to cells in vertical direction.
			std::list<std::string>::const_iterator labelIt = labels.begin();
			for( auto vectorIt = vectorList.begin(); vectorIt != vectorList.end(); vectorIt++ )
			{
				// Get label and row index.
				std::string label = *labelIt;
				
				// Add label + output values to Excel.
				ToSheetVertical(pSheet, 1, curDataColumn, label, *vectorIt);

				// Advance row and label.
				curDataColumn++; labelIt++;
		}			
			
			// Create range objects for source data.
			Excel::RangePtr pBeginRange = pSheet->Cells->Item[beginRow][beginColumn];
			Excel::RangePtr pEndRange = pSheet->Cells->Item[endRow][endColumn];
			Excel::RangePtr pTotalRange = pSheet->Range[(Excel::Range*)pBeginRange][(Excel::Range*)pEndRange];
			
			// Create the chart and sets its type
			Excel::_ChartPtr pChart=xl->ActiveWorkbook->Charts->Add();
			pChart->ChartWizard((Excel::Range*)pTotalRange, (long)Excel::xlXYScatter, 6L, (long)Excel::xlColumns, 1L, 1L, true, chartTitle.c_str(), xTitle.c_str(), yTitle.c_str());
			pChart->ApplyCustomType(Excel::xlXYScatterSmooth);
			pChart->Name = chartTitle.c_str();

			// Make all titles visible again. They were erased by the ApplyCustomType method.
			pChart->HasTitle=true;
			pChart->ChartTitle->Text=chartTitle.c_str();

			Excel::AxisPtr pAxis = pChart->Axes((long)Excel::xlValue, Excel::xlPrimary);
			pAxis->HasTitle = true;
			pAxis->AxisTitle->Text = yTitle.c_str();
			
			pAxis=pChart->Axes((long)Excel::xlCategory, Excel::xlPrimary);
			pAxis->HasTitle = true;
			pAxis->AxisTitle->Text = xTitle.c_str();

			// Add extra row space to make sheet more readable.
			curDataColumn++;
		}
		catch( _com_error & error )
		{
			ThrowAsString(error);
		}
}

    // Create chart with a number of functions. The arguments are:
	//  x:			vector with input values
	//  y:			vector with output values.
	//  chartTitle:	title of chart
	//  xTitle:		label of x axis
	//  yTitle:		label of y axis
	
void ExcelDriver::CreateChart(const std::vector<double>& x, const std::vector<double>& y, const std::string& chartTitle, 
							  const std::string& xTitle, const std::string& yTitle)
{ 
		// Create list with single function and single label.
		// Can use initializer list syntax is C++11, but we want this to be backwards-compatible.
		std::list<std::vector<double>> functions;
		functions.push_back(y);
		std::list<std::string> labels;
		labels.push_back(chartTitle);

		CreateChart(x, labels, functions, chartTitle, xTitle, yTitle);
}


// Make Excel window visible.

void ExcelDriver::MakeVisible( bool b)
{
		// Make excel visible.
		xl->Visible = b ? VARIANT_TRUE : VARIANT_FALSE;
}


	
template <typename Matrix>
	void ExcelDriver::AddMatrix(const Matrix& matrix, const std::string& sheetName,
												const std::list<std::string>& rowLabels, 
												const std::list<std::string>& columnLabels,
												long row, long col)
{
	// Add sheet.
	Excel::_WorkbookPtr pWorkbook = xl->ActiveWorkbook;
	Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->Add();
	pSheet->Name = sheetName.c_str();

	// Add column labels starting at column col.
	Excel::RangePtr pRange = pSheet->Cells;

	long col2 = col+1;
	for (auto columnLabelIt = columnLabels.begin(); columnLabelIt != columnLabels.end(); columnLabelIt++)
	{
		//Excel::RangePtr item = pRange->Item[row][col];
		pRange->Item[row][col2] = columnLabelIt->c_str();
		//	item->Value = columnLabelIt->c_str();
	//	item->Value2 = (*columnLabelIt).c_str();

		col2++;
	}

	// Add row labels + values.
	row++;
	std::list<std::string>::const_iterator rowLabelIt = rowLabels.begin();
	for (unsigned long r = 0; r < matrix.size1(); ++r)
	{
		std::vector<double>	rowArray = CreateVector<Matrix, std::vector<double>>(matrix, r);
		ToSheetHorizontal(pSheet, row, col, *rowLabelIt, rowArray);
		rowLabelIt++;
		row++;
	}

}
	

		
template <typename Matrix>
	void ExcelDriver::AddMatrix(const Matrix& matrix, const std::string& name, long row, long col)
	{

		// Add sheet.
		Excel::_WorkbookPtr pWorkbook = xl->ActiveWorkbook;
		Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->Add();
		pSheet->Name = name.c_str();
		
		// Make empty row labels. Can later make it more general
		std::list<std::string> rowLabels;
		for (std::size_t r2 = 0; r2 < matrix.size1(); ++r2)
		{
			rowLabels.push_back(std::string(""));
		}

		// Add row labels + values.
		std::list<std::string>::const_iterator rowLabelIt = rowLabels.begin();
		for (std::size_t r = 0; r < matrix.size1(); ++r)
		{
			std::vector<double> rowArray = CreateVector<Matrix, std::vector<double>>(matrix, r);
			ToSheetHorizontal(pSheet, row, col, *rowLabelIt, rowArray);
			rowLabelIt++;
			row++;
		}
		
	}

	

// Vector visualisation
template <typename Matrix>
	void ExcelDriver::AddVector(const std::vector<double>& vec, const std::string& name, long row, long col)
{

	Matrix m = CreateMatrix<Matrix, std::vector<double>>(vec);

	AddMatrix<Matrix>(m, name, row, col);
}

template <typename Matrix>
	void ExcelDriver::AddVector(const std::vector<double>& vec, const std::string& sheetName,
				const std::string& rowLabel, const std::list<std::string>& columnLabels,
				long row, long col)
{
		Matrix m = CreateMatrix<Matrix, std::vector<double>>(vec);
		std::list<std::string> rowLabels; 
		rowLabels.push_back(rowLabel);

		AddMatrix<Matrix> (m, sheetName, rowLabels, columnLabels, row, col);

}

// For debugging, for example

void ExcelDriver::printStringInExcel(const std::string& s, long rowNumber, long colNumber)
{ // Mainly for debugging

  // Add sheet.
	Excel::_WorkbookPtr pWorkbook = xl->ActiveWorkbook;
	Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->Add();

	// Add properties to cells.
	Excel::RangePtr pRange = pSheet->Cells;
	pRange->Item[rowNumber][colNumber] = s.c_str();
}


void ExcelDriver::printStringInExcel(const std::list<std::string>& s, long startRow, long colNumber)
{ // Mainly for debugging

  // Add sheet.
	Excel::_WorkbookPtr pWorkbook = xl->ActiveWorkbook;
	Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->Add();


	Excel::RangePtr pRange = pSheet->Cells;

	for (auto it = s.begin(); it != s.end(); it++)
	{
		pRange->Item[startRow][colNumber] = (*it).c_str();
		startRow++;
	}

}

#endif

