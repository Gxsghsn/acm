#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int main()
{
    ofstream ofs("exc2-2.out");
    int x=100;
//    cout<<x/100<<" "<<x/10%10<<" "<<x%10<<endl;
//    cout<<pow(x/100,3)+pow(x/10%10,3)+pow(x%10,3)<<endl;
    while(x<1000)
    {
        if(pow(x/100,3)+pow(x/10%10,3)+pow(x%10,3)==x)
            ofs<<x<<" ";
        x++;
    }
    ofs.close();
    return 0;
}
