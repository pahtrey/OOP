#include "stdafx.h"
#include "CrossSet.h"

using namespace std;

int main(int argc, char *argv[])
{
	size_t numberElements = ReadNumberElementsFromStream(cin);

	set<int> firstSet = CreateSetOfNumbersDivisibleBySumOfItsDigits(numberElements);
	set<int> secondSet = GenerateSecondSet(numberElements);
	PrintSetToStream(cout, firstSet);
	PrintSetToStream(cout, secondSet);

	set<int> crossSet = CrossSet(firstSet, secondSet);
	PrintSetToStream(cout, crossSet);
	
	return 0;
}