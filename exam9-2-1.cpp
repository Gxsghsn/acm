#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
#define n 10
int G[n][n];
int d[n];

int dp(int a){
    int &ans = d[a];
    if(ans>0) return ans;

    for(int i=0;i<n;i++){
        if(G[i][a]){
            ans=max(ans,dp(i)+1);
        }
    }
    return ans;
}


int print_ans(int a){
    printf("%d",a);
    for(int i=0;i<n;i++){
        if(d[i]==d[a]-1){
            print_ans(i);
            break;
        }
    }
    return 0;
}

int main()
{
    memset(G,0,sizeof(G));
    memset(d,0,sizeof(d));
    freopen("exam9-2.txt","r",stdin);
    char s[20];
    while(scanf("%s",&s)!=EOF){
        int a,b,c;
        sscanf(s,"(%d,%d,%d)",&a,&b,&c);
        G[a][b]=c;
    }
    dp(4);
    print_ans(4);
    return 0;
}
