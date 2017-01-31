#include "stdafx.h"
#include "HttpUrl.h"

using namespace std;

int main()
{
	string urlString;

	cout << "Input Urls:" << endl;

	while (getline(cin, urlString))
	{
		try
		{
			CHttpUrl url(urlString);

			cout << "protocol: " << url.ProtocolToString(url.GetProtocol()) << endl;
			cout << "domain: " << url.GetDomain() << endl;
			cout << "document: " << url.GetDocument() << endl;
			cout << "port: " << url.GetPort() << endl;
			cout << "url: " << url.GetUrl() << endl;
		}
		catch (exception const& e)
		{
			cout << e.what() << endl;
		}
		cout << endl;
	}

	return 0;
}