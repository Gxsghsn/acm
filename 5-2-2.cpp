#include<iostream>
#include<memory.h>
using namespace std;
const int maxn=3000;
int f[maxn];
int f1[maxn];

int main()
{
    memset(f,0,sizeof(int)*maxn);
//    memset(f1,0,sizeof(int)*3000);
    f[0]=1;
    int num;
    cin>>num;
//    for(int i=1;i<=num;i++)
//    {
//        int subsript=0;
//        while(subsript<2996)
//        {
//            int a=f[subsript]*i;
//            int b=0;
//            while(a>=1)
//            {
//                f1[subsript+b]+=a%10;
//                a/=10;
//                b++;
//            }
//            subsript++;
//        }
//        for(int j=0;j<3000;j++)
//            f[j]=f1[j];
//    memset(f1,0,sizeof(int)*3000);
//    }


    for(int i=2;i<=num;i++)
    {
        int c=0;
        for(int j=0;j<maxn;j++)
        {
            int s = i*f[j]+c;
            f[j]=s%10;
            c=s/10;
        }
    }



    int i=3000;
    for(;f[i]==0;i--){}
    for(int j=i;j>=0;j--)
        cout<<f[j];
    cout<<endl;
    return 0;
}
