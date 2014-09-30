<<<<<<< HEAD
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int map[100][100]={0};
int A;
int maxnum=0;
int start,numend;

int dfs(int a,int now,int *node)
{
    if(now==A && a==numend) return 1;
    if(now>=A) return 0;
    for(int i=0;i<=maxnum;i++){
        if(map[a][i] && node[i]){
            node[i]=0;
            if(dfs(i,now+1,node)) {
                printf("%d ",i);
                return 1;
            }
            node[i]=1;
        }
    }
    return 0;
}


int main()
{
    freopen("ds7-19.txt","r",stdin);

    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            map[i][j]=0;

    int node[100]={0};
    cin>>start>>numend>>A;
//    memset(map,0,sizeof(map));
//    memset(node,0,sizeof(node));
    char s[100];
    getchar();
    while(gets(s)){
        if(s[0]=='\0') break;
        int a,b;
        sscanf(s,"(%d,%d)",&a,&b);
        map[a][b]=1;
        map[b][a]=1;
//        node[a]=1;
//        node[b]=1;
        maxnum>?=a>?b;
    }
    for(int i=0;i<=maxnum;i++) node[i]=1;
    node[start]=0;
    if(!dfs(start,0,node)) printf("no path\n");
    return 0;
}
=======
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int map[100][100]={0};
int A;
int maxnum=0;
int start,numend;

int dfs(int a,int now,int *node)
{
    if(now==A && a==numend) return 1;
    if(now>=A) return 0;
    for(int i=0;i<=maxnum;i++){
        if(map[a][i] && node[i]){
            node[i]=0;
            if(dfs(i,now+1,node)) {
                printf("%d ",i);
                return 1;
            }
            node[i]=1;
        }
    }
    return 0;
}


int main()
{
    freopen("ds7-19.txt","r",stdin);

    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            map[i][j]=0;

    int node[100]={0};
    cin>>start>>numend>>A;
//    memset(map,0,sizeof(map));
//    memset(node,0,sizeof(node));
    char s[100];
    getchar();
    while(gets(s)){
        if(s[0]=='\0') break;
        int a,b;
        sscanf(s,"(%d,%d)",&a,&b);
        map[a][b]=1;
        map[b][a]=1;
//        node[a]=1;
//        node[b]=1;
        maxnum>?=a>?b;
    }
    for(int i=0;i<=maxnum;i++) node[i]=1;
    node[start]=0;
    if(!dfs(start,0,node)) printf("no path\n");
    return 0;
}
>>>>>>> eaf31b299a8015ff83c93e41729a950c10b789a0
