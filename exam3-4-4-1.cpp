#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char a[10],i=0;


    while(1)
    {
        a[i]=getchar();
        if(a[i]!='\n')
        {
            i++;
        }
        else
            break;
    }

    int len = strlen(a);

    for(int i=0;i<len;i++)
        printf("%c ",a[i]);
//        cout<<a[i]<<" ";
    return 0;
}
