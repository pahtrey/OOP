#pragma once
#include "stdafx.h"
#include "UrlParsingError.h"

const unsigned short HTTP_DEFAULT_PORT = 80;
const unsigned short HTTPS_DEFAULT_PORT = 443;
const unsigned short MIN_PORT_VALUE = 1;
const unsigned short MAX_PORT_VALUE = 65535;

enum class Protocol
{
	HTTP = 80,
	HTTPS = 443
};

class CHttpUrl
{
public:
	CHttpUrl(std::string const & url);

	CHttpUrl(
		std::string const & domain,
		std::string const & document,
		Protocol protocol = Protocol::HTTP);

	CHttpUrl(
		std::string const & domain,
		std::string const & document,
		Protocol protocol,
		unsigned short port);

	std::string GetUrl() const;
	std::string GetDomain() const;
	std::string GetDocument() const;
	Protocol GetProtocol() const;
	unsigned short GetPort() const;

	std::string static ProtocolToString(Protocol protocol);
private:
	std::string static ParseProtocolFromUrl(std::string const & url);
	std::string static ParseDomainFromUrl(std::string const & url);
	unsigned static ParsePortFromUrl(std::string const & url);
	std::string static ParseDocumentFromUrl(std::string const & url);
	Protocol static StringToProtocol(std::string const & protocol);

	std::string m_domain;
	std::string m_document = "/";
	Protocol m_protocol = Protocol::HTTP;
	unsigned short m_port = 80;
};