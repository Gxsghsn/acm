#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int max=a;
    if(b>max) max=b;
    if(c>max) max=c;
//    cout<<max;
    a*a+b*b+c*c-2*max*max==0?cout<<"yes":cout<<"no";
    return 0;
}
