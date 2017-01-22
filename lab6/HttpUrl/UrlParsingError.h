#pragma once
class CUrlParsingError : std::invalid_argument
{
public:
	CUrlParsingError(std::string const & message);
};

