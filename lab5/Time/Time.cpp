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
	if (std::addressof(other) != this)
	{
		m_secondsAfterMidnight += other.m_secondsAfterMidnight;
		if (m_secondsAfterMidnight > SECONDS_IN_DAY)
		{
			m_secondsAfterMidnight -= SECONDS_IN_DAY;
		}
	}
	return *this;
}

CTime & CTime::operator -=(CTime const & other)
{
	if (std::addressof(other) != this)
	{
		signed subtractionResult = m_secondsAfterMidnight - other.m_secondsAfterMidnight;
		if (subtractionResult < 0)
		{
			subtractionResult = SECONDS_IN_DAY - (subtractionResult * (-1));
		}
		m_secondsAfterMidnight = subtractionResult;
	}
	return *this;
}

CTime const CTime::operator +(CTime const & other)const
{
	return CTime((m_secondsAfterMidnight + other.m_secondsAfterMidnight) % SECONDS_IN_DAY);
}

CTime const CTime::operator -(CTime const & other)const
{
	signed subtractionResult = m_secondsAfterMidnight - other.m_secondsAfterMidnight;
	return CTime((subtractionResult < 0) ? SECONDS_IN_DAY - (subtractionResult * (-1)) : subtractionResult);
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
	return CTime((multiplicationResult > SECONDS_IN_DAY)
		? multiplicationResult % SECONDS_IN_DAY
		: multiplicationResult);
}

CTime const operator *(unsigned number, CTime const & other)
{
	unsigned multiplicationResult = other.m_secondsAfterMidnight * number;
	return CTime((multiplicationResult > SECONDS_IN_DAY)
		? multiplicationResult % SECONDS_IN_DAY
		: multiplicationResult);
}

CTime const CTime::operator /(unsigned number)const
{
	if (number == 0)
	{
		throw std::logic_error("Can't divide by zero");
	}
	return CTime(m_secondsAfterMidnight / number);
}

unsigned CTime::operator /(CTime const & other)const
{
	if (other.m_secondsAfterMidnight == 0)
	{
		throw std::logic_error("Can't divide by zero");
	}
	return m_secondsAfterMidnight / other.m_secondsAfterMidnight;
}

CTime & CTime::operator *=(unsigned number)
{
	m_secondsAfterMidnight *= number;
	if (m_secondsAfterMidnight > SECONDS_IN_DAY)
	{
		m_secondsAfterMidnight = m_secondsAfterMidnight % SECONDS_IN_DAY;
	}
	return *this;
}

CTime & CTime::operator /=(unsigned number)
{
	if (number == 0)
	{
		throw std::logic_error("Can't divide by zero");
	}
	m_secondsAfterMidnight /= number;
	return *this;
}

std::ostream & operator <<(std::ostream & output, CTime const & time)
{
	if (time.isValid())
	{
		std::string hours = "0" + std::to_string(time.GetHours());
		std::string minutes = "0" + std::to_string(time.GetMinutes());
		std::string seconds = "0" + std::to_string(time.GetSeconds());
		output << hours.substr(hours.size() - 2) + ":" + minutes.substr(minutes.size() - 2) + ":" + seconds.substr(seconds.size() - 2);
	}
	else
	{
		output << "INVALID";
	}
	return output;
}