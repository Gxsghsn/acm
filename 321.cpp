#include<iostream>
#include<cstdio>
using namespace std;
int room[100][100];
int light[100][100];
int r,d,s;
int num[]={0,1,2,4,6,8,16,32,64,128,512,1028};
int flag=0;
int way[13000];
struct score
{
	int room_num;
	int on;
	int off;
	int step;
	int light[100];
}sc[13000];


int calculate(int *p)
{
	int c=0;
	int x=0;
	for(int i=1;i<=r;i++){
		c+=p[i]*num[i];
		if(p[i]>0&&i<r) x=1;
	}
	if(x) flag=1;
	return c;
}


void show(int cur)
{
    if(sc[cur].light[0]) {show(sc[cur].light[0]);printf("%d\n", sc[cur]);}
    if(sc[cur].on) printf("- Switch on light in room %d.\n",sc[cur].on);
    else if(sc[cur].off) printf("- Switch off light in room %d.\n",sc[cur].off);
    else printf("- Move to room %d.\n", sc[cur].room_num);
}


void bfs()
{
	first=0;
	last=1;
	sc[0].room_num=0;
	while(first<last){
		score t=sc[first++];
		for(int i=1;i<=r;i++){
			if(light[t.room_num][i]&&i!=t.room_num){
				score t1=t;
				t1.light[i]=!t1.light[i];
				int c=calculate(t1.light);
				if(!way[c]){
					way[c]=1;
					t1.light[0]=i-1;
					t1.step++;
					t1.on=0;
					t1.off=0;
					t1.light>0?t1.on=i:t1.off=i;
					sc[last++]=t1;
				}
			}
			if(flag){
				printf("The problem can be solved in %d steps:\n", t.step);
				show(first-1);
				return;
			}
		}
		for(int i=1;i<=r;i++){
			if(room[t.room_num][i]&&t.light[i]){
				score t1=t;
				t1.room_num=i;
				int c=calculate(t1.light);
				if(!way[c]){
					way[c]=1;
					t1.light[0]=i-1;
					t1.off=t1.on=0;
					t1.step++;
					sc[last++]=t;
				}
				if(flag){
					printf("The problem can be solved in %d steps:\n", t.step);
					show(first-1);
					return;
				}
			}
		}
	}
}


int main()
{
    freopen("321.txt","r",stdin);
    while(scanf("%d%d%d",&r,&d,&s)!=EOF){
    	if(r+d+s==0) break;
    	memset(room,0,sizeof(room));
    	memset(light,0,sizeof(light));
    	int x,y;
		for(int i=0;i<d;i++){
			scanf("%d%d",&x,&y);
			room[x][y]=1;
			room[y][x]=1;
		}
		for(int i=0,j=s;s>0;s--){
			scanf("%d%d",&x,&y);
			light[x][y]=1;
		}
		bfs();
		if(!flag) printf("The problem cannot be solved.\n");
    }
    return 0;
}

