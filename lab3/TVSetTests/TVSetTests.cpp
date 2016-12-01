// TVSetTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "../TVSet/TVSet.h"

struct TVSetFixture
{
	CTVSet tvSet;
};

struct TVSetTurnedOnFixture : TVSetFixture
{
	TVSetTurnedOnFixture()
	{
		tvSet.TurnOn();
	}
};

BOOST_FIXTURE_TEST_SUITE(TVSet, TVSetFixture)

	BOOST_AUTO_TEST_CASE(is_turned_off_by_default)
	{
		BOOST_CHECK(!tvSet.IsTurnedOn());
	}

	BOOST_FIXTURE_TEST_SUITE(when_turned_off, TVSetFixture)

		BOOST_AUTO_TEST_CASE(has_zero_channel_number)
		{
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 0);
		}

		BOOST_AUTO_TEST_CASE(can_not_switch_channel)
		{
			BOOST_CHECK(!tvSet.SelectChannel(7));
		}

		BOOST_AUTO_TEST_CASE(can_be_turned_on)
		{
			tvSet.TurnOn();
			BOOST_CHECK(tvSet.IsTurnedOn());
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_FIXTURE_TEST_SUITE(when_turned_on, TVSetTurnedOnFixture)

		BOOST_AUTO_TEST_CASE(can_be_turned_off)
		{
			tvSet.TurnOff();
			BOOST_CHECK(!tvSet.IsTurnedOn());
		}

		BOOST_AUTO_TEST_CASE(can_select_channel)
		{
			tvSet.SelectChannel(7);
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 7);
		}

		BOOST_AUTO_TEST_CASE(has_start_channel_value_1)
		{
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 1);
		}

		BOOST_AUTO_TEST_CASE(has_channel_range_between_1_and_99)
		{
			BOOST_CHECK(!tvSet.SelectChannel(999));
		}

		BOOST_AUTO_TEST_CASE(on_first_start_can_switch_to_previous_channel_that_have_number_1)
		{
			tvSet.TurnOn();
			BOOST_CHECK(tvSet.SelectPreviousChannel());
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 1);
		}

		BOOST_AUTO_TEST_CASE(on_start_remains_previously_selected_channel)
		{
			tvSet.SelectChannel(10);
			tvSet.TurnOff();
			tvSet.TurnOn();
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 10);
		}

		BOOST_AUTO_TEST_CASE(on_start_can_switch_to_previous_channel)
		{
			tvSet.TurnOn();
			tvSet.SelectChannel(10);
			tvSet.SelectChannel(55);
			tvSet.TurnOff();
			tvSet.TurnOn();
			BOOST_CHECK(tvSet.SelectPreviousChannel());
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 10);
		}

		BOOST_AUTO_TEST_CASE(can_switch_to_previous_channel)
		{
			tvSet.SelectChannel(10);
			tvSet.SelectChannel(40);
			tvSet.SelectPreviousChannel();
			BOOST_CHECK_EQUAL(tvSet.GetSelectedChannelNumber(), 10);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()