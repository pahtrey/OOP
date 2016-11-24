#include "stdafx.h"
#include "WordCount.h"

using namespace std;

WordMap WordCount(istream & stream)
{
	WordMap words;
	string word;

	while (stream >> word)
	{
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		++words[word];
	}

	return words;
}

void PrintMapToStream(ostream & stream, WordMap & words)
{
	for (auto word = words.begin(); word != words.end(); ++word)
	{
		stream << word->first << "->" << word->second << endl;
	}
}