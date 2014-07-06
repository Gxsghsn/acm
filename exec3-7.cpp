#include<stdio.h>

int main()
{
    int b,n,sum=0,i=0,nl;
    scanf("%d%d",&b,&n);
    while(n>0)
    {
        nl = n%10;
        for(int j=i;j>0;j--)
            nl*=b;
        sum += nl;
        n /= 10;
        i++;
    }

    printf("%d\n",sum);
}
