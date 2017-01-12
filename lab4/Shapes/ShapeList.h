#pragma once
#include "stdafx.h"
#include "Shape.h"

class CShapeList
{
public:
	CShapeList() = default;
	~CShapeList() = default;

	void ReadShape(std::string shape);
	void PrintMinPerimeterShape();
	void PrintMaxAreaShape();
private:
	void AddLineSegment(const std::vector<std::string> & parameters);
	void AddRectangle(const std::vector<std::string> & parameters);
	void AddCircle(const std::vector<std::string> & parameters);
	void AddTriangle(const std::vector<std::string> & parameters);

	std::vector<std::shared_ptr<IShape>> m_shapeList;
};