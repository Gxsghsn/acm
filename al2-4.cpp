#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

template<class Type>
void Swap(Type &a,Type &b){
	Type temp=a;a=b;b=temp;
//	cout<<"*"<<a<<b<<endl;
}

template <class Type>
void Perm(Type list[],int k,int m)
{
	if(k==m){
		for (int i = 0; i < m; ++i){
			/* code */
			cout<<list[i];
		}
		cout<<endl;
	}
	else for(int i=k;i<m;i++){
		Swap(list[k],list[i]);
		Perm(list,k+1,m);
		Swap(list[k],list[i]);
	}
}



int main()
{
	int list[]={1,2,3};
	Perm<int>(list,0,3);
	return 0;
}
