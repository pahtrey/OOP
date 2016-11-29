#pragma once
#include "stdafx.h"

using namespace std;

size_t ReadNumberElementsFromStream(istream & stream);

set<int> GenerateFirstSet(string const & numberElements);

set<int> GenerateSecondSet(string const & numberElements);

void PrintSetToStream(ostream & stream, set<int> const & set);

set<int> CrossSet(set<int> const & set);