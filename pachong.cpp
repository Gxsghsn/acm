#include <fstream>
#include <afx.h>
#include <afxinet.h>

using std::ofstream;
using std::endl;

int main()
{
	CInternetSession session("HttpClient");
	CString urlBase = "http://t.sina.com.cn/";
	DWORD dwStatusCode;

	char buffer[16];
	bool flag=true;
	for (unsigned long i(1);flag;++i)
	{
		CHttpFile *pfile = (CHttpFile *)session.OpenURL(urlBase+_ltoa(i,buffer,10));
		pfile -> QueryInfoStatusCode(dwStatusCode);

		if(dwStatusCode == HTTP_STATUS_OK)
		{
			CString data;
			while (pfile -> ReadString(data))
			{

			}
		}
		else
		{
			flag=false;
		}
		pfile->Close();
		delete pfile;
	}

	session.Close();
	return 0;
}
