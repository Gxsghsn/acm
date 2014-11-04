#include <iostream>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <queue>
#include <cstdio>
// #include <system>
#include <cstdlib>
using namespace std;
#define MAXN 1000	//顶点个数最大值
#define INF 1000000	//无穷大
#define MIN(a,b) ((a)<(b)?(a):(b))
int abc;

struct ArcType
{
	int c,f;
};

ArcType Edge[MAXN][MAXN];
queue<int> q;
int flag[MAXN]; //顶点状态：-1－未标号,0－已标号未检查,1－已标号已检查
int prev[MAXN];	//标号的第一个分量：指明标号从哪个顶点得到，以便找出可改进量
int queue1[MAXN];	//相当于BFS算中法的队列
int qs, qe;		//队列头位置，队列尾位置
int alpha[MAXN];	//标号的第二个分量：可改进量α
int n, m;		//顶点个数和弧数
int v;


void ford(){
	while(1){
		memset(flag,0xff,sizeof(flag));
		memset(prev,0xff,sizeof(prev));
		memset(alpha,0xff,sizeof(alpha));
		flag[0]=0;
		prev[0]=0;
		alpha[0]=INF;
		// q.push(0);
		qs = qe = 0; 
		queue1[qe] = 0;  qe++;	//源点(顶点0)入队列
		while(!q.empty()){
			q.pop();
		}
		q.push(0);

		while(!q.empty() && flag[n-1]==-1)
		{
			v=q.front();
			q.pop();
			// if(q.empty()) cout<<"haha"<<endl;
			for(int i=0;i<n;i++){
				if(flag[i]==-1){
					if(Edge[v][i].c<INF && Edge[v][i].f<Edge[v][i].c){
						flag[i]=0;
						prev[i]=v;
						// cout<<i<<prev[i]<<endl;
						// return;
						alpha[i]=MIN(alpha[v],Edge[v][i].c-Edge[v][i].f);
						q.push(i);
					}else if(Edge[i][v].c<INF && Edge[i][v].f>0){
						cout<<"abc"<<endl;
						return;
						flag[i]=0;
						prev[i]=-v;
						alpha[i]=MIN(alpha[i],Edge[i][v].f);
						q.push(i);
					}
				}
			}
			flag[v]=1;
			// cout<<alpha[0]<<"\n"<<alpha[1]<<endl;
		}
		// while(qs<qe && flag[n-1]==-1)
		// {
		// 	cout<<"*"<<endl;
		// 	v = queue1[qs];  qs++;	//取出队列头顶点
		// 	// v=q.front();
		// 	// q.pop();
		// 	for( int i=0; i<n; i++ )	//检查顶点v的正向和反向"邻接"顶点
		// 	{
		// 		if( flag[i]==-1 )	//顶点i未标号
		// 		{
		// 			//"正向"且未"满"
		// 			if( Edge[v][i].c<INF && Edge[v][i].f < Edge[v][i].c )
		// 			{
		// 				flag[i] = 0;  prev[i] = v;	//给顶点i标号(已标号未检查)
		// 				alpha[i] = MIN( alpha[v], Edge[v][i].c - Edge[v][i].f );
		// 				queue1[qe] = i;  qe++;	//顶点i入队列
		// 				// q.push(i);
		// 			}
		// 			else if( Edge[i][v].c<INF && Edge[i][v].f > 0 )	//"反向"且有流量
		// 			{
		// 				flag[i] = 0;  prev[i] = -v;	//给顶点i标号(已标号未检查)
		// 				alpha[i] = MIN( alpha[v], Edge[i][v].f );
		// 				queue1[qe] = i;  qe++;	//顶点i入队列
		// 				// q.push(i);
		// 			}
		// 		}
		// 	}
		// 	flag[v] = 1;	//顶点v已标号已检查
		// }//end of while( qs<qe && flag[n-1]==-1 )
		cout<<"#"<<flag[n-1]<<alpha[n-1]<<endl;
		if(flag[n-1]==-1 || alpha[n-1]==0) break;

		int k=n-1,k2=abs(prev[k]);
		int a=alpha[k];//a=1
		// cout<<k<<" "<<k2<<endl;
		// return;
		while(1){
			// for(int i=0;i<n;i++) 
				// cout<<prev[i]<<" ";
			// cout<<endl;
			if(Edge[k2][k].f < INF)
				Edge[k2][k].f += a;
			else  Edge[k][k2].f -= a;

			if(k2==0) break;
			k=k2;
			k2=abs(prev[k]);
		}
		// break;
	}	
	int maxFlow=0;
	for(int i=0;i<n;i++) 
		if(Edge[0][i].f < INF) 
			maxFlow+=Edge[0][i].f;
	cout<<"***"<<maxFlow<<endl;
}






int main()
{
	freopen("biaohaomaxliu.in","r",stdin);
	int u,v,c,f;
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			Edge[i][j].c = Edge[i][j].f = INF;
		}
	}


	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&u,&v,&c,&f);
		Edge[u][v].c=c;
		Edge[u][v].f=f;
	}
	ford();
	return 0;
}
