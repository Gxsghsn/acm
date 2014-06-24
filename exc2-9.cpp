#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

int main()
{
    int a,b,c;
    ifstream fin("exc2-9.in");
    fin>>a>>b>>c;
    cout<<fixed<<setprecision(c)<<(double)a/b<<endl;
    //printf("%.*f",c,(double)a/b);
    fin.close();
    return 0;
}
