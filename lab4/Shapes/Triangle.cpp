#include "stdafx.h"
#include "Triangle.h"
#include "LineSegment.h"

using namespace std;

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, string const & outlineColor, string const & fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
	m_line1 = CLineSegment::CalculateLineSegmentLength(vertex1, vertex2);
	m_line2 = CLineSegment::CalculateLineSegmentLength(vertex2, vertex3);
	m_line3 = CLineSegment::CalculateLineSegmentLength(vertex3, vertex1);
}

double CTriangle::GetArea() const
{
	double semiperimeter = (m_line1 + m_line2 + m_line3) / 2;
	return sqrt(semiperimeter * (semiperimeter - m_line1) * (semiperimeter - m_line2) * (semiperimeter - m_line3));
}

double CTriangle::GetPerimeter() const
{
	return m_line1 + m_line2 + m_line3;
}

string CTriangle::ToString() const
{
	ostringstream strm;
	strm << "Triangle:" << endl << setprecision(4)
		<< "\tarea = " << GetArea() << endl
		<< "\tperimeter = " << GetPerimeter() << endl
		<< "\tvertex1 = " << m_vertex1.ToString() << endl
		<< "\tvertex2 = " << m_vertex2.ToString() << endl
		<< "\tvertex3 = " << m_vertex3.ToString() << endl
		<< "\toutline color = " << GetOutlineColor() << endl
		<< "\tfill color = " << GetFillColor() << endl;

	return strm.str();
}

string CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

string CTriangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}