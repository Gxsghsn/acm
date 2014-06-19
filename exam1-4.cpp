#include<iostream>
using namespace std;

int main()
{
    int heads,legs;
    cin>>heads>>legs;
    int rabbits = (legs-heads*2)/2;
    cout<<rabbits<<" "<<heads-rabbits<<endl;
}
