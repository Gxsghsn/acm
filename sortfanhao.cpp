#include <iostream>
#include <cstdio>
using namespace std;


int compare(char* a,char* b)
{
//    return strcmp(a,b);
    return 0;
}

int main()
{
    freopen("fanhao.txt","r",stdin);
//    freopen("fanhao1.txt","w",stdout);

    char s[300][20];
    int p_s=0;
    while(cin>>s[p_s]){
        cout<<s[p_s]<<endl;
        p_s++;
    }
//    cout<<"**"<<endl;
    sort(s,s+p_s,compare);
    for(int i=0;i<p_s;i++)
        printf("%s\n",s[i]);
    return 0;
}
