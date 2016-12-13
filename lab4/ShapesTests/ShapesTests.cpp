#include "stdafx.h"
#define BOOST_TEST_NO_MAIN 
#include <boost/test/included/unit_test.hpp>
#include "../Shapes/Point.h"

BOOST_AUTO_TEST_SUITE(Point)
	BOOST_AUTO_TEST_CASE(can_be_created)
	{
		CPoint point(11.11, 5.7);
		BOOST_CHECK(point.GetX() == 11.11);
		BOOST_CHECK(point.GetY() == 5.7);
	}

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