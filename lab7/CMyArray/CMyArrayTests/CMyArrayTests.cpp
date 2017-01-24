#include "stdafx.h"
#define BOOST_TEST_NO_MAIN
#include <boost/test/included/unit_test.hpp>
#include "../CMyArray/CMyArray.h"
#include <algorithm>

using namespace std;

struct ArrayItem
{
	ArrayItem(int value = 0) : value(value)
	{}
	int value;
};

struct EmptyStringArray
{
	CMyArray<ArrayItem> arr;
};

bool CheckEqualArrays(CMyArray<ArrayItem> const& left, CMyArray<ArrayItem> const& right)
{
	for (size_t i = 0; i < left.GetSize(); ++i)
	{
		if (left[i].value != right[i].value)
		{
			return false;
		}
	}
	return left.GetSize() == right.GetSize();
}

BOOST_FIXTURE_TEST_SUITE(MyArray, EmptyStringArray)
	BOOST_AUTO_TEST_SUITE(by_default)
		BOOST_AUTO_TEST_CASE(is_empty)
		{
			BOOST_CHECK_EQUAL(arr.GetSize(), 0u);
		}

		BOOST_AUTO_TEST_CASE(has_0_capacity)
		{
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 0u);
		}
		BOOST_AUTO_TEST_CASE(has_not_access_by_subscript)
		{
			ArrayItem x;
			BOOST_CHECK_THROW(x = arr[0], std::out_of_range);
			BOOST_CHECK_THROW(x = arr[-1], std::out_of_range);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(after_appending_an_item)
		BOOST_AUTO_TEST_CASE(increases_its_size_and_capacity)
		{
			arr.Append(ArrayItem());
			BOOST_CHECK_EQUAL(arr.GetSize(), 1u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 1u);
			arr.Append(ArrayItem());
			BOOST_CHECK_EQUAL(arr.GetSize(), 2u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 2u);
			arr.Append(ArrayItem());
			BOOST_CHECK_EQUAL(arr.GetSize(), 3u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
			arr.Append(ArrayItem());
			BOOST_CHECK_EQUAL(arr.GetSize(), 4u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
		}

		BOOST_AUTO_TEST_CASE(it_becomes_available_at_the_back)
		{
			arr.Append(1);
			BOOST_CHECK_EQUAL(arr.GetBack().value, 1);
			arr.Append(2);
			BOOST_CHECK_EQUAL(arr.GetBack().value, 2);
			arr.Append(3);
			BOOST_CHECK_EQUAL(arr.GetBack().value, 3);
			arr.Append(4);
			BOOST_CHECK_EQUAL(arr.GetBack().value, 4);
		}

		BOOST_AUTO_TEST_CASE(has_access_by_subscript)
		{
			arr.Append(1);
			BOOST_CHECK_EQUAL(arr[0].value, 1);
			arr.Append(2);
			BOOST_CHECK_EQUAL(arr[1].value, 2);
			arr.Append(3);
			BOOST_CHECK_EQUAL(arr[2].value, 3);
			arr.Append(4);
			BOOST_CHECK_EQUAL(arr[3].value, 4);
			BOOST_CHECK_THROW(auto x = arr[4], std::out_of_range);
		}

		BOOST_AUTO_TEST_CASE(can_be_resized)
		{
			arr.Append(1);
			arr.Append(2);
			BOOST_CHECK_EQUAL(arr.GetSize(), 2);
			arr.Resize(4);
			BOOST_CHECK_EQUAL(arr.GetSize(), 4);
			BOOST_CHECK_EQUAL(arr[0].value, 1);
			BOOST_CHECK_EQUAL(arr[1].value, 2);
			BOOST_CHECK_EQUAL(arr[2].value, 0);
			BOOST_CHECK_EQUAL(arr[3].value, 0);
			arr.Resize(1);
			BOOST_CHECK_EQUAL(arr.GetSize(), 1);
			BOOST_CHECK_EQUAL(arr[0].value, 1);
		}

		BOOST_AUTO_TEST_CASE(can_be_cleared)
		{
			for (auto i = 0; i < 6; ++i)
			{
				arr.Append(i);
			}
			BOOST_CHECK_EQUAL(arr.GetSize(), 6u);
			BOOST_CHECK_NO_THROW(arr.Clear());
			BOOST_CHECK_EQUAL(arr.GetSize(), 0u);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(after_copy_construction)
		BOOST_AUTO_TEST_CASE(has_size_capacity_equal_to_size_of_original_array)
		{
			for (auto i = 0; i < 6; ++i)
			{
				arr.Append(i);
			}
			BOOST_CHECK_NE(arr.GetSize(), arr.GetCapacity());

			auto copy(arr);
			BOOST_CHECK_EQUAL(copy.GetSize(), arr.GetSize());
			BOOST_CHECK_EQUAL(copy.GetCapacity(), arr.GetSize());
		}
		BOOST_AUTO_TEST_CASE(when_in_original_array_changing_item_copy_without_changes)
		{
			for (auto i = 0; i < 6; ++i)
			{
				arr.Append(i);
			}
			auto copy1(arr);
			auto copy2(arr);
			arr[0] = 6;
			BOOST_CHECK(!CheckEqualArrays(copy1, arr));
			BOOST_CHECK(CheckEqualArrays(copy1, copy2));
		}

		BOOST_AUTO_TEST_CASE(can_be_assigned_with_itself)
		{
			for (auto i = 0; i < 6; ++i)
			{
				arr.Append(i);
			}
			auto copy(arr);
			arr = arr;
			BOOST_CHECK(CheckEqualArrays(copy, arr));
		}

		BOOST_AUTO_TEST_CASE(can_be_assigned)
		{
			CMyArray<ArrayItem> oneEmptyArr, twoEmptyArr;
			for (auto i = 0; i < 6; ++i)
			{
				arr.Append(i);
			}
			oneEmptyArr = arr;
			BOOST_CHECK(CheckEqualArrays(oneEmptyArr, arr));
			arr = twoEmptyArr;
			BOOST_CHECK(CheckEqualArrays(arr, twoEmptyArr));
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(after_moving_construction)
		BOOST_AUTO_TEST_CASE(has_size_capacity_equal_to_old_size_of_original_array)
		{
			for (auto i = 0; i < 6; ++i)
			{
				arr.Append(i);
			}
			BOOST_CHECK_NE(arr.GetSize(), arr.GetCapacity());

			size_t size = arr.GetSize();
			size_t capacity = arr.GetCapacity();

			auto newArr(move(arr));
			BOOST_CHECK_EQUAL(newArr.GetSize(), size);
			BOOST_CHECK_EQUAL(newArr.GetCapacity(), capacity);
		}

		BOOST_AUTO_TEST_CASE(original_array_is_empty)
		{
			for (auto i = 0; i < 6; ++i)
			{
				arr.Append(i);
			}

			auto newArr(move(arr));
			BOOST_CHECK_EQUAL(arr.GetSize(), 0);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 0);
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct CMyIterFixture : EmptyStringArray
	{
		CMyArray<int> intArray;
		CMyArray<string> stringArray;
		CMyIter<int> it, itEnd;
		CMyIter<string> itStr;
		CMyIterFixture()
		{
			stringArray.Append("hello");
			stringArray.Append("world");
			stringArray.Append("!");

			for (auto i = 0; i < 6; ++i)
			{
				intArray.Append(i);
			}
			it = intArray.begin();
			itEnd = intArray.end();
			itStr = stringArray.begin();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(iterator, CMyIterFixture)
		BOOST_AUTO_TEST_CASE(can_return_designated_object)
		{
			BOOST_CHECK_EQUAL(*it, 0);
		}

		BOOST_AUTO_TEST_CASE(can_return_pointer_to_class_object)
		{
			BOOST_CHECK_EQUAL(itStr->size(), 5);
		}

		BOOST_AUTO_TEST_CASE(can_preincrement)
		{
			BOOST_CHECK_EQUAL(*(++it), 1);
		}

		BOOST_AUTO_TEST_CASE(can_postincrement)
		{
			BOOST_CHECK_EQUAL(*(it++), 0);
			BOOST_CHECK_EQUAL(*it, 1);
		}

		BOOST_AUTO_TEST_CASE(can_predecrement)
		{
			BOOST_CHECK_EQUAL(*(--itEnd), 5);
		}

		BOOST_AUTO_TEST_CASE(can_postdecrement)
		{
			--itEnd;
			BOOST_CHECK_EQUAL(*(itEnd--), 5);
			BOOST_CHECK_EQUAL(*itEnd, 4);
		}

		BOOST_AUTO_TEST_CASE(can_increment_by_integer)
		{
			it += 2;
			BOOST_CHECK_EQUAL(*it, 2);
		}

		BOOST_AUTO_TEST_CASE(can_return_this_plus_integer)
		{
			BOOST_CHECK_EQUAL(*(it + 2), 2);
		}

		BOOST_AUTO_TEST_CASE(can_decrement_by_integer)
		{
			itEnd -= 2;
			BOOST_CHECK_EQUAL(*itEnd, 4);
		}

		BOOST_AUTO_TEST_CASE(can_return_this_minus_integer)
		{
			BOOST_CHECK_EQUAL(*(itEnd - 2), 4);
		}

		BOOST_AUTO_TEST_CASE(can_return_difference_of_iterators)
		{
			BOOST_CHECK_EQUAL(itEnd - it, 6);
		}

		BOOST_AUTO_TEST_CASE(can_subscript)
		{
			BOOST_CHECK_EQUAL(it[4], 4);
		}

		BOOST_AUTO_TEST_CASE(can_test_for_iterator_equality)
		{
			BOOST_CHECK(it == intArray.begin());
			BOOST_CHECK(!(it == intArray.end()));
		}

		BOOST_AUTO_TEST_CASE(can_test_for_iterator_inequality)
		{
			BOOST_CHECK(it != intArray.end());
			BOOST_CHECK(!(it != intArray.begin()));
		}

		BOOST_AUTO_TEST_CASE(can_test_if_this_less_right)
		{
			BOOST_CHECK(itEnd > it);
			BOOST_CHECK(!(it > it));
			BOOST_CHECK(!(it > itEnd));
		}

		BOOST_AUTO_TEST_CASE(can_test_if_this_greater_right)
		{
			BOOST_CHECK(it < itEnd);
			BOOST_CHECK(!(it < it));
			BOOST_CHECK(!(itEnd < it));
		}

		BOOST_AUTO_TEST_CASE(can_test_if_this_less_equal_right)
		{
			BOOST_CHECK(it <= itEnd);
			BOOST_CHECK(it <= it);
			BOOST_CHECK(!(itEnd <= it));
		}

		BOOST_AUTO_TEST_CASE(can_test_if_this_greater_equal_right)
		{
			BOOST_CHECK(itEnd >= it);
			BOOST_CHECK(it >= it);
			BOOST_CHECK(!(it >= itEnd));
		}

		BOOST_AUTO_TEST_CASE(compatible_with_stl)
		{
			int i = 0;
			for (auto& arrElement : arr)
			{
				BOOST_CHECK_EQUAL(*it, i++);
			}
		}
	BOOST_AUTO_TEST_SUITE_END()

	struct ReverseCMyIterFixture : EmptyStringArray
	{
		CMyArray<int> intArray;
		CMyArray<string> stringArray;
		std::reverse_iterator<CMyIter<int>> it, itEnd;
		std::reverse_iterator<CMyIter<string>> itStr;
		ReverseCMyIterFixture()
		{
			stringArray.Append("hello");
			stringArray.Append("world");
			stringArray.Append("!");

			for (auto i = 0; i < 6; ++i)
			{
				intArray.Append(i);
			}
			it = intArray.rbegin();
			itEnd = intArray.rend();
			itStr = stringArray.rbegin();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(reverse_iterator, ReverseCMyIterFixture)
		BOOST_AUTO_TEST_CASE(can_return_designated_object)
		{
			BOOST_CHECK_EQUAL(*it, 5);
		}

		BOOST_AUTO_TEST_CASE(can_return_pointer_to_class_object)
		{
			BOOST_CHECK_EQUAL(itStr->size(), 1);
		}

		BOOST_AUTO_TEST_CASE(can_preincrement)
		{
			BOOST_CHECK_EQUAL(*(++it), 4);
		}

		BOOST_AUTO_TEST_CASE(can_postincrement)
		{
			BOOST_CHECK_EQUAL(*(it++), 5);
			BOOST_CHECK_EQUAL(*it, 4);
		}

		BOOST_AUTO_TEST_CASE(can_predecrement)
		{
			BOOST_CHECK_EQUAL(*(--itEnd), 0);
		}

		BOOST_AUTO_TEST_CASE(can_postdecrement)
		{
			--itEnd;
			BOOST_CHECK_EQUAL(*(itEnd--), 0);
			BOOST_CHECK_EQUAL(*itEnd, 1);
		}

		BOOST_AUTO_TEST_CASE(can_increment_by_integer)
		{
			it += 2;
			BOOST_CHECK_EQUAL(*it, 3);
		}

		BOOST_AUTO_TEST_CASE(can_return_this_plus_integer)
		{
			BOOST_CHECK_EQUAL(*(it + 2), 3);
		}

		BOOST_AUTO_TEST_CASE(can_decrement_by_integer)
		{
			itEnd -= 2;
			BOOST_CHECK_EQUAL(*itEnd, 1);
		}

		BOOST_AUTO_TEST_CASE(can_return_this_minus_integer)
		{
			BOOST_CHECK_EQUAL(*(itEnd - 2), 1);
		}

		BOOST_AUTO_TEST_CASE(can_return_difference_of_iterators)
		{
			BOOST_CHECK_EQUAL(itEnd - it, 6);
		}

		BOOST_AUTO_TEST_CASE(can_subscript)
		{
			BOOST_CHECK_EQUAL(it[4], 1);
		}

		BOOST_AUTO_TEST_CASE(can_test_for_iterator_equality)
		{
			BOOST_CHECK(it == intArray.rbegin());
			BOOST_CHECK(!(it == intArray.rend()));
		}

		BOOST_AUTO_TEST_CASE(can_test_for_iterator_inequality)
		{
			BOOST_CHECK(it != intArray.rend());
			BOOST_CHECK(!(it != intArray.rbegin()));
		}

		BOOST_AUTO_TEST_CASE(can_test_if_this_less_right)
		{
			BOOST_CHECK(itEnd > it);
			BOOST_CHECK(!(it > it));
			BOOST_CHECK(!(it > itEnd));
		}

		BOOST_AUTO_TEST_CASE(can_test_if_this_greater_right)
		{
			BOOST_CHECK(it < itEnd);
			BOOST_CHECK(!(it < it));
			BOOST_CHECK(!(itEnd < it));
		}

		BOOST_AUTO_TEST_CASE(can_test_if_this_less_equal_right)
		{
			BOOST_CHECK(it <= itEnd);
			BOOST_CHECK(it <= it);
			BOOST_CHECK(!(itEnd <= it));
		}

		BOOST_AUTO_TEST_CASE(can_test_if_this_greater_equal_right)
		{
			BOOST_CHECK(itEnd >= it);
			BOOST_CHECK(it >= it);
			BOOST_CHECK(!(it >= itEnd));
		}

		BOOST_AUTO_TEST_CASE(compatible_with_stl)
		{
			stringstream stream;
			std::for_each(stringArray.rbegin(), stringArray.rend(), [&](auto& str) {
				stream << str;
			});
			BOOST_CHECK_EQUAL(stream.str(), "!worldhello");
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()