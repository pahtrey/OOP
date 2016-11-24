#include "stdafx.h"
#include "WordCount.h"

using namespace std;

WordMap ReadMapFromStream(istream & stream)
{
	WordMap mapping;
	string word;

	while (stream >> word)
	{
		mapping[word];
	}

	return mapping;
}

WordMap WordCount(WordMap mapping)
{
	WordMap mapping;
	return mapping;
}

void PrintMapToStream(ostream & stream, WordMap & mapping)
{
	for (auto word : mapping)
	{
		stream << word.first << word.second << endl;
	}
}