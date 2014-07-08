#include<iostream>
using namespace std;

void swap(int a,int b)
{
    int t=a;a=b;b=t;
}

int main()
{
    int a=3,b=4;
    swap(3,4);
    cout<<a<<b<<endl;
    return 0;
}
