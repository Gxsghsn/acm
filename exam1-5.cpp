#include<iostream>
using namespace std;

int main()
{
    int a,b,c,t;
    cin>>a>>b>>c;
//    if(a>b)
//        if(a>c)
//            if(b>c)
//                cout<<a<<b<<c;
//            else
//                cout<<a<<c<<b;
//        else
//            cout<<c<<a<<b;
//    else
//        if(b>c)
//            if(a>c)
//                cout<<b<<a<<c;
//            else
//                cout<<b<<c<<a;
//        else
//            cout<<c<<b<<a;
    if(a<b){t=a;a=b;b=t;}
    //a>b
    if(b<c){t=b;b=c;c=t;}
    if(a<b){t=a;a=b;b=t;}
    cout<<a<<b<<c;
    return 0;
}
