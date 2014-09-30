// Client.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <windows.h>
#include <winsock.h>
#include <iostream.h>
#pragma comment(lib, "wsock32.lib")


#define CLIENT_EXIT_OK				0	//客户端正常退出
#define CLIENT_DLL_REEOR			1	//调用Windows socket dll失败
#define CLIENT_API_ERROR			2	//调用Windows socket api失败
#define MAX_NUM_BUF					64	//缓冲区的最大长度
#define	SERVERPORT					5555//服务器TCP端口


//变量
char	bufRecv[MAX_NUM_BUF];			//读缓冲区
char	bufSend[MAX_NUM_BUF];			//写缓冲区
SOCKET	sHost;							//socket
BOOL	bConning;						//连接服务器状态

//函数
void	InitMember(void);				//初始化变量
int		ExitClient(int nExit);			//退出
BOOL	RecvLine(SOCKET s, char* buf);	//读取一行数据
void	ShowErrorMsg(void);				//显示错误信息

//主函数
int main()
{

	//初始化变量
	InitMember();

	WORD	wVersionRequested;		//应用程序需要Windows sockets DLL的版本
	WSADATA	wsaData;				//Windows sockets DLL版本信息
	int		retVal;					//调用Windows sockets API返回值

	//初始化Windows Sockets DLL
	wVersionRequested = MAKEWORD(1,1);
	retVal = WSAStartup(wVersionRequested,(LPWSADATA)&wsaData);
	if ( 0 != retVal )
	{
		MessageBox(NULL, "Can not find a usable Windows Sockets dll!", "ERROR", MB_OK);
		return CLIENT_DLL_REEOR;
	}


	//创建Windows socket
	sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(INVALID_SOCKET == sHost)
	{
		ShowErrorMsg();			//显示错误信息
		WSACleanup();			//释放资源
		return CLIENT_API_ERROR;//退出
	}

	//准备连接服务器
	cout << "Client succeeded!" << endl;
	cout<<"Be ready to connect to server..."<<endl;



	//获取主机的信息
	LPHOSTENT hostEntry;
	char hostname[MAX_NUM_BUF];
	gethostname(hostname,MAX_NUM_BUF);			//获取主机名称
	hostEntry = gethostbyname(hostname);		//获取主机信息
	if(!hostEntry)
	{
		ShowErrorMsg();							//显示错误信息
		return ExitClient(CLIENT_API_ERROR);	//退出
	}
	//设置sockaddr_in
	SOCKADDR_IN addrServ;
	addrServ.sin_family = AF_INET;
	addrServ.sin_addr = *((LPIN_ADDR)*hostEntry->h_addr_list);
	addrServ.sin_port = htons(SERVERPORT);
	//连接服务器
	retVal=connect(sHost,(LPSOCKADDR)&addrServ, sizeof(SOCKADDR_IN));
	if(SOCKET_ERROR == retVal)
	{
		ShowErrorMsg();							//显示错误信息
		return ExitClient(CLIENT_API_ERROR);	//退出
	}else{
		bConning = TRUE;						//连接服务器成功
	}
	//连接服务器成功
	cout<<"Connect successfully!"<<endl;


	//向服务器发送数据
	strcpy(bufSend, "Hello, Server!\n");
	retVal = send(sHost, bufSend, strlen(bufSend), 0);
	if (SOCKET_ERROR == retVal)
	{
		ShowErrorMsg();							//显示错误信息
		return ExitClient(CLIENT_API_ERROR);	//退出
	}

	//从服务器接收数据
	if (!RecvLine(sHost, bufRecv))
	{
		ShowErrorMsg();							//显示错误信息
		return ExitClient(CLIENT_API_ERROR);	//退出
	}
	//显示服务器的应答
	cout<<bufRecv<<endl;

	//退出
	return ExitClient(CLIENT_EXIT_OK);
}


/*
 *	显示错误信息
 */
void	ShowErrorMsg(void)
{
	int nErrCode = WSAGetLastError();//获取错误代码

	HLOCAL hlocal = NULL;

	//获取错误的文本字符串
	BOOL fOk = FormatMessage(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER,
		NULL, nErrCode, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
		(PTSTR)&hlocal, 0, NULL);

	//显示错误信息
	if (hlocal != NULL)
	{
		MessageBox(NULL, (char*)LocalLock(hlocal), "CLIENT ERROR", MB_OK);
		LocalFree(hlocal);
	}
}


/*
 *	初始化成员变量
 */
void	InitMember(void)
{
	//初始化读和写缓冲区
	memset(bufRecv, 0, MAX_NUM_BUF);
	memset(bufSend, 0, MAX_NUM_BUF);
	//初始化
	sHost = INVALID_SOCKET;
	//没有连接状态
	bConning = FALSE;
}

/*
 *	退出
 */
int		ExitClient(int nExit)
{
	closesocket(sHost);		//关闭套接字
	WSACleanup();			//卸载Windows sockets DLL 清理内存

		//显示退出信息
	cout << "Client exiting..." << endl;
	Sleep(20000);
	return nExit;	//退出
}


/*
 *	读取一行数据
 */
BOOL	RecvLine(SOCKET s, char* buf)
{
	BOOL	retVal = TRUE;			//返回值
	BOOL	bLineEnd = FALSE;		//行结束
	int		nReadLen = 0;			//读入字节数
	int		nDataLen = 0;			//数据长度
	while (!bLineEnd && bConning)	//与客户端连接 没有换行
	{
		nReadLen = recv(s, buf + nDataLen, 1, 0);//每次接收一个字节
		//错误处理
		if (SOCKET_ERROR == nReadLen)
		{
			retVal= FALSE;	//读数据失败
			break;			//跳出循环
		}

		if (0 == nReadLen)//客户端关闭
		{
			retVal = FALSE;	//读数据失败
			break ;			//跳出循环
		}

		//读入数据
		if ('\n' == *(buf + nDataLen))	//换行符
		{
			bLineEnd = TRUE;			//接收数据结束
		}else{
			nDataLen += nReadLen;		//增加数据长度
		}
	}

	return retVal;
}

//
// struct hostent {
// 	char FAR *			h_name;
// 	char FAR * FAR *	h_aliases;
// 	short				h_addrtype;
// 	short				h_length;
// 	char FAR * FAR *	h_addr_list;
// };

