#include "stdafx.h"
#include "Vector.h"

using namespace std;

vector<double> ReadNumbersFromStream(istream & stream)
{
	vector<double> numbers;

	copy(istream_iterator<double>(stream), istream_iterator<double>(), back_inserter(numbers));

	return numbers;
}

vector<double> SortNumbers(vector<double> & numbers)
{
	sort(numbers.begin(), numbers.end());

	return numbers;
}

void PrintNumbersToStream(vector<double> const & numbers, ostream & stream)
{
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(stream, " "));
	stream << endl;
}

void ProcessVector(vector<double> & numbers)
{
	if (numbers.empty())
	{
		return;
	}

	double minElement = *min_element(numbers.begin(), numbers.end());

	transform(numbers.begin(), numbers.end(), numbers.begin(), [=](double element) {
		return element * minElement;
	});
}