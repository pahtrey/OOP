#pragma once
#include "stdafx.h"

using namespace std;

typedef map<string, size_t> WordMap;

WordMap ReadMapFromStream(istream & stream);

WordMap WordCount(WordMap mapping);

void PrintMapToStream(ostream & stream , WordMap & mapping);