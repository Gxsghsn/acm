#include<iostream>
using namespace std;

int f(int n)
{
    int sum=1;
    while(n>1)
    {
        sum*=n;
        n--;
    }
    return sum;
}


int main()
{
    int n,m;
    cin>>n>>m;
//    cout<<f(n)<<endl;
    cout<<f(n)/(f(m)*f(n-m))<<endl;
    return 0;
}
