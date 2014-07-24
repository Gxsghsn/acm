//#include<iostream>
//#include<cstdio>
//#include<string.h>
//using namespace std;
//
//int main()
//{
//    string s;
//    while(getline(cin,s))
//    {
//        int i=0;
//        int num=0;
//        while(s[i]!='\0')
//        {
//            while(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
//                i++;
//            if(i>0) num++;
//            while(!(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')&&s[i]!='\0')
//                i++;
//        }
//        cout<<num<<endl;
//    }
//    return 0;
//}




#include<iostream>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        int i=0;
        int num=0;
        int len=0;
        string str="";
        while(s[i] != '\0')
        {
            while((s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'))
            {
                str+=s[i];
                i++;
            }
            for(int j=0;j<str.length();j++)
                if(str[j]>='a'&&str[j]<='z'||str[j]>='A'&&str[j]<='Z')
                    len++;
            if(len>0)
            {
                len=0;
                num++;
            }
            str="";
            i++;
        }
        cout<<num<<endl;
    }
}
