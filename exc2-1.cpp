#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    //fstream *fin,*fout;
    ifstream ifs("exc2-1.in");
    ofstream ofs("exc2-1.out");
    //freopen("exc2-1.in","r",stdin);
    //freopen("exc2-1.out","w",stdout);
    int x,n=1;
    ifs>>x;
    while(x>=10)
    {
        x/=10;
        n++;
    }
    ofs<<n<<endl;
    ifs.close();
    ofs.close();
    return 0;
}
