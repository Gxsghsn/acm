#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{
    FILE *fin;
    fin = fopen("exam3-4-4-2.in","r");
    int n=5,i=0;
    char s[10];
    fgets(s,10,fin);
    printf("%s",s);
    fclose(fin);
    return 0;
}
