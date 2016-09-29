#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char  * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: compare.exe <file1> <file2>\n";
		return 1;
	}

	ifstream inputFirstFile(argv[1]);
	ifstream inputSecondFile(argv[2]);

	if (!inputFirstFile.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}
	else if (!inputSecondFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return 1;
	}

	string lineFirstFile, lineSecondFile;
	int lineNumber = 1;
	bool isSameFiles = false;

	if (inputFirstFile.peek() == -1 && inputSecondFile.peek() == -1)
	{
		isSameFiles = true;
	}

	while (getline(inputFirstFile, lineFirstFile) && getline(inputSecondFile, lineSecondFile))
	{
		if (lineFirstFile == lineSecondFile)
		{
			isSameFiles = true;
		}
		else
		{
			isSameFiles = false;
			break;
		}
		lineNumber++;
	}

	if (isSameFiles)
	{
		cout << "Files are equal\n";
	}
	else
	{
		cout << "Files are different. Line number is " << lineNumber << "\n";
		return 1; 
	}

    return 0;
}