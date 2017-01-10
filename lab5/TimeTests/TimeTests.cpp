#include "stdafx.h"
#define BOOST_TEST_NO_MAIN 
#include <boost/test/included/unit_test.hpp>
#include "../Time/Time.h"

struct TimeFixture
{
	CTime time;
};

BOOST_FIXTURE_TEST_SUITE(Time, TimeFixture)
	BOOST_AUTO_TEST_CASE(can_run_first_test)
	{
		BOOST_CHECK(true);
	}
BOOST_AUTO_TEST_SUITE_END()