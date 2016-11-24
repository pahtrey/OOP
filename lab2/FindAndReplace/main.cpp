#include "stdafx.h"
#include "FindAndReplace.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		cout << "Invalid arguments count" << endl
			<< "Usage: findandreplace.exe <subject-string> <search-string> <replace-string>" << endl;
		return 1;
	}

	string subject = argv[1];
	string search = argv[2];
	string replace = argv[3];

	cout << FindAndReplace(subject, search, replace) << endl;

	return 0;
}