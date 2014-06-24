#include<iostream>
using namespace std;

int main()
{
    int n,sum=0,factorial=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        factorial*=i;
        factorial%=1000000;
        sum+=factorial;
        sum%=1000000;
    }
    cout<<"Time use"<<(double)clock()/CLOCKS_PER_SEC<<endl;
    cout<<sum<<endl;
    return 0;
}
