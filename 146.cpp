#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int cha[26]={0};

int main()
{
    char a[55]={0};
    memset(a,0,sizeof(a));
    while(scanf("%s",&a)){
    	if(a[0]=='#') break;
    	if(next_permutation(a,a+strlen(a))) printf("%s\n",a);
    	else printf("No Successor\n");
    }

 /*   for(int i=0;i<a.length();i++){
    	cha[a[i]-'a']++;
    }*/
    // for(int i=0;i<26;i++) cout<<cha[i];
    // string b="";
    // get_string(b,0);
    return 0;
}
