#include<iostream>
using namespace std;

void dictionary_print(int n,string A,int cur,string B)
{
    if(n==cur){
        for(int i=0;i<n;i++) cout<<A[i];
        cout<<endl;
    }
    else for(int j=0;j<n;j++)
        if(!j||B[j]!=B [j-1]){
        int ok=1;
        int c1=0,c2=0;
        for(int i=0;i<cur;i++){
            if(A[i]==B[j]) c1++;
        }
        for(int i=0;i<n;i++)
            if(B[i]==B[j]) c2++;
//        if(c1<c2) ok=1;
        if(c1<c2){
            A[cur]=B[j];
            dictionary_print(n,A,cur+1,B);
        }
    }
}

int main()
{
    string a;
    cin>>a;
    string b;
    dictionary_print(a.length(),b,0,a);
    return 0;
}
