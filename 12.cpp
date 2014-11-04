#include <iostream>
#include <cstdio>
using namespace std;
int save[1000];
int n,b,w[1000];
// int best=0;
int num=0;

int solve1(int cur){
	int min=999,min_index=0;
	for(int i=0;i<n;i++){
		if(save[i]==0) 
			if(w[i]<min){
				min=w[i];
				min_index=i;
			}
	}
	if(cur+min>b) return cur;
	save[min_index]=1;
	return solve1(cur+min);
}

int main()
{
	int Case;
	Case=1;
	while(scanf("%d %d",&n,&b) != EOF){
		// scanf("%d %d",&n,&b);
		num=0;
		if(n==0 || b==0) break;
		for(int i=0;i<n;i++){
			scanf("%d",&w[i]);
			save[i]=0;
		}
		int a = solve1(0);
		// for(int i=0;i<n;i++)
			// if(save[i]!=0) n++;
		printf("Case %d\n",Case++);
		printf("%d %d\n", n, b-a);
		for(int i=0;i<n;i++) printf("%d", save[i]);
		printf("\n");
	}
	return 0;
}