#include <iostream>
#define BUF_SIZE 64
#include "winsock2.h"
#pragma comment(lib,"ws2_32.lib")

int main()
{
	WSADATA wsd;
	SOCKET sServer,sClient;
	SOCKADDR_IN	addrServ;
	char buf[BUF_SIZE];
	int retval;


	if(WSAStartup(MAKEWORD(2,2),&wsd)!=0){
		printf("WSAStartup failed");
		return 1;
	}

	sServer = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sServer==INVALID_SOCKET){
		printf("socket failed!");
		WSACleanup();
		return -1;
	}	

	addrServ.sin_family=AF_INET;
	addrServ.sin_port=htons(4999);
	addrServ.sin_addr.s_addr=INADDR_ANY;

	retval=bind(sServer,(LPSOCKADDR)&addrServ,sizeof(SOCKADDR_IN));
	if(SOCKET_ERROR==retval){
		printf("bind failed");
		closesocket(sServer);
		WSACleanup();
		return -1;
	}



	retval = listen(sServer,1);
	if(SOCKET_ERROR==retval){
		printf("listen failed!\n");
		closesocket(sServer);
		WSACleanup();
		return -1;
	}
	sockaddr_in addrClient;
	int addrClientlen = sizeof(addrClient);
	sClient = accept(sServer,(sockaddr FAR*)&addrClient,&addrClientlen);
	if(sClient==INVALID_SOCKET){
		printf("accept failed\n");
		closesocket(sServer);
		WSACleanup();
		return -1;
	}

	ZeroMemory(buf,BUF_SIZE);
	retval = recv(sClient,buf,BUF_SIZE,0);
	if(retval==SOCKET_ERROR){
		printf("recv failed\n");
		closesocket(sServer);
		closesocket(sClient);
		WSACleanup();
		return -1;
	}
	printf("%s\n",buf);

	closesocket(sServer);
	closesocket(sClient);
	WSACleanup();
	return 0;

}
