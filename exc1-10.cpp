#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    n%4==0&&n%10!=0?cout<<"yes"<<endl:cout<<"no"<<endl;
    return 0;
}
