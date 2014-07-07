#include<iostream>
using namespace std;
int main()
{
    int sum=0;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
        sum+=(int)s[i]-96;
    cout<<sum<<endl;
    return 0;
}
