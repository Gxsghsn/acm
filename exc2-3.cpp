#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream ifs("exc2-3.in");
    ofstream ofs("exc2-3.out");
    int a,b,c;
    ifs>>a>>b>>c;
    int x=10;
    //cout<<x%3<<x%5<<x%7<<endl;
    while(x%3!=a||x%5!=b||x%7!=c)
    {
        if(x>=100)
        {
            ofs<<"No answer"<<endl;
            return -1;
        }
            x++;
    }
    ofs<<x;
    return 0;
}
