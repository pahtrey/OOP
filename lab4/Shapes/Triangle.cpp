#include "stdafx.h"
#include "Triangle.h"

using namespace std;

CTriangle::CTriangle()
{
}

CTriangle::~CTriangle()
{
}

double CTriangle::GetArea() const
{
	return 0.0;
}

double CTriangle::GetPerimeter() const
{
	return 0.0;
}

string CTriangle::ToString() const
{
	return "";
}

string CTriangle::GetOutlineColor() const
{
	return "";
}

string CTriangle::GetFillColor() const
{
	return "";
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertext1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertext2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertext3;
}