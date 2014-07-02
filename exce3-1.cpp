#include<fstream>
#include<iostream>
using namespace std;

int main()
{
    int a[100][2];
    int num;

    //initiallze
    for(int i=0;i<100;i++)
        for(int j=0;j<2;j++)
            a[i][j]=0;

    ifstream  fin("exce3-1.in");

//    for(int i=0;i<100;i++)
//        a[i][0];

    while(cin>>num)
        a[num][1]++;


    for(int i=0;i<100;i++)
//        for(int j=0;j<2;j++)
            cout<<a[i][1];

    return 0;
}
