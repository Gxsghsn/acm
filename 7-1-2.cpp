#include<iostream>
#include<math.h>
using namespace std;

int maxnum(int num[18])
{
    int maxnum=num[0];
    int maxnumindex=0;
    for(int i=1;i<18;i++){
        if(abs(num[i])>maxnum){
            maxnum=num[i];
            maxnumindex=i;
        }
    }
    num[maxnumindex]=0;
    return maxnum;
}


int main()
{
    long long sum;
    int num[18];
    int n=0;
    int negative1,negative2;
    while(cin>>num[n]){
        n++;
    }

    for(int i=0;i<18;i++){

    }



    return 0;
}
