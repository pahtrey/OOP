#include "stdafx.h"
#define BOOST_TEST_NO_MAIN 
#include <boost/test/included/unit_test.hpp>
#include "../Shapes/Point.h"
#include "../Shapes/LineSegment.h"
#include "../Shapes/Triangle.h"
#include "../Shapes/Rectangle.h"
#include "../Shapes/Circle.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Point)
	BOOST_AUTO_TEST_CASE(can_get_x_value)
	{
		CPoint point(11.11, 5.7);
		BOOST_CHECK(point.x == 11.11);
	}

	BOOST_AUTO_TEST_CASE(can_get_y_value)
	{
		CPoint point(11.11, 5.7);
		BOOST_CHECK(point.y == 5.7);
	}
BOOST_AUTO_TEST_SUITE_END()

struct LineSegmentFixture
{
	CPoint startPoint = CPoint(10.10, 15.02);
	CPoint endPoint = CPoint(30.40, 15.02);
	string outlineColor = "001100";

	CLineSegment lineSegment;
	LineSegmentFixture()
		: lineSegment(startPoint, endPoint, outlineColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(LineSegment_shape, LineSegmentFixture)
	BOOST_AUTO_TEST_CASE(has_zero_area)
	{
		BOOST_CHECK(lineSegment.GetArea() == 0.0);
	}

	BOOST_AUTO_TEST_CASE(has_perimeter)
	{
		double expectedPerimeter = 20.299999999999997;
		BOOST_CHECK_EQUAL(lineSegment.GetPerimeter(), expectedPerimeter);
	}

	BOOST_AUTO_TEST_CASE(can_get_outline_color)
	{
		BOOST_CHECK(lineSegment.GetOutlineColor() == outlineColor);
	}

	BOOST_AUTO_TEST_CASE(can_get_start_point)
	{
		BOOST_CHECK(lineSegment.GetStartPoint() == startPoint);
	}

	BOOST_AUTO_TEST_CASE(can_get_end_point)
	{
		BOOST_CHECK(lineSegment.GetEndPoint() == endPoint);
	}

	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(Line segment:
	area = 0
	perimeter = 20.3
	outline color = 001100
)";
		BOOST_CHECK_EQUAL(lineSegment.ToString(), expectedString);
	}

BOOST_AUTO_TEST_SUITE_END()

struct CircleFixture
{
	CPoint center = CPoint(30.01, 60.15);
	double radius = 2.3;
	string outlineColor = "001100";
	string fillColor = "0ddd00";

	CCircle circle;
	CircleFixture()
		: circle(center, radius, outlineColor, fillColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Circle_shape, CircleFixture)
	BOOST_AUTO_TEST_CASE(has_area)
	{
		double expectedAria = 16.619025137490002;
		BOOST_CHECK_EQUAL(circle.GetArea(), expectedAria);
	}

	BOOST_AUTO_TEST_CASE(has_perimeter)
	{
		double expectedPerimeter = 14.451326206513047;
		BOOST_CHECK_EQUAL(circle.GetPerimeter(), expectedPerimeter);
	}

	BOOST_AUTO_TEST_CASE(can_get_center_point)
	{
		BOOST_CHECK(circle.GetCenter() == center);
	}

	BOOST_AUTO_TEST_CASE(can_get_radius)
	{
		BOOST_CHECK(circle.GetRadius() == radius);
	}

	BOOST_AUTO_TEST_CASE(can_get_outline_color)
	{
		BOOST_CHECK(circle.GetOutlineColor() == outlineColor);
	}

