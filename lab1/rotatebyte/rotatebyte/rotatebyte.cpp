#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void rotation(int number, int numberOfBits, string rotationDirection);

int main(int argc, char * argv[])
{
	if (argc != 4)
	{
		cout << "Invalid arguments count" << endl
			<< "Usage: rotatebyte.exe <byte> <number of bits> <L / R>" << endl;
		return 1;
	}

	int number = atoi(argv[1]);
	int numberOfBits = atoi(argv[2]);
	string rotationDirection = argv[3];
	
	if (number == 0) {
		cout << "Invalid parameter type" << endl
			<< "<byte> parameter must be numerical, but found: " << argv[1] << endl;
		return 1;
	}

	if (numberOfBits < 0 || numberOfBits > 8)
	{
		cout << "Invalid parameter value" << endl
			<< "<number of bits> parameter should be within [2, 8], but found: " << argv[2] << endl;
		return 1;
	}

	if (rotationDirection != "L" && rotationDirection != "R")
	{
		cout << "Invalid parameter value" << endl
			<< "<L / R> parameter should be L or R, but found: " << argv[3] << endl;
		return 1;
	}
	
	rotation(number, numberOfBits, rotationDirection);

	return 0;
}

void rotation(int number, int numberOfBits, string rotationDirection)
{
	const int BYTE_SIZE = 8;
	
	if (rotationDirection == "L")
	{
		number = (number >> numberOfBits) | (number << BYTE_SIZE - numberOfBits);
		cout << number << endl;
	}

	if (rotationDirection == "R")
	{
		number = (number << numberOfBits) | (number >> BYTE_SIZE - numberOfBits);
		cout << number << endl;
	}
}