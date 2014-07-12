//越界
//int num[100000]

#include<iostream>
#include<cstdlib>
#include<memory.h>
#include<time.h>
#include<math.h>
using namespace std;
#define MAXLEN 100000
int a[MAXLEN];
int b[9][MAXLEN];

void clearb(int b[9][MAXLEN])
{
    for(int i=0;i<=9;i++)
        for(int j=0;j<MAXLEN;j++)
            b[i][j]=0;
}

void numsort(int a[MAXLEN],int b[9][MAXLEN])
{
    int k=0;
    for(int i=0;i<=9;i++)
    {
        for(int j=1;j<=b[i][0];j++)
        {
            a[k] = b[i][j];
            k++;
        }
    }
}


void bucket(int a[MAXLEN],int b[9][MAXLEN])
{
    int max=0;
    for(int i=0;i<MAXLEN;i++)
    {
        if(a[i]>max)
            max = a[i];
    }

    int maxlen=0;
    while(max>=1)
    {
        max/=10;
        maxlen++;
    }

    int d=10;
    clearb(b);
    for(int i=1;i<=maxlen;i++)
    {
        for(int j=0;j<MAXLEN;j++)
        {
            int n=(a[j]%d)/(d/10);
            int l=++b[n][0];
            b[n][l]=a[j];
        }

        d*=10;
        numsort(a,b);

        clearb(b);
    }
}




int main()
{
    int max=0;
    srand((unsigned)time(NULL));
    for(int i=0;i<MAXLEN;i++)
        a[i]=random();

    cout<<endl;
    bucket(a,b);

    cout<<"time "<<(double)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
