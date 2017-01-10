#pragma once
#include "TimeConstants.h"

class CTime
{
public:
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);
	CTime(unsigned timeStamp = 0);

	unsigned GetHours() const;
	unsigned GetMinutes() const;
	unsigned GetSeconds() const;

	bool isValid() const;


private:
	unsigned m_secondsAfterMidnight = 0;
};