// FindAndReplaceTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../FindAndReplace/FindAndReplace.h"
#include <boost/test/output/compiler_log_formatter.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(FindAndReplace_function)

	BOOST_AUTO_TEST_CASE(will_not_produce_replacement_if_search_string_empty)
	{
		string subject = "Hi, I'm simple string";
		string search = "";
		string replace = "Hello";
		BOOST_CHECK_EQUAL(FindAndReplace(subject, search, replace), subject);
	}

	BOOST_AUTO_TEST_CASE(will_not_produce_replacement_if_search_was_not_found)
	{
		string subject = "Hi, I'm simple string";
		string search = "Word";
		string replace = "Hello";
		BOOST_CHECK_EQUAL(FindAndReplace(subject, search, replace), subject);
	}

	BOOST_AUTO_TEST_CASE(will_not_produce_search_if_subject_string_empty)
	{
		string subject = "";
		string search = "Hi";
		string replace = "Hello";
		BOOST_CHECK_EQUAL(FindAndReplace(subject, search, replace), "");
	}

	BOOST_AUTO_TEST_CASE(replace_all_search_substrings_in_subject_string_to_replacer_string)
	{
		string subject = "Hi, I'm simple string";
		string search = "Hi";
		string replace = "Hello";
		BOOST_CHECK_EQUAL(FindAndReplace(subject, search, replace), "Hello, I'm simple string");
	}

BOOST_AUTO_TEST_SUITE_END()

class SpecLogFormatter :
	public boost::unit_test::output::compiler_log_formatter
{
public:
	SpecLogFormatter() : m_indent(0) {}
private:
	void test_unit_start(std::ostream &os,
		boost::unit_test::test_unit const& tu)
	{
		os << std::string(m_indent, ' ') <<
			boost::replace_all_copy(tu.p_name.get(), "_", " ") << std::endl;
		m_indent += 2;
	}
	void test_unit_finish(std::ostream &os,
		boost::unit_test::test_unit const& tu, unsigned long elapsed)
	{
		elapsed;
		tu;
		os;
		m_indent -= 2;
	}
	int m_indent;
};


boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
{
	boost::unit_test::unit_test_log.set_formatter(new SpecLogFormatter);
	boost::unit_test::framework::master_test_suite().p_name.value = "All tests";
	return 0;
}


int main(int argc, char* argv[])
{
	return boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);
}