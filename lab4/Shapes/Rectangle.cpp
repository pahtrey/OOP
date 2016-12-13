#include "stdafx.h"
#include "Rectangle.h"

using namespace std;

CRectangle::CRectangle()
{
}

CRectangle::~CRectangle()
{
}

double CRectangle::GetArea() const
{
	return 0.0;
}

double CRectangle::GetPerimeter() const
{
	return 0.0;
}

string CRectangle::ToString() const
{
	return "";
}

string CRectangle::GetOutlineColor() const
{
	return "";
}

string CRectangle::GetFillColor() const
{
	return "";
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	CPoint point(0.0, 0.0);

	return point;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
