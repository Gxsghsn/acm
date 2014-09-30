<<<<<<< HEAD
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

char map[1000][1000];
int step[1000][1000];
int d[4][2]={1,0,-1,0,0,1,0,-1};

typedef struct node{
    int x,y,step;
    bool IsFire;
    node(int X,int Y,int S,bool F){x=X;y=Y;step=S;IsFire=F;}
    node(){}
}point;

point Q[1000];


int bfs(int n,int m)
{
    int move=0,save=0;
    point J;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        if(map[i][j]=='J')
            J = point(i,j,0,0);
        if(map[i][j]=='F')
            Q[save++]=point(i,j,0,1);
        step[i][j]=100000;
    }
    Q[save++]=J;
    step[J.x][J.y]=0;
    while(move<save){

//        for(int i=0;i<n;i++)
//            printf("%s\n",map[i]);
//        if()
//        printf("J")
//        printf("\n");

        point New,now=Q[move++];

//        if(!now.IsFire)
//            printf("%d %d**\n",now.x,now.y);
//        printf("\n");

        if(!now.IsFire&&(now.x==0||now.y==0||now.x==n-1||now.y==m-1)){
            printf("%d\n",now.step);
            return 1;
        }

        for(int i=0;i<4;i++){
            New.x=now.x+d[i][0];
            New.y=now.y+d[i][1];
            New.step=now.step+1;
            New.IsFire=now.IsFire;
            if(New.x<n&&New.x>=0&&New.y<m&&New.y>=0)
            if(map[New.x][New.y]=='.'){
                if(New.IsFire){
                    map[New.x][New.y]='F';
                    Q[save++]=New;
                }
                else if(step[New.x][New.y]>New.step){
                    step[New.x][New.y]=New.step;
                    Q[save++]=New;
                }
            }
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}



int main()
{
    freopen("11624.txt","r",stdin);
    int c;
    scanf("%d",&c);
    while(c--){
        int R,C;
        scanf("%d%d",&R,&C);
        for(int i=0;i<R;i++){
            scanf("%s",map[i]);
        }
//        for(int i=0;i<R;i++)
//            printf("%s\n",map[i]);
        bfs(R,C);
    }
}
=======
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

char maps[1005][1005];
int  step[1005][1005];
int  d[4][2] = {1,0,-1,0,0,1,0,-1};

typedef struct nodep {
	int x,y,s,f;
	nodep( int X, int Y, int S, int F ){x = X;y = Y;s = S;f = F;}
	nodep(){}
}point;
point Q[1000005];

void bfs( int n, int m )
{
	int move = 0,save = 0;
	point J;
	for ( int i = 0 ; i < n ; ++ i )
	for ( int j = 0 ; j < m ; ++ j ) {
		if ( maps[i][j] == 'J' )
			J = point( i, j, 0, 0 );
		if ( maps[i][j] == 'F' )
			Q[save ++] = point( i, j, 0, 1 );
		step[i][j] = 1000005;
	}

	step[J.x][J.y] = 0;
	Q[save ++] = J;
	while ( move < save ) {
		point New,now = Q[move ++];
		if ( !now.f )
		if ( now.x == 0 || now.x == n-1 || now.y == 0 || now.y == m-1 ) {
			printf("%d\n",now.s+1);
			return;
		}
		for ( int i = 0 ; i < 4 ; ++ i ) {
			New.x = now.x + d[i][0];
			New.y = now.y + d[i][1];
			New.s = now.s + 1;
			New.f = now.f;
			if ( New.x >= 0 && New.x < n && New.y >= 0 && New.y < m )
			if ( maps[New.x][New.y] == '.' )
				if ( New.f ) {
					maps[New.x][New.y] = 'F';
					Q[save ++] = New;
				}else if ( step[New.x][New.y] > step[now.x][now.y] + 1 ) {
					step[New.x][New.y] = step[now.x][now.y] + 1;
					Q[save ++] = New;
				}
		}
	}
	printf("IMPOSSIBLE\n");
}

int main()
{
	int c,n,m;
	while ( scanf("%d",&c) != EOF )
	while ( c -- ) {
		scanf("%d%d",&n,&m);
		for ( int i = 0 ; i < n ; ++ i )
			scanf("%s",maps[i]);
		bfs( n, m );
	}
	return 0;
}
>>>>>>> eaf31b299a8015ff83c93e41729a950c10b789a0
