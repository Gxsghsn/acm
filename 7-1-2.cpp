#include<iostream>
#include<math.h>
using namespace std;
int n=0,num[18];

int maxnum()
{
    int maxnum=num[0];
    int maxnumindex=0;
    for(int i=1;i<n;i++){
        if(abs(num[i])>abs(maxnum)){
            maxnum=num[i];
            maxnumindex=i;
        }
    }
    num[maxnumindex]=0;
    return maxnum;
}


int main()
{
    freopen("7-1-2.txt","r",stdin);
    long long sum=1;
    int a=1;
    int negative1=0,negative2;
    while(cin>>num[n]){
        n++;
    }

    for(int i=0;i<n;i++) cout<<num[i]<<" ";
    cout<<endl;

    int b=0;
    while(b<n){
        b++;
        int a=maxnum();

        if(abs(a)<=1) break;
        if(a<0 && negative1<0) {sum*=(a*negative1);negative1=0;}
        if(a<0 && negative1==0) {negative1=a;}
        if(a>0) sum*=a;
    }

    if(negative1<0){
        while(b<n){
            b++;
            int a=maxnum();
            if(a<0) break;
        }
        if(b<n)
            if(negative1*a>1) sum*=(negative1*a);
    }

    cout<<sum<<endl;
    return 0;
}
