#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define MAXLEN 100

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int cmp1(const void *a,const void *b )
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int num[MAXLEN];
    srand((unsigned)time(NULL));
    for(int i=0;i<MAXLEN;i++)
        num[i]=random()%100;
    qsort(num,MAXLEN,sizeof(num[0]),cmp);
    for(int i=0;i<MAXLEN;i++)
        cout<<num[i]<<" ";
    return 0;
}
