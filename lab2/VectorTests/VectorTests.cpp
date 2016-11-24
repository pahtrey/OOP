// VectorTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Vector/Vector.h"
#include <boost/test/output/compiler_log_formatter.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(ProcessVector_function)

	BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		ProcessVector(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}

	BOOST_AUTO_TEST_CASE(multiplies_vector_elements_on_minimal_element)
	{
		vector<double> inputVector = { 13, 5, 6, 7.1, 4, 2 };
		vector<double> expectedVector = { 26, 10, 12, 14.2, 8, 4 };
		ProcessVector(inputVector);
		BOOST_CHECK(inputVector == expectedVector);
	}

	BOOST_AUTO_TEST_CASE(works_with_negative_values)
	{
		vector<double> inputVector = { -10, 30, 80, 11, -5, 0 };
		vector<double> expectedVector = { 100, -300, -800, -110, 50, 0 };
		ProcessVector(inputVector);
		BOOST_CHECK(inputVector == expectedVector);
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
