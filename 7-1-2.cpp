#include<iostream>
#include<math.h>
using namespace std;

int maxnum(int num[18])
{
    int maxnum=num[0];
    int maxnumindex=0;
    for(int i=1;abs(num[i]<1000);i++){
        if(abs(num[i])>maxnum){
            maxnum=num[i];
            maxnumindex=i;
        }
    }
    num[maxnumindex]=0;
    cout<<"maxnum"<<maxnum<<endl;
    return maxnum;
}


int main()
{
    freopen("7-1-2.txt","r",stdin);
    long long sum=1;
    int num[18],a;
    int n=0;
    int negative1,negative2;
    while(cin>>num[n]){
        n++;
    }

    while(a=maxnum(num)||abs(a)>1){
        cout<<"a "<<a<<endl;
        sum*=a;
//        cout<<"sum "<<sum<<endl;
    }
    if(sum<0) sum*=maxnum(num);
    cout<<sum<<endl;
    return 0;
}
