#include<iostream>
#include<fstream>
using namespace std;
#define ofs cout
int main()
{
    freopen("exc2-4.out","w",stdout);
    //ofstream ofs("exc2-4.out");
    int n;
    cin>>n;
    int nostar=2*n-1,i=0;
    for(int j=0;j<=n;j++)
    {
        for(i=0;i<j+1;i++)
            ofs<<" ";
        for(nostar=2*n-1-2*j;nostar>0;nostar-=1)
            ofs<<"*";
        ofs<<endl;
    }
//    ofs.close();
    return 0;
}
