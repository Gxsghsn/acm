#include<iostream>
using namespace std;
int mnt=0;

void merge_sort(int *A,int x,int y,int *T)
{
    if(y-x>1){
        int m=x+(y-x)/2;
        merge_sort(A,x,m,T);
        merge_sort(A,m,y,T);
        int p=x,q=m,i=x;
        while(p<m||q<y){
            if(q>=y || (p<m&&A[p]<=A[q])) T[i++]=A[p++];
            else{
                T[i++]=A[q++];
                mnt+=m-p;
            }
        }
        for(i=x;i<y;i++){
            A[i]=T[i];
        }
    }
}


int main()
{
    int T[10]={9};
    int A[10]={1,5,2,-1,9,6,22,-11,7,10};
    merge_sort(A,0,10,T);
    for(int i=0;i<10;i++) cout<<A[i]<<" ";
    cout<<endl;
    cout<<mnt<<endl;
    return 0;
}
