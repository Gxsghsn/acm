#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main()
{
    freopen("5-3-2.in","r",stdin);
    string s[20][2];
    int n=1;
    while((cin>>s[n][0])&&s[n][0]!="******"){n++;}

    for(int i=0;i<n;i++)
    {
        string a = s[i][0];
        for(int j=0;j<a.length();j++)
        {
            for(int k=0;k<a.length()-1;k++)
            {
                if(a[k]>a[k+1])
                {
                    char b = a[k];
                    a[k] = a[k+1];
                    a[k+1] = b;
                }
            }
        }
        s[i][1] = a;
    }

    string input;
    int findflag=0;

    while(cin>>input)
    {
        findflag=0;
        for(int j=0;j<input.length();j++)
        {
            for(int k=0;k<input.length()-1;k++)
            {
                if(input[k]>input[k+1])
                {
                    char b = input[k];
                    input[k] = input[k+1];
                    input[k+1] = b;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(s[i][1]==input)
            {
                findflag=1;
                cout<<s[i][0]<<" ";
            }
        }
        if(findflag==0)
            cout<<":(";
        cout<<endl;
    }
    return 0;
}
