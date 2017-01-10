#include "stdafx.h"
#include "Time.h"

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
{
	m_secondsAfterMidnight = hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTE + seconds;
}

CTime::CTime(unsigned timeStamp) : m_secondsAfterMidnight(timeStamp)
{
}

unsigned CTime::GetHours() const
{
	return m_secondsAfterMidnight / SECONDS_IN_HOUR;
}

unsigned CTime::GetMinutes() const
{
	return m_secondsAfterMidnight / SECONDS_IN_MINUTE - GetHours() * SECONDS_IN_MINUTE;
}

unsigned CTime::GetSeconds() const
{
	return m_secondsAfterMidnight % SECONDS_IN_MINUTE;
}

bool CTime::isValid() const
{
	return m_secondsAfterMidnight < SECONDS_IN_DAY;
}
