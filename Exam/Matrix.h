#pragma once
#include<iostream>
using namespace std;

template<class T>
class Matrix
{
	T** matrix;
	int cols;
	int rows;
public:
	Matrix()
	{
		cols = 2;
		rows = 2;
		matrix = new T*[rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new T[cols];
		}
	}
	Matrix(int Rows, int Cols)
	{
		rows = Rows;
		cols = Cols;
		matrix = new T*[Rows];
		for (int i = 0; i < Rows; i++)
		{
			matrix[i] = new T[Cols];
		}
	}
	Matrix(const Matrix<T>& cpy)
	{
		matrix = new T*[rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new T[cols];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				matrix[i][j] = cpy.matrix[i][j];
			}
		}
	}
	Matrix& operator=(Matrix<T>& cpy)
	{
		if (this != &cpy)
		{
			rows = cpy.rows;
			cols = cpy.cols;
			for (int i = 0; i < rows; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;

			matrix = new T*[rows];
			for (int i = 0; i < rows; i++)
			{
				matrix[i] = new T[cols];
			}

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					matrix[i][j] = cpy.matrix[i][j];
				}
			}
		}
		return *this;
	}

	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	void Matrix::setAt(unsigned int x, unsigned int y, T element)
	{
		matrix[x - 1][y - 1] = element;
	}


	const T Matrix::getAt(unsigned int x, unsigned int y) const
	{
		return matrix[x - 1][y - 1];
	}


	void print() const
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << " " << matrix[i][j];
			}
			cout << endl;
		}
	}
	
	/*void transpose()
	{
		if (rows == cols)
		{
			T** arr;
			{
				arr
			}

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					arr[i][j] = matrix[j][i];
				}
			}
		}
		else cout << "Wrong input" << endl;
	}*/
};