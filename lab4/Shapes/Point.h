#pragma once
#include "stdafx.h"

class CPoint
{
public:
	CPoint() = default;
	CPoint(double x, double y);

	double GetX() const;
	double GetY() const;

	~CPoint();
private:
	double m_x;
	double m_y;
};