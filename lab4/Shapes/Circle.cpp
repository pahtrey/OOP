#include "stdafx.h"
#include "Circle.h"

using namespace std;

CCircle::CCircle()
{
}

CCircle::~CCircle()
{
}

double CCircle::GetArea() const
{
	return 0.0;
}

double CCircle::GetPerimeter() const
{
	return 0.0;
}

string CCircle::ToString() const
{
	return "";
}

string CCircle::GetOutlineColor() const
{
	return "";
}

string CCircle::GetFillColor() const
{
	return "";
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}