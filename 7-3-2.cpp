#include<iostream>
using namespace std;

void print_subset(int n,int s)
{
    for(int i=0;i<n;i++)
        if(s&&(1<<i)) cout<<i;
    cout<<endl;
}

int main()
{
//    int n=4;
//    cout<<(1<<4)<<endl;
//    for(int i=0;i<(1<<n);i++) print_subset(n,i);
    int a,b,c;
    scanf("%dabc%dabc%d",&a,&b,&c);
    cout<<a<<endl<<b<<endl<<c;
    return 0;
}
