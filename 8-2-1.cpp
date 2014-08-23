#include<iostream>
using namespace std;

void merge_sort(int *A,int x,int y,int *T)
{
    if(y-x>1){
        int m=x+(y-x)/2;
        merge_sort(A,x,m,T);
        merge_sort(A,m,y,T);
        int p=x,q=m,i=x;
        while(p<m||q<y){
        	if(q>=y || (p<m && A[p]<=A[q])) T[i++]=A[p++];
        	else T[i++]=A[q++];
        }
        for(int j=x;j<y;j++) A[j]=T[j];
    }
}


int main()
{
	int A[10]={1,5,2,-1,9,6,22,-11,7,10};
	int T[10]={0};
	merge_sort(A,0,10,T);
	for(int i=0;i<10;i++) cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}
