#include<stdio.h>


int main()
{
    FILE *fin;
    fin = fopen("exec3-4.in","r");
    int a,b;
    char c;


    fscanf(fin,"%d",&a);
//    while(fscanf(fin,"%c",&c) && c=='\t'){}
    while((c = fgetc(fin)) == ' '|| c == '\t'){}
    fscanf(fin,"%d",&b);

    if(c=='+')
        printf("%d",a+b);
    if(c=='-')
        printf("%d",a-b);
    if(c=='*')
        printf("%d",a*b);
    if(c=='/')
        printf("%f",(double)a/b);
    fclose(fin);
    return 0;
}
