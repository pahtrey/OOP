#pragma once
#include "SolidShape.h"
#include "Point.h"

class CCircle : public ISolidShape
{
public:
	CCircle();
	
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;

	CPoint GetCenter() const;
	double GetRadius() const;

	~CCircle();
private:
	CPoint m_center;
	double m_radius;
};