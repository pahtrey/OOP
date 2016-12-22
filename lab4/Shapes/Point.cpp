#include "stdafx.h"
#include "Point.h"

using namespace std;

CPoint::CPoint(double x, double y)
	: x(x)
	, y(y)
{
}

bool CPoint::operator ==(CPoint point) const
{
	return (x == point.x && y == point.y);
}

string CPoint::ToString() const
{
	ostringstream strm;
	strm << "(" << x << ", " << y << ")";

	return strm.str();
}