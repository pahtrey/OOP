#pragma once
#include "Shape.h"
#include "Point.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint startPoint, CPoint endPoint, std::string & outlineColor);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

	~CLineSegment();
private:
	std::string m_outlineColor;
	CPoint m_startPoint;
	CPoint m_endPoint;
};