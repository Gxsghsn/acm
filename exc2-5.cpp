#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin("exc2-5.in");
    ofstream fout("exc2-5.out");
    int n,count=0,m;
    fin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        fin>>a[i];
    fin>>m;
    for(int i=0;i<n;i++)
        if(a[i]>m)
            count++;
    fout<<count;
    return 0;
}
