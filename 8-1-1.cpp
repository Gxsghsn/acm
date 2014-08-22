#include <iostream>
using namespace std;
int circle=1;


int maxsum(int *A,int x, int y)
{
    if(y-x==1) return A[x];
    int m=x+(y-x)/2;
    int max=maxsum(A,x,m)>?maxsum(A,m,y);
    int v=0,L=A[m-1],R=A[m];
    for(int i=m;i<y;i++) R>?=v+=A[i];
    v=0;
    for(int i=m-1;i>=x;i--) L>?=v+=A[i];
    return max>?(L+R);
}




int main(int argc, char const *argv[])
{
	/* code */
	// cout<<"abc"<<endl;

    int n=10;
    freopen("8-1-1.txt","r",stdin);
    int num[10];
    for(int i=0;i<n;i++)
        cin>>num[i];
    for(int i=0;i<n;i++) cout<<num[i]<<" ";
    cout<<endl;
    int max=maxsum(num,0,n);
    cout<<max<<endl;




    int s[n];
	int maxsum=0;
	s[0]=num[0];
	for(int i=1;i<n;i++){
		s[i]=s[i-1]+num[i];
	}
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(s[i]-s[j]>maxsum) maxsum=s[i]-s[j];
	cout<<maxsum<<endl;

	return 0;
}

