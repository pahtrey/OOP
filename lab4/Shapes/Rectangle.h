#pragma once
#include "SolidShape.h"
#include "Point.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle();

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

	~CRectangle();
private:
	CPoint m_leftTop;
	double m_width;
	double m_height;
};

