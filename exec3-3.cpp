#include<stdio.h>
#include<string.h>
//#include<ctype.h>

int main()
{
    freopen("exec3-3.in","rb",stdin);
    int a=0,b,c=111;
    char s;

    while(scanf("%c",&s))
    {
        if(s>='0' && s<='9')
        {
            a*=10;a+=(int)s-48;
        }
    }

    printf("%d",a);

    return 0;
}
