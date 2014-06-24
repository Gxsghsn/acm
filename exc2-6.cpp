#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
    ifstream fin("exc2-6.in");
    ofstream fout("exc2-6.out");
    int n;
    double sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        sum += 1.0/i;
    //cout<<setiosflags(ios::fixed)<<setprecision(3)<<sum<<endl;
    fout<<setiosflags(ios::fixed)<<setprecision(3)<<sum<<endl;
    fin.close();
    fout.close();
    return 0;
}
