#include "stdafx.h"
#include "ShapeList.h"
#include "Shape.h"
#include "SolidShape.h"
#include "Point.h"
#include "LineSegment.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

using namespace std;

void CShapeList::ReadShape(string shape)
{
	boost::to_lower(shape);
	vector<string> parameters;
	boost::split(parameters, shape, boost::is_any_of(" "));
	if (parameters[0] == "linesegment")
	{
		AddLineSegment(parameters);
	}
	else if (parameters[0] == "rectangle")
	{
		AddRectangle(parameters);
	}
	else if (parameters[0] == "circle")
	{
		AddCircle(parameters);
	}
	else if (parameters[0] == "triangle")
	{
		AddTriangle(parameters);
	}
	else
	{
		throw invalid_argument("Invalid command");
	}
}

void CShapeList::AddLineSegment(const std::vector<std::string> & parameters)
{
	if (parameters.size() != 6)
	{
		throw invalid_argument("Invalid arguments count in LineSegment");
	}
	CPoint startPoint(stod(parameters[1]), stod(parameters[2]));
	CPoint endPoint(stod(parameters[3]), stod(parameters[4]));
	string outlineColor = parameters[5];
	auto lineSegment = make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
	m_shapeList.push_back(lineSegment);
}

void CShapeList::AddRectangle(const std::vector<std::string> & parameters)
{
	if (parameters.size() != 7)
	{
		throw invalid_argument("Invalid arguments count in Rectangle");
	}
	CPoint leftTopPoint(stod(parameters[1]), stod(parameters[2]));
	double width = stod(parameters[3]);
	double height = stod(parameters[4]);
	string oulineColor = parameters[5];
	string fillColor = parameters[6];
	auto rectangle = make_shared<CRectangle>(leftTopPoint, width, height, oulineColor, fillColor);
	m_shapeList.push_back(rectangle);
}

void CShapeList::AddCircle(const std::vector<std::string> & parameters)
{
	if (parameters.size() != 6)
	{
		throw invalid_argument("Invalid arguments count in Circle");
	}
	CPoint centerPoint(stod(parameters[1]), stod(parameters[2]));
	double radius = stod(parameters[3]);
	string oulineColor = parameters[4];
	string fillColor = parameters[5];
	auto circle = make_shared<CCircle>(centerPoint, radius, oulineColor, fillColor);
	m_shapeList.push_back(circle);
}

void CShapeList::AddTriangle(const std::vector<std::string> & parameters)
{
	if (parameters.size() != 9)
	{
		throw invalid_argument("Invalid arguments count in Triangle");
	}
	CPoint vertex1(stod(parameters[1]), stod(parameters[2]));
	CPoint vertex2(stod(parameters[3]), stod(parameters[4]));
	CPoint vertex3(stod(parameters[5]), stod(parameters[6]));
	string oulineColor = parameters[7];
	string fillColor = parameters[8];
	auto triangle = make_shared<CTriangle>(vertex1, vertex2, vertex3, oulineColor, fillColor);
	m_shapeList.push_back(triangle);
}

void CShapeList::PrintMinPerimeterShape()
{
	if (m_shapeList.empty())
	{
		return;
	}
	auto minPerimeterShape = min_element(m_shapeList.begin(), m_shapeList.end(), [](auto & firstShape, auto & secondShape) {
		return firstShape->GetPerimeter() < secondShape->GetPerimeter();
	});
	cout << "Shape with min perimetr is" << endl
		<< (*minPerimeterShape)->ToString() << endl;
}

void CShapeList::PrintMaxAreaShape()
{
	if (m_shapeList.empty())
	{
		return;
	}
	auto maxAreaShape = max_element(m_shapeList.begin(), m_shapeList.end(), [](auto & firstShape, auto & secondShape) {
		return firstShape->GetArea() < secondShape->GetArea();
	});
	cout << "Shape with max area is" << endl
		<< (*maxAreaShape)->ToString() << endl;
}