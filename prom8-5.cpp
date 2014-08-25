#include<iostream>
using namespace std;

int bsearch(int *A,int x,int y,int v)
{
	while(x<y){
        cout<<"x "<<x<<" y "<<y<<endl;
		int m=x+(y-x)/2;
		cout<<"m "<<m<<endl;
        if(A[m]==v) return m;
		else if(A[m]>v) y=m;
		else x=m+1;
	}
	return -1;
}


int bsearch1(int *A,int x,int y,int v)
{
    while(x<y){
        int m=x+(y-x)/2;
        if(A[x]>=v) y=m;
        else x=m+1;
    }
    return x;
}

int main(int argc, char const *argv[])
{
	/* code */
	freopen("prom8-5.txt","r",stdin);
	int A[10];
	for(int i=0;i<10;i++) cin>>A[i];
	int x=bsearch(A,0,10,7);
	cout<<x<<endl;
	return 0;
}
