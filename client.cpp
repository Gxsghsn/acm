#define BUF_SIZE 64
#include <cstdio>
#include "winsock2.h"
#pragma comment(lib,"ws2_32.lib")

int main()
{
	WSADATA wsd;
	int retval;
	SOCKADDR_IN servAddr;
	char buf[BUF_SIZE];
	SOCKET sHost;

	if (WSAStartup(MAKEWORD(2,2),&wsd)!=0)
	{
		printf("WSAStartup failed\n");
		return -1;
	}

	sHost=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sHost==INVALID_SOCKET){
		printf("socket failed\n");
		WSACleanup();
		return -1;
	}

	servAddr.sin_family=AF_INET;
	servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servAddr.sin_port=htons((short)4999);
	int nServAddlen=sizeof(servAddr);

	retval=connect(sHost,(LPSOCKADDR)&servAddr,sizeof(servAddr));
	if(retval==SOCKET_ERROR){
		printf("connect failed!\n");
		closesocket(sHost);
		WSACleanup();
		return -1;
	}


	ZeroMemory(buf,BUF_SIZE);
	strcpy(buf,"big than big");

	retval=send(sHost,buf,strlen(buf),0);
	if(retval==SOCKET_ERROR){
		printf("send failed!");
		closesocket(sHost);
		WSACleanup();
		return -1;
	}

	closesocket(sHost);
	WSACleanup();
	return 0;
}


