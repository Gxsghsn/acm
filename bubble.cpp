//41.88s
//int num[100000]

#include<iostream>
//#include<random>
#include<cstdlib>
#include<memory.h>
#include<time.h>
using namespace std;
#define MAXLEN 100000
int num[MAXLEN];

int main()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<MAXLEN;i++)
        num[i]=random();

    int temp,flag=1;
    while(flag==1)
    {
        flag=0;
        for(int i=0;i<MAXLEN-1;i++)
            if(num[i]>num[i+1])
            {
                flag=1;
                temp=num[i];num[i]=num[i+1];num[i+1]=temp;
            }
//                exchange(num[i],num[i+1]);
    }
    for(int i=0;i<MAXLEN;i++)
        cout<<num[i]<<" ";

    cout<<"\n"<<(double)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
