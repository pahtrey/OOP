#pragma once
#include "stdafx.h"

class CPoint
{
public:
	CPoint() = default;
	CPoint(double x, double y);

	double x = 0;
	double y = 0;

	bool operator ==(CPoint point) const;
	std::string ToString() const;
};