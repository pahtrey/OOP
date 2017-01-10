#include "stdafx.h"
#include "Time.h"

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
{
	std::string errorMessage;

	if (hours > MAX_HOURS_IN_DAY)
	{
		errorMessage = "Hours must be less than " + MAX_HOURS_IN_DAY;
		throw std::invalid_argument(errorMessage);
	}
	else if(minutes > MAX_MINUTES_IN_HOUR)
	{
		errorMessage = "Minutes must be less than " + MAX_MINUTES_IN_HOUR;
		throw std::invalid_argument(errorMessage);
	}
	else if (seconds > MAX_SECONDS_IN_MINUTE)
	{
		errorMessage = "Seconds must be less than " + MAX_SECONDS_IN_MINUTE;
		throw std::invalid_argument(errorMessage);
	}

	m_secondsAfterMidnight = hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTE + seconds;
}

CTime::CTime(unsigned timeStamp)
{
	std::string errorMessage;

	if (timeStamp > SECONDS_IN_DAY)
	{
		errorMessage = "Timestamp must be less than " + SECONDS_IN_DAY;
		throw std::invalid_argument(errorMessage);
	}

	m_secondsAfterMidnight = timeStamp;
}