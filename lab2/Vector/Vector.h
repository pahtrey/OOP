#pragma once
#include "stdafx.h"

using namespace std;

vector<double> ReadNumbersFromStream(istream & stream);

vector<double> SortNumbers(vector<double> numbers);

void PrintNumbersToStream(const vector<double> numbers, ostream & stream);

void ProcessVector(vector<double> & numbers);