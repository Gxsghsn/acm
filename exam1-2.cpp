#include<iostream>
using namespace std;

int main()
{
    int num;
    cin>>num;
    cout<<num%10<<num/10%10<<num/100<<endl;
    int m = num%10*100+num/10%10*10+num/100;
    cout<<m<<endl;
    return 0;
}

