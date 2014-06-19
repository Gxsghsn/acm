#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int price = 95*n;
    price>300?cout<<price*0.85<<endl:cout<<price<<endl;
    return 0;
}
