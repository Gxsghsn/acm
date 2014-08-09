#include<iostream>
using namespace std;

int main()
{
    int k,a,b;
    cin>>k;
//    cout<<1.0/k<<endl;
//    cout<<1.0/84+1.0/14<<endl;
    for(int i=k+1;i<=2*k;i++)
        for(int j=i;j<=k*(k+1);j++)
            if((int)((1.0/i+1.0/j)*10000)==(int)((1.0/k)*10000))
                cout<<"1/"<<k<<"="<<"1/"<<j<<"+1/"<<i<<endl;
    return 0;
}
