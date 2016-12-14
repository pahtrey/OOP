#include "stdafx.h"
#define BOOST_TEST_NO_MAIN 
#include <boost/test/included/unit_test.hpp>
#include "../Shapes/Point.h"
#include "../Shapes/LineSegment.h"

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
		BOOST_CHECK(lineSegment.GetOutlineColor() == "001100");
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