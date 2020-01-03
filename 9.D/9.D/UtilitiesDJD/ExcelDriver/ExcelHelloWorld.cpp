// ExcelHelloWorld.cpp
//
// (C) Datasim Education BV 2012-2017
//
#include <string>
#include <iostream>
#include "ExcelImports.cpp"

#include "atlsafe.h"	// Data types

// Extract a value from a cell
double GetDoubleFromCell(Excel::_WorksheetPtr sheet, CComBSTR cell)
{ 

	Excel::RangePtr range=sheet->GetRange(CComVariant(cell));
	_variant_t value=range->GetValue2();
	return value;
}

// Put a double value in an Excel cell
void SetCellValue(Excel::_WorksheetPtr sheet, CComBSTR cell, double value)
{
	Excel::RangePtr range=sheet->GetRange(CComVariant(cell));
	range->Value2=value;
}


int main()
{
	{
		Excel::_ApplicationPtr xl;		// Pointer to Excel.

	
		try
			{
				// Initialize COM Runtime Libraries.
				CoInitialize(NULL);

				// Start excel application.
				xl.CreateInstance(L"Excel.Application");
				xl->Visible = VARIANT_TRUE;
				xl->Workbooks->Add((long) Excel::xlWorksheet);
         
				// Rename "Sheet1" to "Chart Data".
				Excel::_WorkbookPtr workbook = xl->ActiveWorkbook;
				// Can also GetItem by sheet name, but this may not work on non-English versions of Excel.
				// Excel::_WorksheetPtr sheet = workbook->Worksheets->GetItem("Sheet1"); //Language-dependent

				Excel::_WorksheetPtr sheet = workbook->Worksheets->GetItem(1); //Language-independent
				sheet->Name = "Chart Data";
	
				double val = 2.0;

				// Display values in Excel
				SetCellValue(sheet, "B9", val);
				SetCellValue(sheet, "B10", val*3);

				// Get the parameters
				double T = GetDoubleFromCell(sheet, "B9");
				double r = GetDoubleFromCell(sheet, "B10");

				// Display values in Excel somwhere else
				SetCellValue(sheet, "C9", T);
				SetCellValue(sheet, "C10", r);
			}
			catch( _com_error & error )
			{
				bstr_t description = error.Description();
				if( !description )
				{
					description = error.ErrorMessage();
				}
				std::cout << std::string(description);

			}
	}

	CoUninitialize();

	return 0;
}

	