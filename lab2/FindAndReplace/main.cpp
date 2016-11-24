#include "stdafx.h"
#include "FindAndReplace.h"

using namespace std;

int main()
{
	string subject;
	string search;
	string replace;

	cout << "Input subject: ";
	getline(cin, subject);
	cout << endl;

	cout << "Input search: ";
	getline(cin, search);
	cout << endl;

	cout << "Input replace: ";
	getline(cin, replace);
	cout << endl;

	cout << FindAndReplace(subject, search, replace) << endl;

	return 0;
}