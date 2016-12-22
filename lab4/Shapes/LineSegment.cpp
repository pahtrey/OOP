#include "stdafx.h"
#include "LineSegment.h"

using namespace std;

CLineSegment::CLineSegment(CPoint startPoint, CPoint endPoint, string const & outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_outlineColor(outlineColor)
{
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	return CalculateLineSegmentLength(m_startPoint, m_endPoint);
}

string CLineSegment::ToString() const
{
	ostringstream strm;
	strm << "Line segment:" << endl << setprecision(4)
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

double CLineSegment::CalculateLineSegmentLength(CPoint startPoint, CPoint endPoint)
{
	return sqrt(pow(endPoint.x - startPoint.x, 2) + pow(endPoint.y - startPoint.y, 2));
}