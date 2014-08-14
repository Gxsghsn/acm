#include<iostream>
using namespace std;
int n;
int C[10],vis[10]={0},isp[20];


int is_p(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return 0;
    return 1;
}

void inp()
{
    for(int i=2;i<2*n;i++) isp[i]=is_p(i);
//    for(int i=0;i<2*n;i++) cout<<isp[i];
//    cout<<endl;
}

void dfs(int cur)
{
    if(cur==n && isp[C[0]+C[n-1]]){
        for(int i=0;i<n;i++) cout<<C[i];
        cout<<endl;
    }
    else{
//        cout<<cur<<"*"<<endl;
        for(int i=2;i<=n;i++){
            if(isp[C[cur-1]+i]&&!vis[i]){
                C[cur]=i;
                vis[i]=1;
                dfs(cur+1);
                vis[i]=0;
            }
        }
    }
}

int main()
{
    C[0]=1;
    n=6;
    inp();
    dfs(1);
    return 0;
}
