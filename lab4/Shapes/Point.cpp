#include "stdafx.h"
#include "Point.h"

CPoint::CPoint(double x, double y)
	: m_x(x)
	, m_y(y)
{
}

CPoint::~CPoint()
{
}

double CPoint::GetX() const
{
	return m_x;
}

double CPoint::GetY() const
{
	return m_y;
}