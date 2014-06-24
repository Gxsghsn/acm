#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout("exc2-7.out");
    double sum=0,flag;
    int last=1;
    while(1.0/last >= 0.000001)
    {
        last%4==1?flag=1:flag=-1;
        sum += flag*1.0/last;
        last+=2;
    }
    fout<<sum<<endl;
    return 0;
}


