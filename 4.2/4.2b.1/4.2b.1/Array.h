//Purpose: The head file of Array Class
//Author: Tianyu Zhang
//Date: 06/22/18

#ifndef Array_h
#define Array_h


template <typename T>
class Array
{
private:
	int m_size;
	T* m_data;
	static int m_static_size;

public:
	// Constructors and destructors
	Array();
	Array(int size);
	Array(const Array<T>& source0);
	~Array();
	// SizeGetter
	// int Size() const;
	// Setter
	void SetElement(int index, const T& newT);
	// Getter
	T& GetElement(int index) const;
	static int DefaultSize();
	// Operator
	Array<T>& operator =(const Array<T>& source);
	T& operator [] (int index);
	const T& operator [] (int index) const;
	
	static void DefaultSize(int size);
};

//#ifndef Array_cpp // Must be the same name as in source file #define
//#include "Array.cpp"
//#endif
// Checking ARRAY.CPP file and including it with Array.h file.
#endif