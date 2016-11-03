#include "stdafx.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

enum class RotationDirection
{
	LEFT,
	RIGHT
};

RotationDirection GetRotationDirection(const string directionString)
{
	RotationDirection rotationDirection;
	if (directionString == "L")
	{
		rotationDirection = RotationDirection::LEFT;
	}
	else if (directionString == "R")
	{
		rotationDirection = RotationDirection::RIGHT;
	}

	return rotationDirection;
}

int Rotate(uint8_t number, unsigned int numberOfBits, RotationDirection rotationDirection);

int main(int argc, char * argv[])
{
	if (argc != 4)
	{
		cout << "Invalid arguments count" << endl
			<< "Usage: rotatebyte.exe <byte> <number of bits> <L / R>" << endl;
		return 1;
	}

	uint8_t number = atoi(argv[1]);
	unsigned int numberOfBits = atoi(argv[2]);
	string directionString = argv[3];
	
	if (number == 0) {
		cout << "Invalid parameter type" << endl
			<< "<byte> parameter must be numerical, but found: " << argv[1] << endl;
		return 1;
	}

	if (numberOfBits > 8)
	{
		cout << "Invalid parameter value" << endl
			<< "<number of bits> parameter should be within [0, 8], but found: " << argv[2] << endl;
		return 1;
	}

	if (directionString != "L" && directionString != "R")
	{
		cout << "Invalid parameter value" << endl
			<< "<L / R> parameter should be L or R, but found: " << argv[3] << endl;
		return 1;
	}

	RotationDirection rotationDirection = GetRotationDirection(directionString);

	int rotatedNumber;

	rotatedNumber = Rotate(number, numberOfBits, rotationDirection);

	cout << rotatedNumber << endl;

	return 0;
}

int Rotate(uint8_t number, unsigned int numberOfBits, RotationDirection rotationDirection)
{
	const unsigned int BITS_IN_BYTE = 8;
	
	if (rotationDirection == RotationDirection::LEFT)
	{
		number = (number << numberOfBits) | (number >> (BITS_IN_BYTE - numberOfBits));
	}
	else if (rotationDirection == RotationDirection::RIGHT)
	{
		number = (number >> numberOfBits) | (number << (BITS_IN_BYTE - numberOfBits));
	}

	return number;
}