	BOOST_AUTO_TEST_CASE(can_get_fill_color)
	{
		BOOST_CHECK(circle.GetFillColor() == fillColor);
	}

	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(Circle:
	area = 16.62
	perimeter = 14.45
	outline color = 001100
	fill color = 0ddd00
)";
		BOOST_CHECK_EQUAL(circle.ToString(), expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()

struct RectangleFixture
{
	CPoint leftTop = CPoint(10.10, 30.15);
	double width = 15.0;
	double height = 10.5;
	string outlineColor = "ff1100";
	string fillColor = "0dff00";

	CRectangle rectangle;
	RectangleFixture()
		: rectangle(leftTop, width, height, outlineColor, fillColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Rectangle_shape, RectangleFixture)
	BOOST_AUTO_TEST_CASE(has_area)
	{
		double expectedAria = 157.5;
		BOOST_CHECK_EQUAL(rectangle.GetArea(), expectedAria);
	}

	BOOST_AUTO_TEST_CASE(has_perimeter)
	{
		double expectedPerimeter = 51;
		BOOST_CHECK_EQUAL(rectangle.GetPerimeter(), expectedPerimeter);
	}

	BOOST_AUTO_TEST_CASE(can_get_width)
	{
		BOOST_CHECK(rectangle.GetWidth() == width);
	}

	BOOST_AUTO_TEST_CASE(can_get_height)
	{
		BOOST_CHECK(rectangle.GetHeight() == height);
	}

	BOOST_AUTO_TEST_CASE(can_get_outline_color)
	{
		BOOST_CHECK(rectangle.GetOutlineColor() == outlineColor);
	}

	BOOST_AUTO_TEST_CASE(can_get_fill_color)
	{
		BOOST_CHECK(rectangle.GetFillColor() == fillColor);
	}

	BOOST_AUTO_TEST_CASE(can_get_left_top)
	{
		BOOST_CHECK(rectangle.GetLeftTop() == leftTop);
	}

	BOOST_AUTO_TEST_CASE(can_get_right_bottom)
	{
		CPoint expectedRightBottom = CPoint(10.10 + width, 30.15 + height);
		BOOST_CHECK(rectangle.GetRightBottom() == expectedRightBottom);
	}

	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(Rectangle:
	area = 157.5
	perimeter = 51
	width = 15
	height = 10.5
	outline color = ff1100
	fill color = 0dff00
)";
		BOOST_CHECK_EQUAL(rectangle.ToString(), expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()

struct TriangleFixture
{
	CPoint vertex1 = CPoint(10., 10.);
	CPoint vertex2 = CPoint(15., 20.);
	CPoint vertex3 = CPoint(5., 20.);
	string outlineColor = "ff1100";
	string fillColor = "0dff00";

	CTriangle triangle;
	TriangleFixture()
		: triangle(vertex1, vertex2, vertex3, outlineColor, fillColor)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Triangle_shape, TriangleFixture)
	BOOST_AUTO_TEST_CASE(has_area)
	{
		double expectedAria = 50.000000000000007;
		BOOST_CHECK_EQUAL(triangle.GetArea(), expectedAria);
	}

	BOOST_AUTO_TEST_CASE(has_perimeter)
	{
		double expectedPerimeter = 32.360679774997898;
		BOOST_CHECK_EQUAL(triangle.GetPerimeter(), expectedPerimeter);
	}

	BOOST_AUTO_TEST_CASE(can_get_vertex1)
	{
		BOOST_CHECK(triangle.GetVertex1() == vertex1);
	}
	
	BOOST_AUTO_TEST_CASE(can_get_vertex2)
	{
		BOOST_CHECK(triangle.GetVertex2() == vertex2);
	}

	BOOST_AUTO_TEST_CASE(can_get_vertex3)
	{
		BOOST_CHECK(triangle.GetVertex3() == vertex3);
	}

	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(Triangle:
	area = 50
	perimeter = 32.36
	vertex1 = (10, 10)
	vertex2 = (15, 20)
	vertex3 = (5, 20)
	outline color = ff1100
	fill color = 0dff00
)";
		BOOST_CHECK_EQUAL(triangle.ToString(), expectedString);
	}

	BOOST_AUTO_TEST_CASE(can_get_outline_color)
	{
		BOOST_CHECK(triangle.GetOutlineColor() == outlineColor);
	}

	BOOST_AUTO_TEST_CASE(can_get_fill_color)
	{
		BOOST_CHECK(triangle.GetFillColor() == fillColor);
	}
BOOST_AUTO_TEST_SUITE_END()