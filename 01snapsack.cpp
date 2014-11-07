#include <iostream>  
#include <cstdio>
#define min(a,b)(a<b?a:b)
#define max(a,b)(a>=b?a:b)
using namespace std;   
int m[500][500];   
int x[500];   

void Knapsack(int *v,int *w,int c,int n)   
{ 
    int j;
    int jMax=min(w[n]-1,c);   
    for(j=0;j<=jMax;j++) m[n][j]=0;   
    for(j=w[n];j<=c;j++) m[n][j]=v[n];   
    for(int i=n-1;i>1;i--)   
    {
        jMax=min(w[i]-1,c);   
        for(j=0;j<=jMax;j++) m[i][j]=m[i+1][j];   
        for(j=w[i];j<=c;j++) m[i][j]=max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
    }   
    m[1][c]=m[2][c];   
    if(c>=w[1]) m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);   
}   
  
void Traceback(int *w,int c,int n,int *x)   
{   
    for(int i=1;i<n;i++)   
    {
        if(m[i][c]==m[i+1][c]) x[i]=0;   
        else    
        {
            x[i]=1;   
            c-=w[i];   
        }
    }   
    x[n]=(m[n][c])?1:0;   
}   
       
int main()   
{   
    freopen("01.in","r",stdin);
    int n,c,T=20,a=1,i;   
    int v[500],w[500];   
    while(cin>>n){
        int bestv=0;   
        cin>>c;
        for(i=1;i<=n;i++){   
            cin>>v[i];   
        }   
        for(i=1;i<=n;i++){   
            cin>>w[i];   
        }   
        Knapsack(v,w,c,n);   
        Traceback(w,c,n,x);   
        for(i=1;i<=n;i++){   
            if(x[i]==1) bestv+=v[i];   
        }   
        cout<<"Case "<<a<<endl;   
        a++;   
        cout<<bestv<<" ";   
        for(i=1;i<=n;i++)   
            cout<<x[i];   
           
        cout<<endl;   
    }   
    return 0;   
}  