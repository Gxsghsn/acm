#include<iostream>
using namespace std;

int main()
{
    int testnum;
    cin>>testnum;
    while(testnum>0)
    {
        int pn;
        cin>>pn;
        int sum=0;
        while(pn>0)
        {
            int a,b,c;
            cin>>a>>b>>c;
            sum+=a*c;
            pn--;
        }
        cout<<sum<<endl;
        testnum--;
    }
    return 0;
}
