<<<<<<< HEAD
#include<iostream>
//#include<stack>
using namespace std;

int p[100];
int pare[100];
int node[100];
int map[100][100];
int front=0;
int rear=0;
int start,tar;
int maxnum;

int bfs()
{
    while(front<rear){
        if(p[front]==tar){
//            printf("find\n");
            return 1;
        }
        for(int i=0;i<=maxnum;i++){
            if(map[p[front]][i]){
               p[rear++]=i;
               pare[rear-1]=i;
            }
        }
        front++;
    }
    printf("no path\n");
    return 0;
}



int main()
{
    memset(map,0,sizeof(map));
    freopen("7-16.txt","r",stdin);
    char s[100];
    gets(s);
    sscanf(s,"%d %d",&start,&tar);
//    cout<<start<<tar<<endl;
    while(gets(s)){
        if(s[0]=='\0') break;
        int a,b;
        sscanf(s,"(%d,%d)",&a,&b);
        map[a][b]=1;
        maxnum>?=a>?b;
    }


    for(int i=0;i<maxnum;i++){
        node[i]=1;
    }

    p[rear++]=start;
    pare[0]=0;
    node[start]=0;
    int a=bfs();


    while(pare[a]!=0){
        printf("%d ",a);
        a=pare[a];
    }

    return 0;
}
=======
#include<iostream>
//#include<stack>
using namespace std;

int p[100];
int pare[100];
int node[100];
int map[100][100];
int front=0;
int rear=0;
int start,tar;
int maxnum;

int bfs()
{
    while(front<rear){
        if(p[front]==tar){
//            printf("find\n");
            return 1;
        }
        for(int i=0;i<=maxnum;i++){
            if(map[p[front]][i]){
               p[rear++]=i;
               pare[rear-1]=i;
            }
        }
        front++;
    }
    printf("no path\n");
    return 0;
}



int main()
{
    memset(map,0,sizeof(map));
    freopen("7-16.txt","r",stdin);
    char s[100];
    gets(s);
    sscanf(s,"%d %d",&start,&tar);
//    cout<<start<<tar<<endl;
    while(gets(s)){
        if(s[0]=='\0') break;
        int a,b;
        sscanf(s,"(%d,%d)",&a,&b);
        map[a][b]=1;
        maxnum>?=a>?b;
    }


    for(int i=0;i<maxnum;i++){
        node[i]=1;
    }

    p[rear++]=start;
    pare[0]=0;
    node[start]=0;
    int a=bfs();


    while(pare[a]!=0){
        printf("%d ",a);
        a=pare[a];
    }

    return 0;
}
>>>>>>> eaf31b299a8015ff83c93e41729a950c10b789a0
