#pragma once
#include "SolidShape.h"
#include "Point.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle();

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

	~CTriangle();
private:
	CPoint m_vertext1;
	CPoint m_vertext2;
	CPoint m_vertext3;
};

