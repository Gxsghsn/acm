#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("fanhao.txt","r",stdin);
//    freopen("fanhao1.txt","w",stdout);
    char c[20];
    string s;
    while(gets(c)!=NULL){
        if(c[0]>='A'&& c[0]<='z')
            cout<<c<<endl;
//        cout<<c<<endl;
    }
    return 0;
}
