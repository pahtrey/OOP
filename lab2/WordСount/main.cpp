#include "stdafx.h"
#include "WordCount.h"

using namespace std;

int main()
{
	WordMap words = WordCount(cin);

	PrintMapToStream(cout, words);

	return 0;
}