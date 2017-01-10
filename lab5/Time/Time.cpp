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

/* �������� ++ ����������� ����� */
CTime const CTime::operator ++(int)
{
	CTime timeCopy(m_secondsAfterMidnight);
	++*this;
	return timeCopy;
}

/* �������� ++ ���������� ����� */
CTime & CTime::operator ++()
{
	++m_secondsAfterMidnight;
	if (m_secondsAfterMidnight >= SECONDS_IN_DAY)
	{
		m_secondsAfterMidnight = m_secondsAfterMidnight - SECONDS_IN_DAY;
	}
	return *this;
}

/* �������� == */
bool CTime::operator ==(CTime const & other) const
{
	return m_secondsAfterMidnight == other.m_secondsAfterMidnight;
}

/* �������� != */
bool CTime::operator !=(CTime const & other) const
{
	return !(*this == other);
}

/* �������� < */
bool CTime::operator <(CTime const & other) const
{
	return m_secondsAfterMidnight < other.m_secondsAfterMidnight;
}

/* �������� > */
bool CTime::operator >(CTime const & other) const
{
	return m_secondsAfterMidnight > other.m_secondsAfterMidnight;
}

/* �������� <= */
bool CTime::operator <=(CTime const & other) const
{
	return m_secondsAfterMidnight <= other.m_secondsAfterMidnight;
}

/* �������� >= */
bool CTime::operator >=(CTime const & other) const
{
	return m_secondsAfterMidnight >= other.m_secondsAfterMidnight;
}

/* �������� += */
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

/* �������� -= */
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

/* �������� + */
CTime const CTime::operator +(CTime const & other)const
{
	return CTime((m_secondsAfterMidnight + other.m_secondsAfterMidnight) % SECONDS_IN_DAY);
}

/* �������� - */
CTime const CTime::operator -(CTime const & other)const
{
	signed subtractionResult = m_secondsAfterMidnight - other.m_secondsAfterMidnight;
	return CTime((subtractionResult < 0) ? SECONDS_IN_DAY - (subtractionResult * (-1)) : subtractionResult);
}