#include "stdafx.h"
#include "Rectangle.h"

using namespace std;

CRectangle::CRectangle(CPoint leftTop, double width, double height, std::string const & outlineColor, std::string const & fillColor)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return (m_width + m_height) * 2;
}

string CRectangle::ToString() const
{
	ostringstream strm;
	strm << "Rectangle:" << endl << setprecision(4)
		<< "\tarea = " << GetArea() << endl
		<< "\tperimeter = " << GetPerimeter() << endl
		<< "\twidth = " << GetWidth() << endl
		<< "\theight = " << GetHeight() << endl
		<< "\toutline color = " << GetOutlineColor() << endl
		<< "\tfill color = " << GetFillColor() << endl;

	return strm.str();
}

string CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

string CRectangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return CPoint(m_leftTop.x + m_width, m_leftTop.y + m_height);
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}