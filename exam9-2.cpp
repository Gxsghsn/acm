#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
#define n 10
int d[n];
int G[n][n];

int dp(int i){
//    cout<<"a"<<endl;
    int &ans = d[i];
    if(ans>0) return ans;
    ans = 0;
    for(int j=0;j<n;j++){
        if(G[i][j])
            ans=max(ans,dp(j)+1);
    }
    return ans;
}

void print_ans(int i){
    printf("%d",i);
    for(int j=0;j<=n;j++){
        if(G[i][j] && d[i]==d[j]+1){
            print_ans(j);
            break;
        }

    }
}


int main()
{
    freopen("exam9-2.txt","r",stdin);
//    cout<<"heh"<<endl;
    memset(d,0,sizeof(d));
    memset(G,0,sizeof(G));
    char s[50];
    while(scanf("%s",s)!=EOF){
//        cout<<s<<endl;
        int a,b,c;
        sscanf(s,"(%d,%d,%d)",&a,&b,&c);
        G[a][b]=c;
//        cout<<a<<b<<c<<endl;
    }
    cout<<dp(0)<<endl;
    print_ans(0);
    return 0;
}
