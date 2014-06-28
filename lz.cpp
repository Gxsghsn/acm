#include<iostream>
#include<string>
using namespace std;

int main()
{
    int i=0,flag=0,sflag=0,locat=-1;
    string s[20],after,before,compare;
    cin>>before;
    int length = before.length();
    for(i=0;i<length;i++)     // in before
    {
        flag = 0;
        int j = 0;
        compare+=before[i];
        for(j=0;j<10;j++)    //  in s[10]
        {
            if(compare==s[j])
            {
                flag = 1;
                locat = j;     //locat is the longest string number in s
            }
        }
        if(flag==0)      //s has not compare
        {
            s[sflag] = compare;
            sflag++;
            compare="";
            if(locat!=-1)
            {
                char ch=(char)(locat+1+int('0'));
                after+=ch;
            }
            after+=before[i];
        }
    }
    cout<<after<<endl;
    return 0;
}
