#include "stdafx.h"
#include "Vector.h"

using namespace std;

int main()
{
	vector<double> numbers = ReadNumbersFromStream(cin);

	ProcessVector(numbers);

	vector<double> numbersSorted = SortNumbers(numbers);

	PrintNumbersToStream(numbersSorted, cout);

	return 0;
}