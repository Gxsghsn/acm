#include<iostream>
using namespace std;

void print_subset1(int n,int *A,int cur)
{
    for(int i=0;i<cur;i++) cout<<A[i];
    cout<<endl;

    int s=cur?A[cur-1]+1:0;

    for(int i=s;i<n;i++){
        A[cur]=i;
        print_subset1(n,A,cur+1);
    }

}


void print_subset2(int n,int *B,int cur)
{
    if(cur==n){
        for(int i=0;i<n;i++)
            if(B[i]) cout<<i;
        cout<<endl;
        return;
    }
    B[cur]=1;
    print_subset2(n,B,cur+1);
    B[cur]=0;
    print_subset2(n,B,cur+1);
}


int main()
{
    int a[10];
    print_subset1(4,a,0);
    return 0;
}
