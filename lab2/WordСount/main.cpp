#include "stdafx.h"
#include "WordCount.h"

using namespace std;

int main()
{
	WordMap mapping = ReadMapFromStream(cin);
	PrintMapToStream(cout, mapping);
	system("pause");
	return 0;
}