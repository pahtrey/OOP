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

	CTime const CTime::operator ++(int);
	CTime & operator ++();

	bool operator ==(CTime const & other) const;
	bool operator !=(CTime const & other) const;

	bool operator <(CTime const & other) const;
	bool operator >(CTime const & other) const;

	bool operator <=(CTime const & other) const;
	bool operator >=(CTime const & other) const;

	CTime & operator +=(CTime const & other);
	CTime & operator -=(CTime const & other);

	CTime const operator +(CTime const & other) const;
	CTime const operator -(CTime const & other) const;
private:
	unsigned m_secondsAfterMidnight = 0;
};