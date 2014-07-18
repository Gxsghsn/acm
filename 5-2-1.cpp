#include<iostream>
using namespace std;

int main()
{
    int n1,n2;
    while(cin>>n1>>n2&&n1!=0&&n2!=0)
    {
        int shuchu=0,parameter=1,flag = 0;
        while(parameter<=n1&&parameter<=n2){
            parameter*=10;
            flag = n1%(parameter*10)/parameter+n2%(parameter*10)/parameter+flag>=10?1:0;
            shuchu+=flag;
        }
        cout<<shuchu<<endl;
    }

    return 0;
}
