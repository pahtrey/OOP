#include "stdafx.h"
#include "Circle.h"

using namespace std;

CCircle::CCircle(CPoint center, double radius, string & outlineColor, string & fillColor)
	: m_center(center)
	, m_radius(radius)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

CCircle::~CCircle()
{
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

string CCircle::ToString() const
{
	ostringstream strm;
	strm << "Circle:" << endl << setprecision(4)
		<< "\tarea = " << GetArea() << endl
		<< "\tperimeter = " << GetPerimeter() << endl
		<< "\toutline color = " << GetOutlineColor() << endl
		<< "\tfill color = " << GetFillColor() << endl;

	return strm.str();
}

string CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

string CCircle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}