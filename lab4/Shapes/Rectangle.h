#pragma once
#include "SolidShape.h"
#include "Point.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint leftTop, double width, double height, std::string const & outlineColor, std::string const & fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
private:
	CPoint m_leftTop;
	double m_width;
	double m_height;
	std::string m_outlineColor;
	std::string m_fillColor;
};

