#include "stdafx.h"
#define BOOST_TEST_NO_MAIN 
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Shapes)
	BOOST_AUTO_TEST_CASE(can_run_first_test)
	{
		BOOST_CHECK(true);
	}
BOOST_AUTO_TEST_SUITE_END()