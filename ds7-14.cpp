#include <iostream>
#include <cstdio>
using namespace std;

int map[100][100]={0};
int start,tar;
int node[100]={0};
int maxnum=0;

int dfs(int a)
{
    if(a==tar) return 1;
    for(int i=0;i<maxnum;i++){
        if(map[a][i] && node[i]){
            node[i]=0;
            if(dfs(i)){
                printf("%d ",i);
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    memset(map,0,sizeof(map));
    freopen("ds7-14.txt","r",stdin);

    cin>>start>>tar;
    char s[100];
//    getchar();
    gets(s);
    sscanf(s,"%d %d",&start,&tar);
//    getchar();
    while(gets(s)){
        if(s[0]=='\0') break;
        int a,b;
        sscanf(s,"(%d,%d)",&a,&b);
//        printf("%d,%d",a,b);
        map[a][b]=1;
//        map[b][a]=1;
        maxnum>?=a>?b;
    }


    for(int i=0;i<maxnum;i++){
        node[i]=1;
    }

    node[start]=0;
    if(!dfs(start)){
        printf("no path\n");
    }
    return 0;
}
