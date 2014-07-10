#include<iostream>
#include<memory.h>
using namespace std;
char cangku[2000000000];


int main()
{
    memset(cangku,1,sizeof(cangku));
    freopen("test7.in","r",stdin);
    int testnum,casenum=1;
    cin>>testnum;
    while(testnum>0)
    {
        int n;
        cin>>n;
        cout<<"Case "<<casenum<<":\n";
        casenum++;
        while(n>0)
        {
            string s;
            int m;
            cin>>s>>m;
            m+=1000;
            if(s=="Floor")
            {
                while(cangku[m]==0)
                    m-=1;
                cangku[m]=0;
                cout<<m-1000<<endl;
            }
//            if(s=="Ceiling")
            else
            {
                while(cangku[m]==0)
                    m+=1;
                cangku[m]=0;
                cout<<m-1000<<endl;
            }
            n--;
        }
        testnum--;
    }
    return 0;
}
