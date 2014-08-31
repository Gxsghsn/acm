#include<iostream>
#include<algorithm>
using namespace std;

bool compare(const string a,const string b)
{
    return(a+b>b+a);
}

int main()
{
    freopen("10905.txt","r",stdin);
    int n;
    while(cin>>n&&n){
        string str[50];
        for(int i=0;i<n;i++) cin>>str[i];
        sort(str,str+n,compare);
        for(int i=0;i<n;i++) cout<<str[i];
        cout<<endl;
    }
    return 0;
}
