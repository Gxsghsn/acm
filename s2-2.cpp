#include <iostream>
#include <cstdio>
using namespace std;

int fibonacci(int n)
{
	if(n==0||n==1) return 1;
	return fibonacci(n-1)+fibonacci(n-2);
}


int main(int argc, char const *argv[])
{
	/* code */
	int n=5;
	printf("%d\n", fibonacci(6));
	return 0;
}
