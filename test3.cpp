#include<iostream>
using namespace std;

int main()
{
    int casenum=1,testnum,rating,s;
    cin>>testnum;
    while(testnum>0)
    {
        cin>>rating>>s;
        cout<<"Case "<<testnum<<":\n"<<rating-150-1500/(s+2)<<" "<<rating+150+1500/(s+2)<<endl;;
        testnum--;
    }
    return 0;
}
