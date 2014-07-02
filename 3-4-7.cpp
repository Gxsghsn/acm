//#include<iostream>
//#include<fstream>
//using namespace std;
//
//int main()
//{
//    ofstream fout("3-4-7.out");
//    int n=0,h=0;
//    while(h<1000)
//    {
//        n=0;
//        while(n<10000)
//        {
//            fout<<"a";
//            n++;
//        }
//        fout<<"\n";
//        h++;
//    }
//    return 0;
//}




//fstream 0.13s
//freopen 0.6s
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
using namespace std;

int main()
{
    freopen("3-4-7.out","r",stdin);
//    ifstream fin("3-4-7.out");
    string s;
    while(cin>>s)
        cout<<s<<endl;
    cout<<(double)clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}


//
////freopen 0.44s
////fileopen 0.46s
//#include<time.h>
//#include<cstdio>
//using namespace std;
//
//int main()
//{
////    FILE *fin;
////    fin = fopen("3-4-7.out","rb");
//    freopen("3-4-7.out","r",stdin);
//    int ch;
//    while((ch = getchar())!=EOF)   putchar(ch);
//    printf("time used = %lf\n",(double)clock()/CLOCKS_PER_SEC);
////    fclose(fin);
//    return 0;
//}
//



////fileopen    0.11
////freopen   0.12
//#include<time.h>
//#include<cstdio>
//using namespace std;
//#define MAXN 100010
//char s[MAXN];
//
//int main()
//{
//    FILE *fin;
//    fin = fopen("3-4-7.out","rb");
////    freopen("3-4-7.out","r",stdin);
//    int ch;
//    while(fgets(s,MAXN,fin) != NULL)
//        puts(s);
//    printf("%lf",(double)clock()/CLOCKS_PER_SEC);
//    fclose(fin);
//    return 0;
//}
