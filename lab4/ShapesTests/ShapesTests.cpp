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
		BOOST_CHECK(point.GetX() == 11.11);
	}

	BOOST_AUTO_TEST_CASE(can_get_y_value)
	{
		CPoint point(11.11, 5.7);
		BOOST_CHECK(point.GetY() == 5.7);
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

BOOST_FIXTURE_TEST_SUITE(LineSegment, LineSegmentFixture)
	BOOST_AUTO_TEST_CASE(has_zero_area)
	{
		BOOST_CHECK(lineSegment.GetArea() == 0.0);
	}

	BOOST_AUTO_TEST_CASE(has_zero_perimeter)
	{
		BOOST_CHECK(lineSegment.GetPerimeter() == 0.0);
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
	perimeter = 0
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

BOOST_FIXTURE_TEST_SUITE(Circle, CircleFixture)
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