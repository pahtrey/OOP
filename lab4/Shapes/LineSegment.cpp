#include "stdafx.h"
#include "LineSegment.h"

using namespace std;

CLineSegment::CLineSegment(CPoint startPoint, CPoint endPoint, string & outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_outlineColor(outlineColor)
{
}

CLineSegment::~CLineSegment()
{
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	return 0.0;
}

string CLineSegment::ToString() const
{
	ostringstream strm;
	strm << "Line segment:" << endl << setprecision(2)
		<< "\tarea = " << GetArea() << endl
		<< "\tperimeter = " << GetPerimeter() << endl
		<< "\toutline color = " << GetOutlineColor() << endl;

	return strm.str();
}

string CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}