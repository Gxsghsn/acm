#include<iostream>
#include<ctype.h>
using namespace std;

int main()
{
    int n,num=1;
    cin>>n;
    string s;
    while(n>0)
    {
        cin>>s;
        for(int i=0;i<s.length();i++)
            if(s[i]=='_')
            {
                s.erase(i,1);
                s[i]=toupper(s[i]);
//                s[i]=(char)(s[i]-32);
            }
        n--;
        n++;
        cout<<"case "<<num<<":\n"<<s<<endl;
    }
    return 0;
}
