#include <iostream>
#include <cstdio>
using namespace std;

int m[10][10];
int now[10];
int nowp=0;

int record[10][2];
int recordp=0;

int num_in_now(int n)
{
	for(int i=0;i<nowp;i++)
		if(n==now[i]){
			return 1;
		}
	return 0;
}

int main()
{

	int max=0;
	freopen("prim.txt","r",stdin);
	char s[20];
	while(gets(s)){
		int a,b,c;
		sscanf(s,"(%d,%d,%d)",&a,&b,&c);
		max>?=a>?b;
		m[a][b]=c;
		m[b][a]=c;
	}

	now[0]=0;
	nowp++;

	for(int lines=0;lines<max;lines++){
        // cout<<lines<<":"<<endl;
        int min=9999;
		for(int i=0;i<nowp;i++){
			for(int j=0;j<=max;j++){
				if(num_in_now(j)) continue;

				if(m[now[i]][j]<min&&m[now[i]][j]!=0) {
				    min=m[now[i]][j];
                    now[nowp]=j;
                    record[lines][0]=now[i];
                    record[lines][1]=j;
                }
			}
		}
		nowp++;
//		printf(" %d\n", min);
        recordp++;
	}

	for(int i=0;i<=max;i++){
		for(int j=0;j<=max;j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
//    cout<<recordp<<endl;
	for(int i=0;i<recordp;i++){
		printf("(%d,%d)\n", record[i][0],record[i][1]);
	}

	return 0;
}

