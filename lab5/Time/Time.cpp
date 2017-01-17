#include "stdafx.h"
#include <iomanip>
#include "Time.h"

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
{
	if (hours > MAX_HOURS_IN_DAY || minutes > MAX_MINUTES_IN_HOUR || seconds > MAX_SECONDS_IN_MINUTE)
	{
		throw std::invalid_argument("Invalid arguments values");
	}
	m_secondsAfterMidnight = hours * SECONDS_IN_HOUR + minutes * SECONDS_IN_MINUTE + seconds;
}

CTime::CTime(unsigned timeStamp)
{
	if (timeStamp > SECONDS_IN_DAY)
	{
		throw std::invalid_argument("Timestamp must be less than 86400");
	}
	else if (timeStamp < SECONDS_IN_DAY)
	{
		m_secondsAfterMidnight = timeStamp;
	}
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

CTime const CTime::operator ++(int)
{
	CTime timeCopy(m_secondsAfterMidnight);
	++*this;
	return timeCopy;
}

CTime & CTime::operator ++()
{
	++m_secondsAfterMidnight;
	if (m_secondsAfterMidnight >= SECONDS_IN_DAY)
	{
		m_secondsAfterMidnight = m_secondsAfterMidnight - SECONDS_IN_DAY;
	}
	return *this;
}

bool CTime::operator ==(CTime const & other) const
{
	return m_secondsAfterMidnight == other.m_secondsAfterMidnight;
}

bool CTime::operator !=(CTime const & other) const
{
	return !(*this == other);
}

bool CTime::operator <(CTime const & other) const
{
	return m_secondsAfterMidnight < other.m_secondsAfterMidnight;
}

bool CTime::operator >(CTime const & other) const
{
	return m_secondsAfterMidnight > other.m_secondsAfterMidnight;
}

bool CTime::operator <=(CTime const & other) const
{
	return m_secondsAfterMidnight <= other.m_secondsAfterMidnight;
}

bool CTime::operator >=(CTime const & other) const
{
	return m_secondsAfterMidnight >= other.m_secondsAfterMidnight;
}

CTime & CTime::operator +=(CTime const & other)
{
	m_secondsAfterMidnight += other.m_secondsAfterMidnight;
	if (m_secondsAfterMidnight >= SECONDS_IN_DAY)
	{
		m_secondsAfterMidnight -= SECONDS_IN_DAY;
	}
	return *this;
}

CTime & CTime::operator -=(CTime const & other)
{
	signed subtractionResult = m_secondsAfterMidnight - other.m_secondsAfterMidnight;
	if (subtractionResult < 0)
	{
		subtractionResult = SECONDS_IN_DAY + subtractionResult;
	}
	m_secondsAfterMidnight = subtractionResult;
	return *this;
}

CTime const CTime::operator +(CTime const & other)const
{
	signed additionResult = m_secondsAfterMidnight + other.m_secondsAfterMidnight;
	return CTime((additionResult >= SECONDS_IN_DAY) ? additionResult - SECONDS_IN_DAY : additionResult);
}

CTime const CTime::operator -(CTime const & other)const
{
	signed subtractionResult = m_secondsAfterMidnight - other.m_secondsAfterMidnight;
	return CTime((subtractionResult < 0) ? SECONDS_IN_DAY + subtractionResult : subtractionResult);
}

CTime const CTime::operator --(int)
{
	CTime tmpCopy(m_secondsAfterMidnight);
	--*this;
	return tmpCopy;
}

CTime & CTime::operator --()
{
	m_secondsAfterMidnight == 0 ? m_secondsAfterMidnight = SECONDS_IN_DAY - 1: --m_secondsAfterMidnight;
	return *this;
}

CTime const CTime::operator *(unsigned number)const
{
	unsigned multiplicationResult = m_secondsAfterMidnight * number;
	return CTime((multiplicationResult >= SECONDS_IN_DAY)
		? multiplicationResult % SECONDS_IN_DAY
		: multiplicationResult);
}

CTime const operator *(unsigned number, CTime const & other)
{
	unsigned multiplicationResult = other.m_secondsAfterMidnight * number;
	return CTime((multiplicationResult >= SECONDS_IN_DAY)
		? multiplicationResult % SECONDS_IN_DAY
		: multiplicationResult);
}

CTime const CTime::operator /(unsigned number)const
{
	if (number == 0)
	{
		throw std::invalid_argument("Can't divide by zero");
	}
	return CTime(m_secondsAfterMidnight / number);
}

unsigned CTime::operator /(CTime const & other)const
{
	if (other.m_secondsAfterMidnight == 0)
	{
		throw std::invalid_argument("Can't divide by zero");
	}
	return m_secondsAfterMidnight / other.m_secondsAfterMidnight;
}

CTime & CTime::operator *=(unsigned number)
{
	m_secondsAfterMidnight *= number;
	if (m_secondsAfterMidnight >= SECONDS_IN_DAY)
	{
		m_secondsAfterMidnight = m_secondsAfterMidnight % SECONDS_IN_DAY;
	}
	return *this;
}

CTime & CTime::operator /=(unsigned number)
{
	if (number == 0)
	{
		throw std::invalid_argument("Can't divide by zero");
	}
	m_secondsAfterMidnight /= number;
	return *this;
}

std::ostream & operator <<(std::ostream & output, CTime const & time)
{
	output << std::setfill('0') << std::setw(2) << time.GetHours() << ":";
	output << std::setfill('0') << std::setw(2) << time.GetMinutes() << ":";
	output << std::setfill('0') << std::setw(2) << time.GetSeconds();
	return output;
}

std::istream & operator >>(std::istream & input, CTime & time)
{
	unsigned hours;
	unsigned minutes;
	unsigned seconds;
	if (input >> hours
		&& input.get() == ':'
		&& input >> minutes
		&& input.get() == ':'
		&& input >> seconds)
	{
		time = CTime(hours, minutes, seconds);
	}
	else
	{
		input.setstate(std::ios::failbit);
	}
	return input;
}