#include "stdafx.h"
#include "CrossSet.h"

size_t ReadNumberElementsFromStream(istream & stream)
{
	string tempString;
	getline(stream, tempString);
	stringstream sstream(tempString);

	size_t numberElements;
	sstream >> numberElements;

	return numberElements;
}

set<int> CreateSetOfNumbersDivisibleBySumOfItsDigits(string const & numberElements)
{

}

set<int> GenerateSecondSet(string const & numberElements)
{

}

void PrintSetToStream(ostream & stream, set<int> const & set)
{

}

bool isNumeric(string const & input) {
	return all_of(input.begin(), input.end(), ::isdigit);
}
