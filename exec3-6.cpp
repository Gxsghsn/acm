#include<stdio.h>

int main()
{
    int n,b,i=0,a[10],len=0;
    scanf("%d%d",&n,&b);

    for(int j=0;j<10;j++)
        a[j]=0;

    while(n>0)
    {
        a[i]=n%b;
        len++;
//        printf("%d",n%b);
        n/=b;
        i++;
    }

    for(i=len-1;i>=0;i--)
    {
//        while(flag=0)
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
