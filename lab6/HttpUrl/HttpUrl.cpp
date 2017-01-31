#include "stdafx.h"
#include "HttpUrl.h"

CHttpUrl::CHttpUrl(std::string const & url)
{
	std::string urlString(url);

	auto protocolString = ParseProtocolFromUrl(urlString);
	m_protocol = StringToProtocol(protocolString);
	urlString = urlString.substr(protocolString.size() + 3);

	m_domain = ParseDomainFromUrl(urlString);
	urlString = urlString.substr(m_domain.size());

	if (urlString[0] == ':')
	{
		m_port = ParsePortFromUrl(urlString);
		urlString = urlString.substr(std::to_string(m_port).size() + 1);
	}
	else
	{
		m_port = (m_protocol == Protocol::HTTP) ? HTTP_DEFAULT_PORT : HTTPS_DEFAULT_PORT;
	}

	m_document = ParseDocumentFromUrl(urlString);
}

CHttpUrl::CHttpUrl(
	std::string const & domain,
	std::string const & document,
	Protocol protocol)
	: m_domain(ParseDomainFromUrl(domain))
	, m_document(ParseDocumentFromUrl(document))
	, m_protocol(protocol)
{
	m_port = (protocol == Protocol::HTTP) ? HTTP_DEFAULT_PORT : HTTPS_DEFAULT_PORT;
}

CHttpUrl::CHttpUrl(
	std::string const & domain,
	std::string const & document,
	Protocol protocol,
	unsigned short port)
	: m_domain(ParseDomainFromUrl(domain))
	, m_document(ParseDocumentFromUrl(document))
	, m_protocol(protocol)
	, m_port(port)
{
	if (port == 0)
	{
		throw std::invalid_argument("Port can not be zero");
	}
}

std::string CHttpUrl::GetUrl() const
{
	auto url = ProtocolToString(m_protocol) +"://" + m_domain;
	if (!((m_protocol == Protocol::HTTP && m_port == HTTP_DEFAULT_PORT)
		|| (m_protocol == Protocol::HTTPS && m_port == HTTPS_DEFAULT_PORT)))
	{
		url += ":" + std::to_string(m_port);
	}
	return url + m_document;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

std::string CHttpUrl::ParseProtocolFromUrl(std::string const & url)
{
	auto end = url.find("://");
	if (end == std::string::npos)
	{
		throw CUrlParsingError("Invalid URL protocol");
	}
	return url.substr(0, end);
}

std::string CHttpUrl::ParseDomainFromUrl(std::string const & url)
{
	auto end = url.find(':');
	if (end == std::string::npos)
	{
		end = url.find("/");
	}
	auto domain = url.substr(0, end);
	if ((domain == "") || (domain.find(' ') != std::string::npos))
	{
		throw std::invalid_argument("Invalid URL domain");
	}
	return domain;
}

unsigned CHttpUrl::ParsePortFromUrl(std::string const & url)
{
	auto end = url.find("/");
	auto portString = url.substr(1, end);

	if (portString.empty() || (portString.find(' ') != std::string::npos))
	{
		throw CUrlParsingError("Invalid URL port");
	}

	signed port = 0;
	try
	{
		port = std::stoi(portString);
	}
	catch (...)
	{
		throw CUrlParsingError("Invalid URL port");
	}

	if (port < MIN_PORT_VALUE || port > MAX_PORT_VALUE)
	{
		throw CUrlParsingError("Invalid URL port");
	}
	return port;
}

std::string CHttpUrl::ParseDocumentFromUrl(std::string const & url)
{
	auto document = (url[0] != '/') ? '/' + url : url;

	if (document.find(' ') != std::string::npos)
	{
		throw std::invalid_argument("Invalid URL document");
	}
	return document;
}

Protocol CHttpUrl::StringToProtocol(std::string const & protocol)
{
	std::string protocolString(protocol);
	std::transform(protocolString.begin(), protocolString.end(), protocolString.begin(), tolower);
	if (protocolString == "http")
	{
		return Protocol::HTTP;
	}
	else if (protocolString == "https")
	{
		return Protocol::HTTPS;
	}
	throw CUrlParsingError("Invalid protocol type");
}

std::string CHttpUrl::ProtocolToString(Protocol protocol) const
{
	return (protocol == Protocol::HTTP) ? "http" : "https";
}