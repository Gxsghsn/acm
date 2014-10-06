#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
int n;
//int S[n][n];
int d[100];
int V[100];
int maxv[100];
int minv[100];
#define INF 999999

int dp(int S){
    int& ans = d[S];
    if(ans!=-1) return ans;

    ans=-2;
    for(int i=0;i<n;i++){
        if(S>=V[i]){
            ans=max(ans,dp(S-V[i])+1);
        }
    }
    return ans;
}

int init(int a){
    a=50;
    maxv[0]=0;
    minv[0]=0;
    for(int i=1;i<a;i++){
        maxv[i]=-1*INF;
        minv[i]=INF;
    }

    for(int i=0;i<a;i++)
        for(int j=0;j<n;j++){
            if(i>=V[j]){
                minv[i]=min(minv[i],minv[i-V[j]]+1);
                maxv[i]=max(maxv[i],maxv[i-V[j]]+1);
            }
        }
//    printf("%d\n",a);
//    printf("%d %d\n",maxv[20],minv[20]);
}


int print_ans(int d[],int s){
    printf("%d\n",s);
    for(int i=0;i<n;i++){
        if(s>=V[i] && d[s]==d[s-V[i]]+1)
            print_ans(d,s-V[i]);
    }
    return 0;
}

int main()
{
    memset(V,0,sizeof(V));
    memset(d,-1,sizeof(d));
    freopen("9-2-3.txt","r",stdin);
    cin>>n;
//    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cin>>V[i];
    }
    init(20);
    print_ans(minv,20);
    return 0;
}
