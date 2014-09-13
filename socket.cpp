//1.cpp:
#pragma comment(lib,"wsock32.lib")
#include<stdio.h>
#include<string.h>
#include<winsock.h>
#include <windows.h>
void initial();
int InitSockets(void);
void GetArgments(int argc,char **argv);
void ErrorPrint(char *x);
void userHelp();
int LoopControl(SOCKET listenfd,int isMultiTasking);
void Service(LPVOID lpv);
#define MAX_SER 10
char *hostName;
unsigned short maxService;
unsigned short port;


char tolower(char a)
{
    return a>'A'?(char)a-'a':a;
}


int serverNum=0;
struct LoginUser
{
	char name[10];
	SOCKET acceptfd;
	bool online;
};
int lognum=0;
LoginUser *loginuser;
void initial()
{
	hostName="127.0.0.1";
	maxService=3;
	port=9999;
}
int InitSockets(void)
{
	WSADATA wsaData;
	WORD sockVersion;
	int err;
	sockVersion=MAKEWORD(2,2);
	err=WSAStartup(sockVersion,&wsaData);
	if(err!=0)
	{
		printf("Error %d:Winsock not avaliable\n",err);
		return 1;
	}
	return 0;
}
void GetArgments(int argc,char **argv)
{
	int i;
	for(i=1;i<argc;i++)
	{
		if(argv[i][0]=='-')
		{
			switch(tolower(argv[i][1]))
			{
			case 'p':
				if(strlen(argv[i])>3)
					port=atoi(&argv[i][3]);
				break;
			case 'h':
				hostName=&argv[i][3];
				break;
			case 'n':
				maxService=atoi(&argv[i][3]);
				break;
			default:
				userHelp();
				break;
			}
		}
	}
	return;
}
void ErrorPrint(char *x)
{
	printf("Error %d: %s\n",WSAGetLastError(),x);
}
void userHelp()
{
	printf("userHelp: -h:str -p:int -n:int\n");
	printf("-h:str The host name\n");
	printf("The default host is 127.0.01\n");
	printf("-p:int The port number to use\n");
	printf("The default port is 9999\n");
	printf("-n:int The number of service,below MAX_SER\n");
	printf("The default number is 3\n");
	ExitProcess(-1);
}
struct sockaddr_in clientAddr;
int LoopControl(SOCKET listenfd,int isMultiTasking)
{

	SOCKET acceptfd;
	int err,i;
	int nSize;
	HANDLE handles[MAX_SER];
	int myID;
	loginuser=new LoginUser[maxService];
	while(serverNum<maxService)
	{
		i=serverNum;
		nSize=sizeof(clientAddr);
		acceptfd=accept(listenfd,(struct sockaddr *)&clientAddr,&nSize);
		if(acceptfd==INVALID_SOCKET)
		{
			ErrorPrint("Error: accept failed\n");
			return 1;
		}
		printf("Accepted the %d connection from client at %s:%d\n",i+1,inet_ntoa(clientAddr.sin_addr),htons(clientAddr.sin_port));
			if(isMultiTasking)
			{
					handles[serverNum]=CreateThread(NULL,1000,(LPTHREAD_START_ROUTINE)
					Service,(LPVOID) acceptfd,0,(unsigned long *)&myID);
			}
			else
			{
				Service((LPVOID)acceptfd);
			}
			serverNum++;
	}
	if(isMultiTasking)
	{
		err=WaitForMultipleObjects(maxService,handles,TRUE,INFINITE);

		printf("Last thread to finish was thread #%d\n",err);
	}
	return 0;
}
void stringExchange(char *a)
{
	char temp;
	int i,len=strlen(a);
	for(i=0;i<len/2;i++)
	{
		temp=a[i];
		a[i]=a[len-i-1];
		a[len-i-1]=temp;
	}
}
void getclientip(char *ip,int port,char *msg)
{
	char exchtemp;
	int i=0,j=0,temp=port;
	for(i=0;i<(int)strlen(ip);i++)
	{
		msg[i]=ip[i];
	}
	msg[i]='#';
	i++;
	j=i;
	for(;temp>0;)
	{
		msg[i]=temp%10+48;
		i++;
		temp=temp/10;
	}
	msg[i]='\0';
	int n=strlen(msg);
	for(i=j;i<(n-j)/2+j;i++)
	{
		exchtemp=msg[i];
		msg[i]=msg[n-i-1+j];

		msg[n-i-1+j]=exchtemp;
	}
}
void GetLogUseMsg(char *msg)
{
	int i=0,j=0,k;
	msg[j]='*';
	j++;
	for(i=0;i<lognum;i++)
	{
		if(loginuser[i].online==true)
		{
			for(k=0;k<(int)strlen(loginuser[i].name);k++)
			{
				msg[j]=loginuser[i].name[k];
				j++;
			}
			msg[j]='*';
			j++;
		}
	}
	msg[j]='\0';
	j++;
}
void SendLogUseToAll(char *msg)
{
	int i=0;
	for(i=0;i<lognum;i++)
	{
		if(loginuser[i].online==true)
		{
			send(loginuser[i].acceptfd,msg,strlen(msg)+1,0);
		}
	}
}
void GetDestIndex(char *msg,int *index)
{

	int i=0,j=0;
	char buf[20];
	for(i=1;msg[i]!='@';i++)
	{
		buf[j]=msg[i];
		j++;
	}
	buf[j]='\0';
	for(i=0;i<lognum;i++)
	{
		if(loginuser[i].online==true)
		{
			if(strcmp(buf,loginuser[i].name)==0)
			{
				*index=i;
				return;
			}
		}
	}
	*index=-1;
	return;
}
void Service(LPVOID lpv)
{
	SOCKET acceptfd=(SOCKET)lpv;
	char msg[4096],insuser[1024];
	char clientname[10];
	char clientpassword[10];
	char response[4096];
	int loginNum=0;
	int myid=lognum;
	while(loginNum<3)
	{
		memset(response,0,sizeof(response));
		strcpy(msg," please input name:");
		send(acceptfd,msg,strlen(msg)+1,0);

		recv(acceptfd,clientname,sizeof(clientname),0);
		strcpy(msg," please input password:");
		send(acceptfd,msg,strlen(msg)+1,0);
		recv(acceptfd,clientpassword,sizeof(clientpassword),0);
		if(strcmp(clientname,clientpassword)==0)
		{
			strcpy(msg,"connected sucessful.");
			send(acceptfd,msg,strlen(msg)+1,0);
			getclientip(inet_ntoa(clientAddr.sin_addr),htons(clientAddr.sin_port),msg);
			send(acceptfd,msg,strlen(msg)+1,0);
			Sleep(50);
			//strcpy(msg,"hello");
			//send(acceptfd,msg,strlen(msg)+1,0);
			//
			strcpy(loginuser[myid].name,clientname);
			loginuser[myid].acceptfd=acceptfd;
			loginuser[myid].online=true;
			lognum++;
			GetLogUseMsg(msg);
			//printf("!!!%s",msg);
			send(acceptfd,msg,strlen(msg)+1,0);
			SendLogUseToAll(msg);
			printf("%s",msg);
			//
			while(1)
			{
				//char buf1[]="hello";
				// scanf("%s",buf1);
				//send(acceptfd,buf1,1024,0);
				recv(acceptfd,response,sizeof(response),0);
				if(strlen(response)!=0)
				{

					if(strcmp(response,"quit")==0)
					{
						printf("quit!!!");
						strcpy(msg,"connection closed.");
						send(acceptfd,msg,strlen(msg)+1,0);
						loginuser[myid].online=false;
						GetLogUseMsg(msg);
						send(acceptfd,msg,strlen(msg)+1,0);
						SendLogUseToAll(msg);
						goto quit;
					}
					else
					{
						int i;
						GetDestIndex(response,&i);
						if(i==-1)
						{
							printf("error!!!!!!!!!");
						}
						else
						{
							//stringExchange(response);
							send(loginuser[i].acceptfd,response,strlen(response)+1,0);
						}
					}
					printf("%s\n",loginuser[0].name);
					//send(loginuser[0].acceptfd,buf1,10,0);
				}
			}
		}
		loginNum++;
	}
	strcpy(msg,"Error,please check and connect again.");
	send(acceptfd,msg,strlen(msg)+1,0);
quit:
	serverNum--;

	printf("the connection from client at %s:%d quit.now connection number is %d\n",inet_ntoa(clientAddr.sin_addr),htons(clientAddr.sin_port),serverNum);
	closesocket(acceptfd);
}
int main(int argc,char **argv)
{
	SOCKET listenfd;
	int err;
	struct sockaddr_in serverAddr;
	struct hostent *ptrHost;
	initial();
	GetArgments(argc,argv);
	InitSockets();
	listenfd=socket(PF_INET,SOCK_STREAM,0);
	if(listenfd==INVALID_SOCKET)
	{
		printf("Error: out of socket resources\n");
		return 1;
	}
	if(atoi(hostName))
	{
		//number
			u_long ip_addr=inet_addr(hostName);
		ptrHost=gethostbyaddr((char*)&ip_addr,sizeof(u_long),AF_INET);
	}
	else
		ptrHost=gethostbyname(hostName);
	if(!ptrHost)
	{
		ErrorPrint("cannot resolve hostname");
		return 1;
	}
	serverAddr.sin_family=PF_INET;
	serverAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	serverAddr.sin_port=htons(port);
	err=bind(listenfd,(const struct sockaddr *)&serverAddr,sizeof(serverAddr));
	if(err==INVALID_SOCKET)

	{
		ErrorPrint("Error: unable to bind socket\n");
		return 1;
	}
	err=listen(listenfd,SOMAXCONN);
	if(err==INVALID_SOCKET)
	{
		ErrorPrint("Error: listen failed\n");
		return 1;
	}
	LoopControl(listenfd,1);
	printf("Server is down\n");
	WSACleanup();
	return 0;
}

