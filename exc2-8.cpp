#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
    ifstream fin("exc2-8.in");
    double n,m;
    double sum;
    fin>>n>>m;
    for(n;n<=m;n++)
        sum += 1.0/(n*n);
    cout<<fixed<<setprecision(5)<<sum<<endl;
    return 0;
}
