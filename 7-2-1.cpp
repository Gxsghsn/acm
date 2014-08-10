#include<iostream>
using namespace std;

void dictionary_print(int n,string A,int cur,string B)
{
    if(n==cur){
        for(int i=0;i<n;i++) cout<<A[i];
        cout<<endl;
    }
    else for(int j=0;j<n;j++){
        int ok=1;
        for(int i=0;i<cur;i++){
            if(A[i]==B[j]) ok=0;
        }
        if(ok){
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
