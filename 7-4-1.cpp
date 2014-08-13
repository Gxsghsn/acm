#include<iostream>
using namespace std;
int n;
int C[10];


void search(int cur)
{
    if(cur==n){
        for(int i=0;i<n;i++) cout<<C[i];
        cout<<endl;
        return;
    }
    else{
        for(int i=0;i<n;i++){
            C[cur]=i;
            int ok=1;
            for(int j=0;j<cur;j++)
                if(C[j]==C[cur]||C[j]-j==C[cur]-cur||C[j]+j==C[cur]+cur)
                    ok=0;
            if(ok){
//                C[cur]=i;
                search(cur+1);
            }
        }
    }
}


int main()
{
//    cin>>n;
    n=4;
    search(0);
    return 0;
}
