#include "stdafx.h"
#define BOOST_TEST_NO_MAIN 
#include <boost/test/included/unit_test.hpp>
#include "../ArraySum/ArraySum.h"

BOOST_AUTO_TEST_SUITE(ArraySumFunction)
	BOOST_AUTO_TEST_CASE(can_calculate_sum_of_integer_array)
	{
		std::vector<int> inputArray = { 1, 10, 0, -10 };
		int sum = ArraySum(inputArray);
		BOOST_CHECK(sum == 1);
	}
	BOOST_AUTO_TEST_CASE(can_calculate_sum_of_double_array)
	{
		std::vector<double> inputArray = { 3.3, -10.1, 0.0, 10.5 };
		double sum = ArraySum(inputArray);
		BOOST_CHECK(sum == 3.7);
	}
	BOOST_AUTO_TEST_CASE(can_calculate_sum_of_string_array)
	{
		std::vector<std::string> inputArray = { "Hello", " ", "World", "!", "!", "!" };
		std::string sum = ArraySum(inputArray);
		BOOST_CHECK_EQUAL(sum, "Hello World!!!");
	}
	BOOST_AUTO_TEST_SUITE(if_takes_empty_array)
		BOOST_AUTO_TEST_CASE(can_return_default_constructor_of_integer)
		{
			std::vector<int> inputArray = {};
			int sum = ArraySum(inputArray);
			BOOST_CHECK_EQUAL(sum, 0);
		}
		BOOST_AUTO_TEST_CASE(can_return_default_constructor_of_double)
		{
			std::vector<double> inputArray = {};
			double sum = ArraySum(inputArray);
			BOOST_CHECK_EQUAL(sum, 0);
		}
		BOOST_AUTO_TEST_CASE(can_return_default_constructor_of_string)
		{
			std::vector<std::string> inputArray = {};
			std::string sum = ArraySum(inputArray);
			BOOST_CHECK_EQUAL(sum, "");
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()