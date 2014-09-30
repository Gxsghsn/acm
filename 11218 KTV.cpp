#include <iostream>
#include <cstdio>
//#define test
using namespace std;
int vis[10];
int num;
int maxs=0;

struct group{
    int a;
    int b;
    int c;
    int d;
}g[100];

void dfs(int cur,int score)
{
    if(cur>=3){
        if(score>maxs)
            maxs=score;
//        maxs>?=score;
        return;
    }
    for(int i=0;i<num;i++){
        if(vis[g[i].a]&&vis[g[i].b]&&vis[g[i].c]){
            vis[g[i].a]=vis[g[i].b]=vis[g[i].c]=0;
            dfs(cur+1,score+g[i].d);
            vis[g[i].a]=vis[g[i].b]=vis[g[i].c]=1;
        }
    }
}



int main()
{
    #ifdef test
        freopen("11218.txt","r",stdin);
    #endif // test
    for(int i=0;i<10;i++)
        vis[i]=1;

    int Case=0;
    while(scanf("%d",&num)&&num){
        maxs=-1;
        for(int i=0;i<num;i++)
            scanf("%d%d%d%d",&g[i].a,&g[i].b,&g[i].c,&g[i].d);
        dfs(0,0);
        printf("Case %d: %d\n",Case++,maxs);
    }
    return 0;
}
