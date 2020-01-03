//Purpose: The head file of functionObjects
//Author: Tianyu Zhang
//Date: 07/03/18

#ifndef FunctionObj_h
#define FunctionObj_h

template <typename T>
class FunctionObj
{
private:
	T limit;

public:
	// Constructors
	FunctionObj();
	FunctionObj(const T& t);
	FunctionObj(const FunctionObj<T>& source);

	// Destructor
	~FunctionObj();

	// Member operator overloading
	FunctionObj<T>& operator = (const FunctionObj<T>& source);
	int operator () (const T& t) const;
};

#endif