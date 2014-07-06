#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
        s[i]-=97;
    for(int i=0;i<s.length();i++)
    {
        int n=(int)s[i]%3;
        while(s[i]%3!=0)
            s[i]--;
        cout<<char('a'+s[i])<<n+1;
    }
    cout<<endl;
    return 0;
}
