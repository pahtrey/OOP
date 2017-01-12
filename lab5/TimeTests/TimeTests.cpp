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

	BOOST_FIXTURE_TEST_SUITE(has_operator, TimeFixture)

		BOOST_AUTO_TEST_CASE(postfix_increment)
		{
			CTime time(12, 30, 15);
			CTime time1(23, 59, 59);
			BOOST_CHECK(CheckTime(time++, 12, 30, 15));
			BOOST_CHECK(CheckTime(time, 12, 30, 16));
			BOOST_CHECK(CheckTime(time1++, 23, 59, 59));
			BOOST_CHECK(CheckTime(time1, 0, 0, 0));
		}

		BOOST_AUTO_TEST_CASE(prefix_increment)
		{
			CTime time(12, 30, 15);
			CTime time1(23, 59, 59);
			BOOST_CHECK(CheckTime(++time, 12, 30, 16));
			BOOST_CHECK(CheckTime(++time1, 0, 0, 0));
		}

		BOOST_AUTO_TEST_CASE(equal_to)
		{
			CTime time1(12, 30, 15);
			CTime time2(12, 30, 15);
			BOOST_CHECK(time1 == time2);
		}

		BOOST_AUTO_TEST_CASE(not_equal_to)
		{
			CTime time1(12, 30, 15);
			CTime time2(23, 59, 59);
			BOOST_CHECK(time1 != time2);
		}

		BOOST_AUTO_TEST_CASE(less_than)
		{
			CTime time1(12, 30, 15);
			CTime time2(23, 59, 59);
			BOOST_CHECK(time1 < time2);
		}

		BOOST_AUTO_TEST_CASE(greater_than)
		{
			CTime time1(12, 30, 15);
			CTime time2(23, 59, 59);
			BOOST_CHECK(time2 > time1);
		}

		BOOST_AUTO_TEST_CASE(less_than_or_equal_to)
		{
			CTime time1(12, 30, 15);
			CTime time2(23, 59, 59);
			BOOST_CHECK(time1 <= time2);
			BOOST_CHECK(time1 <= time1);
		}

		BOOST_AUTO_TEST_CASE(greater_than_or_equal_to)
		{
			CTime time1(12, 30, 15);
			CTime time2(23, 59, 59);
			BOOST_CHECK(time2 >= time1);
			BOOST_CHECK(time2 >= time2);
		}

		BOOST_AUTO_TEST_CASE(assignment_addition)
		{
			CTime time1(12, 30, 15);
			CTime time2(1, 10, 15);
			CTime time3(12, 1, 1);
			BOOST_CHECK(CheckTime(time1 += time2, 13, 40, 30));
			BOOST_CHECK(CheckTime(time1 += time3, 1, 41, 31));
		}

		BOOST_AUTO_TEST_CASE(assignment_subtraction)
		{
			CTime time1(12, 30, 15);
			CTime time2(1, 10, 15);
			CTime time3(12, 0, 0);
			BOOST_CHECK(CheckTime(time1 -= time2, 11, 20, 0));
			BOOST_CHECK(CheckTime(time1 -= time3, 23, 20, 0));
		}

		BOOST_AUTO_TEST_CASE(addition)
		{
			CTime time1(12, 30, 15);
			CTime time2(1, 10, 15);
			CTime time3(12, 1, 1);
			BOOST_CHECK(CheckTime(time1 + time2, 13, 40, 30));
			BOOST_CHECK(CheckTime(time1 + time3, 0, 31, 16));
		}

		BOOST_AUTO_TEST_CASE(subtraction)
		{
			CTime time1(12, 30, 15);
			CTime time2(1, 10, 15);
			CTime time3(13, 0, 0);
			BOOST_CHECK(CheckTime(time1 - time2, 11, 20, 0));
			BOOST_CHECK(CheckTime(time1 - time3, 23, 30, 15));
		}

		BOOST_AUTO_TEST_CASE(postfix_decrement)
		{
			CTime time(12, 30, 15);
			CTime time1(0, 0, 0);
			BOOST_CHECK(CheckTime(time--, 12, 30, 15));
			BOOST_CHECK(CheckTime(time, 12, 30, 14));
			BOOST_CHECK(CheckTime(time1--, 0, 0, 0));
			BOOST_CHECK(CheckTime(time1, 23, 59, 59));
		}

		BOOST_AUTO_TEST_CASE(prefix_decrement)
		{
			CTime time(12, 30, 15);
			CTime time1(0, 0, 0);
			BOOST_CHECK(CheckTime(--time, 12, 30, 14));
			BOOST_CHECK(CheckTime(--time1, 23, 59, 59));
		}

		BOOST_AUTO_TEST_CASE(multiplication)
		{
			CTime time(12, 30, 15);
			CTime multiplicationCheck = time * 2;
			CTime multiplicationCheck1 = 2 * time;
			CTime multiplicationCheck3 = time * 0;
			BOOST_CHECK(CheckTime(multiplicationCheck, 1, 0, 30));
			BOOST_CHECK(CheckTime(multiplicationCheck1, 1, 0, 30));
			BOOST_CHECK(CheckTime(multiplicationCheck3, 0, 0, 0));
		}

		BOOST_AUTO_TEST_CASE(division)
		{
			CTime time(12, 30, 15);
			CTime time1(10, 10, 10);
			CTime time2(2, 2, 2);
			CTime time3(0, 0, 0);
			CTime divisionCheck = time / 3;
			unsigned divisionCheck1 = time1 / time2;
			BOOST_CHECK(CheckTime(divisionCheck, 4, 10, 5));
			BOOST_REQUIRE_THROW(time / 0, std::logic_error);
			BOOST_CHECK(divisionCheck1 == 5);
			BOOST_REQUIRE_THROW(time1 / time3, std::logic_error);
		}

		BOOST_AUTO_TEST_CASE(assignment_multiplication)
		{
			CTime time(6, 15, 10);
			time *= 2;
			BOOST_CHECK(CheckTime(time, 12, 30, 20));
			time *= 2;
			BOOST_CHECK(CheckTime(time, 1, 0, 40));
		}

		BOOST_AUTO_TEST_CASE(assignment_division)
		{
			CTime time(12, 30, 10);
			time /= 2;
			BOOST_CHECK(CheckTime(time, 6, 15, 5));
			BOOST_REQUIRE_THROW(time /= 0, std::logic_error);
		}

		BOOST_AUTO_TEST_CASE(insert_string_into_stream)
		{
			CTime time(12, 30, 15);
			std::stringstream output;
			output << time;
			BOOST_CHECK_EQUAL(output.str(), "12:30:15");
			output.str(std::string());

			CTime time1(6, 15, 5);
			output << time1;
			BOOST_CHECK_EQUAL(output.str(), "06:15:05");
			output.str(std::string());

			CTime time2(99, 99, 99);
			output << time2;
			BOOST_CHECK_EQUAL(output.str(), "INVALID");
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()