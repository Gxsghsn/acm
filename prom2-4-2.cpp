#include<iostream>
using namespace std;

void delay()
{
    int l=0,k=0,p=0,o=0;
    while(l<10000)
    {
        k=0;
        l+=1;
        while(k<10000)
        {
            k+=1;
        }
    }
}
int main()
{
    double i;
    for(i=0;i!=1;i+=0.1)
    {
        printf("%.1lf\n",i);
        delay();
    }
    return 0;
}
