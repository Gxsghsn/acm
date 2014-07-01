#include<stdio.h>
#include<string.h>

int main()
{
    char s[100];
    char a='b';
    scanf("%s",&s);
    int n = strlen(s),i=0;

    a = getchar();
    a = getchar();

    for(i=0;i<n;i++)
    {
        if(s[i] == a)
        {
            printf("heheh");
            break;
        }
    }

    printf("%s%d",s,i);

    return 0;
}
