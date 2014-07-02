//#include<iostream>
//#include<string>
//#include<fstream>
//using namespace std;
//
//int main()
//{
//    ifstream fin("exec3-2.in");
//    int n=0,sum=0;
//    string a;
//    while(fin>>a)
//    {
//        n++;
//        sum+=a.length();
//    }
//    cout<<(double)sum/n<<endl;
//}



#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fin;
    int n=0,sum=0;
    fin = fopen("exec3-2.in","rb");
    char s[10];
//    fscanf(fin,"%s",&s);
//    printf("%s ",s);
//    fscanf(fin,"%s",&s);
//    printf("%s ",s);
//    fscanf(fin,"%s",&s);
//    printf("%s ",s);
//    fscanf(fin,"%s",&s);
//    printf("%s ",s);
    while(fscanf(fin,"%s",&s)!=EOF)
    {
//        printf("%s\n",s);
        n++;
        sum += strlen(s);
    }
    printf("%d\n",n);
    printf("%f",(double)sum/n);
    fclose(fin);
    return 0;
}
