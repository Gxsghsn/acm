#include<stdio.h>
//using namespace std;

int main()
{
    char s[100];
    int i=0,n=3;

    while(n>0)
    {
        n--;
        s[i]=getchar();
        if(s[i]=='\n')
            break;
        i++;
        if(n==1)
        {
            s[i]='\0';
            break;
        }
    }

    printf("%s",s);
    return 0;
}
