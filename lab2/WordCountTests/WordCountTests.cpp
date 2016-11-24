// WordCountTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Word—ount/WordCount.h"
#include <boost/test/output/compiler_log_formatter.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(WordCount_function)

	BOOST_AUTO_TEST_CASE(does_not_consider_word_count_then_input_string_is_empty)
	{
		WordMap result = {};
		istringstream testString("");
		BOOST_CHECK(result == WordCount(testString));
	}

	BOOST_AUTO_TEST_CASE(count_the_number_words_in_input_string)
	{
		WordMap result = { {"name" , 1}, {"is", 2}, { "korsakov", 1 }, {"my", 2}, {"pavel", 1}, {"surname", 1} };
		istringstream testString("my name is Pavel\n My surname IS Korsakov");
		BOOST_CHECK(result == WordCount(testString));
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