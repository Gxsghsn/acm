#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.find(s[s.length()-1]);
//    cout<<n+1<<endl;
    string s1;
    for(int i=0;i<=n;i++)
    {
        s1+=s[i];
    }
//    cout<<s1<<"*"<<endl;
    int flag=0;
    for(int i=n+1;i<s.length();i++)
    {
        if(s[i]!=s1[i%(n+1)])
        {
            flag=1;
            break;
        }
        else
            cout<<"yes"<<endl;
    }
    if(flag==0)
        cout<<s1<<endl;
    else
        cout<<"wrong"<<endl;
    return 0;
}
