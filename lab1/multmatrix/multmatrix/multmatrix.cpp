#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <array>

using namespace std;

const int ROW_SIZE = 3;
const int COL_SIZE = 3;
const int MATRIX_PRECISION = 3;

typedef array<array<double, COL_SIZE>, ROW_SIZE> Matrix;

void PrintMatrix(const Matrix & matrix);
Matrix ReadMatrixFromFile(ifstream & file);
Matrix MultiplyMatrix(const Matrix & firstMatrix, const Matrix & secondMatrix);

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count" << endl
				<< "Usage: multmatrix.exe <matrix file1> <matrix file2>" << endl;
		return 1;
	}

	ifstream firstFile(argv[1]);
	ifstream secondFile(argv[2]);

	if (!firstFile.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading" << endl;
		return 1;
	}
	else if (!secondFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading" << endl;
		return 1;
	}

	Matrix firstMatrix, secondMatrix, multipliedMatrix;

	try
	{
		firstMatrix = ReadMatrixFromFile(firstFile);
		secondMatrix = ReadMatrixFromFile(secondFile);
	}
	catch (const exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}

	multipliedMatrix = MultiplyMatrix(firstMatrix, secondMatrix);

	PrintMatrix(multipliedMatrix);

    return 0;
}

Matrix ReadMatrixFromFile(ifstream & file)
{
	Matrix matrix;
	size_t row = 0;
	string fileRow;

	while (getline(file, fileRow) && row < ROW_SIZE)
	{
		size_t col = 0;
		istringstream streamRow(fileRow);

		while (!streamRow.eof() && col < COL_SIZE)
		{
			streamRow >> matrix[row][col];
			++col;
		}
		
		if (col != COL_SIZE)
		{
			throw invalid_argument("Columns must contain 3 elements");
		}

		++row;
	}

	if (row != ROW_SIZE)
	{
		throw invalid_argument("Rows must contain 3 elements");
	}

	return matrix;
}

void PrintMatrix(const Matrix & matrix)
{
	for (size_t row = 0; row < ROW_SIZE; row++)
	{
		for (size_t col = 0; col < COL_SIZE; col++)
		{
			cout << fixed << setprecision(MATRIX_PRECISION) << matrix[row][col] << ' ';
		}
		cout << endl;
	}
}

Matrix MultiplyMatrix(const Matrix & firstMatrix, const Matrix & secondMatrix)
{
	Matrix resultMatrix;

	for (size_t row = 0; row < ROW_SIZE; row++)
	{
		for (size_t col = 0; col < COL_SIZE; col++)
		{
			resultMatrix[row][col] = 0;

			for (size_t i = 0; i < ROW_SIZE; i++)
			{
				resultMatrix[row][col] += firstMatrix[row][i] * secondMatrix[i][col];
			}
		}
	}

	return resultMatrix;
}