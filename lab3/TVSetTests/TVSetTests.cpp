// TVSetTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "../TVSet/TVSet.h"

struct TVSetFixture
{
	CTVSet tvSet;
};

struct WhenTurnedOnFixture : TVSetFixture
{
	WhenTurnedOnFixture()
	{
		tvSet.TurnOn();
	}
};

BOOST_FIXTURE_TEST_SUITE(TVSet, TVSetFixture)

	BOOST_AUTO_TEST_CASE(is_turned_off_by_default)
	{
		BOOST_CHECK(!tvSet.IsTurnedOn());
	}

	BOOST_AUTO_TEST_CASE(has_zero_channel_number_then_turned_off)
	{
		BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 0);
	}

	BOOST_AUTO_TEST_CASE(can_not_switch_channel_then_turned_off)
	{
		bool isSuccessfulOperation = tvSet.SelectChannel(7);
		BOOST_CHECK(!isSuccessfulOperation);
	}
	
	BOOST_AUTO_TEST_CASE(can_be_turned_on)
	{
		tvSet.TurnOn();
		BOOST_CHECK(tvSet.IsTurnedOn());
	}

	BOOST_FIXTURE_TEST_SUITE(when_turned_on, WhenTurnedOnFixture)

		BOOST_AUTO_TEST_CASE(can_be_turned_off)
		{
			tvSet.TurnOff();
			BOOST_CHECK(!tvSet.IsTurnedOn());
		}

	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()