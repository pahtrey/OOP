#pragma once
#include "stdafx.h"

using namespace std;

vector<double> ReadNumbersFromStream(istream & stream);

vector<double> SortNumbers(vector<double> & numbers);

void PrintNumbersToStream(vector<double> const & numbers, ostream & stream);

void ProcessVector(vector<double> & numbers);