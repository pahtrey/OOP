#include "stdafx.h"
#define BOOST_TEST_NO_MAIN 
#include <boost/test/included/unit_test.hpp>
#include "../HttpUrl/HttpUrl.h"
#include "../HttpUrl/UrlParsingError.h"

void CheckUrlInitializating(CHttpUrl const & url
	, Protocol expectedProtocol
	, std::string const & expectedDomain
	, unsigned short expectedPort
	, std::string const & expectedDocument
	, std::string const & expectedUrl)
{
	BOOST_CHECK(url.GetProtocol() == expectedProtocol);
	BOOST_CHECK_EQUAL(url.GetDomain(), expectedDomain);
	BOOST_CHECK(url.GetPort() == expectedPort);
	BOOST_CHECK_EQUAL(url.GetDocument(), expectedDocument);
	BOOST_CHECK_EQUAL(url.GetUrl(), expectedUrl);
}

BOOST_AUTO_TEST_SUITE(HttpUrl)
	BOOST_AUTO_TEST_SUITE(can_be_initialize_by)
		BOOST_AUTO_TEST_CASE(url_string)
		{
			CheckUrlInitializating(CHttpUrl("http://www.google.ru/testpage/")
				, Protocol::HTTP
				, "www.google.ru"
				, 80
				, "/testpage/"
				, "http://www.google.ru/testpage/");

			CheckUrlInitializating(CHttpUrl("https://google.ru")
				, Protocol::HTTPS
				, "google.ru"
				, 443
				, "/"
				, "https://google.ru/");

			CheckUrlInitializating(CHttpUrl("HTTPS://google.ru:333/testpage")
				, Protocol::HTTPS
				, "google.ru"
				, 333
				, "/testpage"
				, "https://google.ru:333/testpage");
		}
		BOOST_AUTO_TEST_CASE(domain_and_document_and_protocol)
		{
			CheckUrlInitializating(CHttpUrl("google.com", "testpage", Protocol::HTTP)
				, Protocol::HTTP
				, "google.com"
				, 80
				, "/testpage"
				, "http://google.com/testpage");

			CheckUrlInitializating(CHttpUrl("google.com", "testpage/", Protocol::HTTPS)
				, Protocol::HTTPS
				, "google.com"
				, 443
				, "/testpage/"
				, "https://google.com/testpage/");
		}
		BOOST_AUTO_TEST_CASE(domain_and_document_and_protocol_and_port)
		{
			CheckUrlInitializating(CHttpUrl("google.com", "testpage", Protocol::HTTP, 111)
				, Protocol::HTTP
				, "google.com"
				, 111
				, "/testpage"
				, "http://google.com:111/testpage");

			CheckUrlInitializating(CHttpUrl("google.com", "testpage/", Protocol::HTTPS, 333)
				, Protocol::HTTPS
				, "google.com"
				, 333
				, "/testpage/"
				, "https://google.com:333/testpage/");
		}	
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(failed_initialize_when)
		BOOST_AUTO_TEST_CASE(wrong_protocol)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("//google.com"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl("ftp://google.com/"), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(wrong_domain)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("http://goo gle.com/"), std::invalid_argument);
			BOOST_REQUIRE_THROW(CHttpUrl("http://"), std::invalid_argument);
		}
		BOOST_AUTO_TEST_CASE(wrong_port)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("http://google.com:  /test"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl("http://google.com:-10/"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl("http://google.com:port/"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl("google.com", "/test/", Protocol::HTTP, 0), std::invalid_argument);
			BOOST_REQUIRE_THROW(CHttpUrl("http://google.com:65536"), CUrlParsingError);
			BOOST_REQUIRE_THROW(CHttpUrl("http://google.com:73124"), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(wrong_document)
		{
			BOOST_REQUIRE_THROW(CHttpUrl("http://google.com:333/test page/"), std::invalid_argument);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()