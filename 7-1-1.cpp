#include<iostream>
#include<iomanip>
using namespace std;

bool judge(int divid,int n)
{
    int digit[10]={0};
    for(int i=divid,count=0;count<5;i/=10,count++){
        digit[i%10]++;
    }
    for(int i=n*divid;i>0;i/=10){
        digit[i%10]++;
    }
    for(int i=0;i<10;i++)
        if(digit[i]!=1)
            return false;
    return true;
}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<99999;i++){
        if(judge(i,n))
            printf("%d/%05d=%d\n",i*n,i,n);
    }
    return 0;
}
