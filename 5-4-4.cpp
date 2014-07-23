#include<iostream>
using namespace std;

int main()
{
    //dingdian  n+for(int i=1;i<n-3;i++){i*(n-2-i);}/2
    //bian   (for(int i=1;i<=n-3;i++){(n-2-i)*i;}+n-3)*n/2;
    int n;
    cin>>n;
    int dian=0;
    for(int i=1;i<=n-3;i++){dian+=i*(n-2-i);}
    dian*=n;dian/=4;dian+=n;
//    cout<<dian<<endl;

    int bian=0;
    for(int i=1;i<=n-3;i++){bian+=(n-2-i)*i;}
    bian+=n-3;
    bian*=n;bian/=2;bian+=n;
//    cout<<bian<<endl;

    cout<<2-dian+bian+n-1<<endl;
    return 0;
}
