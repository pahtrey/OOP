#include "stdafx.h"
#define BOOST_TEST_NO_MAIN 
#include <boost/test/included/unit_test.hpp>
#include "../Time/Time.h"

struct TimeFixture
{
	CTime time;
};

bool CheckTime(const CTime & time, unsigned hours, unsigned minutes, unsigned seconds)
{
	return ((time.GetHours() == hours) && (time.GetMinutes() == minutes) && (time.GetSeconds() == seconds));
}

BOOST_FIXTURE_TEST_SUITE(Time, TimeFixture)
	BOOST_AUTO_TEST_CASE(can_be_initialized_by_hours_and_minutes_and_seconds)
	{
		CTime time(12, 30, 15);
		BOOST_CHECK(CheckTime(time, 12, 30, 15));
	}

	BOOST_AUTO_TEST_CASE(can_be_initialized_by_timestamp)
	{
		CTime time(36810);
		BOOST_CHECK(CheckTime(time, 10, 13, 30));
	}

	BOOST_AUTO_TEST_CASE(can_get_hours)
	{
		CTime time(36810);
		BOOST_CHECK(time.GetHours() == 10);
	}

	BOOST_AUTO_TEST_CASE(can_get_minutes)
	{
		CTime time(36810);
		BOOST_CHECK(time.GetMinutes() == 13);
	}

	BOOST_AUTO_TEST_CASE(can_get_seconds)
	{
		CTime time(36810);
		BOOST_CHECK(time.GetSeconds() == 30);
	}

	BOOST_AUTO_TEST_CASE(can_work_with_limit_values)
	{
		CTime time1(86400);
		CTime time2(0);
		BOOST_CHECK(CheckTime(time1, 24, 0, 0));
		BOOST_CHECK(CheckTime(time2, 0, 0, 0));
	}

	BOOST_AUTO_TEST_CASE(can_check_if_wrong_initialized)
	{
		CTime time(99, 32, 83);
		BOOST_CHECK(!time.isValid());
	}
BOOST_AUTO_TEST_SUITE_END()