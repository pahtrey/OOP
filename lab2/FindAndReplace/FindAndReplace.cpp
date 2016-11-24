#include "stdafx.h"
#include "FindAndReplace.h"

string FindAndReplace(string const & subject, string const & search, string const & replace)
{
	if (subject.length() == 0 || search.length() == 0)
	{
		return subject;
	}

	string resultString = "";
	size_t leftPosition = 0;
	size_t rightPosition = 0;

	while (rightPosition != string::npos)
	{
		rightPosition = subject.find(search, leftPosition);

		if (rightPosition != string::npos)
		{
			resultString.append(subject, leftPosition, rightPosition - leftPosition);
			resultString.append(replace);
			leftPosition = rightPosition + search.length();
		}
	}

	resultString.append(subject, leftPosition, subject.length());

	return resultString;
}