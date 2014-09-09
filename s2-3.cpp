#include <iostream>
#include <cstdio>
using namespace std;

int ackerman(int n,int m)
{
    printf("...");
	if(n==0) return 1;
	if(n==1&&m==0) return 2;
	if(m==0) return n+2;
	return ackerman(ackerman(n-1,m),m-1);
}

int main()
{
	int n=10;
	int m=3;
	printf("%d\n", ackerman(n,m));
	return 0;
}
