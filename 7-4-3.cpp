#include<iostream>
using namespace std;
int len,m;
int S[100]={0};

int dfs(int cur)
{
    if(m==0){
        cout<<"~"<<endl;
        cout<<cur<<"~"<<endl;
        for(int i=0;i<cur;i++) cout<<(char)('A'+S[i]);
        cout<<endl;
        return 0;
    }
    for(int i=0;i<len;i++){
        S[cur]=i;
        int ok=1;
        for(int k=1;2*k<=cur+1;k++){
            ok=1;
            for(int j=0;j<k;j++){
                if(S[cur-j]!=S[cur-k-j]){
                    ok=0;
                    break;
                }
            }
            if(ok==1) break;
        }
        if(cur==0) ok=0;
        if(!ok){
            for(int j=0;j<=cur;j++) cout<<(char)('A'+S[j]);
            cout<<endl;
        }
        if(!ok) {m--;}
        if(ok==0||cur==0)
            if(dfs(cur+1)==0)
                return 0;
    }
    return 1;
}



int main()
{
    cin>>m>>len;
    dfs(0);
    return 0;
}
