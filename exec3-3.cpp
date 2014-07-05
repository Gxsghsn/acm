#include<stdio.h>
#include<string.h>
//#include<ctype.h>

int main()
{
    freopen("exec3-3.in","rb",stdin);
    int a=0,b=0,c=0;
    char s[10];
    char t;
//
//    while(scanf("%c",&t)!='\0')
//        printf("%c",t);
//




    scanf("%s",&s);
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a*=10;
            a+=(int)s[i]-48;
        }
        i++;
    }



    scanf("%s",&s);
    i=0;
    while(s[i]!='\0')
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            b*=10;
            b+=(int)s[i]-48;
        }
        i++;
    }


    scanf("%s",&s);
    i=0;
    while(s[i]!='\0')
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            c*=10;
            c+=(int)s[i]-48;
        }
        i++;
    }


    printf("%d\n",112*111*110);
    printf("%d\n",a*b*c%1000);

    return 0;
}
