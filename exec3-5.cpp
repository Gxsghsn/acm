//#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
//using namespace std;

char s[5];
char a[5][5][5];

int main()
{
    FILE *fin;
//    ifstream fin("exec3-5.in");
    fin=fopen("exec3-5.in","r");
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            fscanf(fin,"%s",a[i][j]);

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            printf("%2s ",a[i][j]);
//        cout<<endl;
        printf("\n");
    }

printf("\n");

    char b[5][5][5];
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            strcpy(b[i][j],a[i][j]);
        }



    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        {
            strcpy(a[i][j],b[j][4-i]);
        }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            printf("%2s ",a[i][j]);
        printf("\n");
    }


//    fin.close();
    fclose(fin);
    return 0;
}
