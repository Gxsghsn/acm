#include<stdio.h>
#include<time.h>
#include<string.h>
#define MINLEN 10000000
char s[MINLEN];


int main()
{
    int len,i=0,tot=0;
    while(strlen(s)<1000000)
    {
        s[i]='a';
        s[i+1]='1';
        i++;
        i++;
    }


    for(int j=0;j<strlen(s);j++)
    {
        if(s[j]=='1')
            tot++;
    }

    printf("%d\n",tot);
    printf("%f",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
