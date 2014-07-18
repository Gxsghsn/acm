#include<iostream>
using namespace std;

int main()
{
    string s=" \"To be or not to be,\"quoth the Bard,\"that is the question\"";
//    cin>>s;
//    cout<<s<<endl;
//    s="”";
//    cout<<s<<"     1"<<endl;
    int flag=1;
    s = s.replace(s,'"',"“");
//    for(int i=0;i<s.length();i++)
//    {
//        if(s[i]=='"')
//        {
//            if(flag==0)
//                s.insert(i,"“");
//            else
//                s.insert(i,"”");
//            flag = 1-flag;
//        }
//    }
    cout<<s<<endl;

//    char c;
//    while((c=getchar())!=EOF)
//    {
//        if(c=='"'){printf("%s",flag?"“":"”");flag = !flag;}
//        else printf("%c",c);
//    }
    return 0;
}
