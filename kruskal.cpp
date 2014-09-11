#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct side
{
	/* data */
	int left;
	int right;
	int value;
};
side m[100];
int p_m=0;
int father[100];


int find_root(int a)
{
	return a == father[a] ? a : find_root(father[a]);
}

int compare(side a,side b)
{
	return a.value<b.value;
}

int combine(int a,int b)
{
	if(find_root(a)==find_root(b)) return 0;
	father[find_root(b)]=find_root(a);
	return 1;
}

int main()
{
	freopen("prim.txt","r",stdin);
	char s[50];
	int max=0;

	for(int i=0;i<100;i++) father[i]=i;

	while(gets(s)){
		int a,b,c;
		sscanf(s,"(%d,%d,%d)",&a,&b,&c);
		max>?=a>?b;
		side si;
		si.left=a;si.right=b;si.value=c;
		m[p_m++]=si;
		// father[b]=a;
	}

	sort(m,m+p_m,compare);

	int edge_num=0;
	for(int u=0;u<p_m;u++){
		if(combine(m[u].left,m[u].right)){
			printf("(%d,%d)\n", m[u].left,m[u].right);
			edge_num++;
		}
		if(edge_num>=max)
			break;
	}
	return 0;
}


