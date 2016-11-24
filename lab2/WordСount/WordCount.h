#pragma once
#include "stdafx.h"

using namespace std;

typedef map<string, size_t> WordMap;

WordMap WordCount(istream & stream);

void PrintMapToStream(ostream & stream , WordMap & mapping);