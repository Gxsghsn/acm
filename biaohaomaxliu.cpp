//标号法求网络最大流量
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#define MAXN 1000	//顶点个数最大值
#define INF 1000000	//无穷大
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

struct ArcType	//弧结构
{
	int c, f;	//容量，流量
};
ArcType Edge[MAXN][MAXN];	//邻接矩阵(每个元素为ArcType类型)
int n, m;		//顶点个数和弧数
int flag[MAXN]; //顶点状态：-1－未标号,0－已标号未检查,1－已标号已检查
int prev[MAXN];	//标号的第一个分量：指明标号从哪个顶点得到，以便找出可改进量
int alpha[MAXN];	//标号的第二个分量：可改进量α
int queue[MAXN];	//相当于BFS算中法的队列
int v;			//从队列里取出来的队列头元素
int qs, qe;		//队列头位置，队列尾位置
int i, j;		//循环变量

void ford( )
{
	while( 1 )	//标号直至不存在可改进路
	{
		//标号前对顶点状态数组初始化
		memset( flag, 0xff, sizeof(flag) );	//将3个数组各元素初始化为-1
		memset( prev, 0xff, sizeof(prev) ); 
		memset( alpha, 0xff, sizeof(alpha) );
		flag[0] = 0;  prev[0] = 0;  alpha[0] = INF; //源点为已标号未检查顶点
		qs = qe = 0; 
		queue[qe] = 0;  qe++;	//源点(顶点0)入队列
		
		//qs<qe表示队列非空, flag[n-1]==-1表示汇点未标号
		while( qs<qe && flag[n-1]==-1 )
		{
			cout<<"*"<<endl;
			v = queue[qs];  qs++;	//取出队列头顶点
			for( i=0; i<n; i++ )	//检查顶点v的正向和反向"邻接"顶点
			{
				if( flag[i]==-1 )	//顶点i未标号
				{
					//"正向"且未"满"
					if( Edge[v][i].c<INF && Edge[v][i].f < Edge[v][i].c )
					{
						flag[i] = 0;  prev[i] = v;	//给顶点i标号(已标号未检查)
						alpha[i] = MIN( alpha[v], Edge[v][i].c - Edge[v][i].f );
						queue[qe] = i;  qe++;	//顶点i入队列
					}
					else if( Edge[i][v].c<INF && Edge[i][v].f > 0 )	//"反向"且有流量
					{
						flag[i] = 0;  prev[i] = -v;	//给顶点i标号(已标号未检查)
						alpha[i] = MIN( alpha[v], Edge[i][v].f );
						queue[qe] = i;  qe++;	//顶点i入队列
					}
				}
			}
			flag[v] = 1;	//顶点v已标号已检查
		}//end of while( qs<qe && flag[n-1]==-1 )

		//当汇点没有获得标号，或者汇点的调整量为0，应该退出while循环
		cout<<"#"<<flag[n-1]<<alpha[n-1]<<endl;
		if( flag[n-1]==-1 || alpha[n-1]==0 )  break;
		
		//当汇点有标号时,应该进行调整了
		int k1 = n-1, k2 = abs(prev[k1]);
		int a = alpha[n-1];	//可改进量
		cout<<"***"<<k1<<" "<<k2<<endl;
		while( 1 )
		{
			if( Edge[k2][k1].f<INF ) //正向
				Edge[k2][k1].f = Edge[k2][k1].f + a;
			else  Edge[k1][k2].f = Edge[k1][k2].f - a;	 //反向
			if( k2==0 )  break;	//调整一直到源点v0
			k1 = k2;  k2 = abs( prev[k2] );
		}//end of while( 1 )
	}//end of while( 1 )

	//输出各条弧及其流量，以及求得的最大流量
	int maxFlow = 0;
	for( i=0; i<n; i++ )
	{
		for( j=0; j<n; j++ )
		{
			if( i==0 && Edge[i][j].f<INF )	//求源点流出量，即最大流
				maxFlow += Edge[i][j].f;
			if( Edge[i][j].f<INF )  printf( "%d->%d : %d\n", i, j, Edge[i][j].f );
		}
	}
	printf( "maxFlow : %d\n", maxFlow );
}

int main( )
{
	freopen("biaohaomaxliu.in","r",stdin);
	int u, v, c, f;	//弧的起点、终点、容量、流量
	scanf( "%d%d", &n, &m );	//读入顶点个数n和弧数m
	for( i=0; i<n; i++ )	//初始化邻接矩阵中各元素
	{
		for( j=0; j<n; j++ )  Edge[i][j].c = Edge[i][j].f = INF;	//INF表示没有直接边连接
	}
	for( i=0; i<m; i++ )	//读入每条弧
	{
		scanf( "%d%d%d%d", &u, &v, &c, &f );	//读入边的起点和终点
		Edge[u][v].c = c;  Edge[u][v].f = f;	//构造邻接矩阵
	}
	ford( );	//标号法求网络最大流
	return 0;
}
