#include<iostream>
using namespace std;

int main()
{
    char c;
    char *s="1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    while((c=getchar()) !=EOF)
    {
        int i=1;
        for(i=1;s[i]&&s[i]!=c;i++);
        if(s[i]) cout<<s[i-1];
        else cout<<c;

    }
    return 0;
}
