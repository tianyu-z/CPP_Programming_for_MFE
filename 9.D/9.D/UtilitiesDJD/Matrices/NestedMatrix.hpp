// NestedMatrix.hpp
//
// (C) Datasim Education BV 2017
//

#ifndef NestedMatrix_HPP
#define NestedMatrix_HPP

template <typename T> class NestedMatrix
{ // Simple class just to show Excel interoperability
private:
	std::vector<std::vector<T>> mat;

	std::size_t nr;
	std::size_t nc;
public:
	NestedMatrix(std::size_t rows, std::size_t cols) : nr(rows), nc(cols)
	{
		mat = std::vector<std::vector<T>>(nr);
		for (std::size_t i = 0; i < nr; ++i)
		{
			mat[i] = std::vector<T>(nc);
		}
	}

	NestedMatrix(const NestedMatrix<T>& m2) : nr(m2.nr), nc(m2.nc)
	{
		mat
			= std::vector<std::vector<T>>(nr);

		for (std::size_t i = 0; i < nr; ++i)
		{
			mat[i] = m2.mat[i];
		}
	}

	T& operator ()(std::size_t row, std::size_t col)
	{
		return mat[row][col];
	}

	const T& operator ()(std::size_t row, std::size_t col) const
	{
		return mat[row][col];
	}

	NestedMatrix operator - (const NestedMatrix<T>& m2)
	{

		NestedMatrix<T> diff(nr, nc);

		for (std::size_t i = 0; i < nr; ++i)
		{
			for (std::size_t j = 0; i < nc; ++j)
			{
				diff(i, j) = (*this)(i, j) - m2(i, j);
			}
		}
	}

	std::size_t size1() const
	{
		return nr;
	}

	std::size_t size2() const
	{
		return nc;
	}
};

#endif