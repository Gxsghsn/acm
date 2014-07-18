#include<iostream>
using namespace std;
int c=0;

int  f()
{
//    int c=0;
    return c++;
}

int g()
{
    return c++;
}

int h()
{
    return c++;
}

int main()
{
    int i=0;
//    cout<<++i<<++i<<++i<<endl;
    cout<<f()+g()+h()<<endl;
    cout<<f()+(g()+h())<<endl;
//    cout<<f()<<endl;
    return 0;
}
