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
