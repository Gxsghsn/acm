#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
struct score
{
    int room_num;
    int light[13];
    int step;
    int on;
    int off;
};
score sc[13000];
int r,d,s,flag,first,last;
int room[12][12],light[12][12],way[13000],num[]= {0,1,2,4,8,16,32,64,128,256,512,1024};
int calculate(int *q)
{
    int c=0,x=0;
    for(int i=1; i<=r; i++)
    {
        c=c+num[i]*q[i];
        if(i<r&&q[i])x=1;
    }
    c+=q[r+1]*num[r+1];
    if(!x&&q[r]&&q[r+1]==r) flag=1;
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
    memset(way,0,sizeof(way));
    memset(sc[0].light,0,sizeof(sc[0].light));
    sc[0].room_num=sc[0].light[1]=sc[0].light[r+1]=way[num[r+1]+1]=last=1;
    sc[0].step=sc[0].on=sc[0].off=first=0;
    while(first<last)
    {
        score t=sc[first++];
        for(int i=1; i<=r; i++)
            if(light[t.room_num][i]&&i!=t.room_num)
            {
                score p=t;
                p.light[i]=!p.light[i];
                int c=calculate(p.light);
                if(!way[c])
                {
                    p.light[0]=first-1;
                    way[c]=1;
                    p.step=t.step+1;
                    if(p.light[i])
                    {
                        p.on=i;
                        p.off=0;
                    }
                    else
                    {
                        p.off=i;
                        p.on=0;
                    }
                    sc[last++]=p;
                }
                if(flag)
                {
                    printf("The problem can be solved in %d steps:\n",p.step);
                    show(last-1);
                    return;
                }
            }
        for(int i=1; i<=r; i++)
            if(room[t.room_num][i]&&t.light[i])
            { 
                score p=t;
                p.light[r+1]=i;
                p.room_num=i;
                int c=calculate(p.light);
                if(!way[c])
                {
                    way[c]=1;
                    p.off=p.on=0;
                    p.light[0]=first-1;
                    p.step=t.step+1;
                    sc[last++]=p;
                }
                if(flag)
                {
                    printf("The problem can be solved in %d steps:\n",p.step);
                    show(last-1);
                    return;
                }
            }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("321.txt","r",stdin);
#endif
    int count=1;
    while(scanf("%d%d%d",&r,&d,&s)!=EOF)
    {
        if(r+d+s==0) break;
        memset(room,0,sizeof(room));
        memset(light,0,sizeof(light));
        int x,y;
        for(int i=0; i<d; i++)
        {
            scanf("%d%d",&x,&y);
            room[x][y]=1;
            room[y][x]=1;
        }
        for(int i=0; i<s; i++)
        {
            scanf("%d%d",&x,&y);
            light[x][y]=1;
        }
        flag=0;
        printf("Villa #%d\n",count++);
        if(r==1) printf("The problem can be solved in 0 steps:\n\n");
        else
        {
            bfs();
            if(!flag)printf("The problem cannot be solved.\n");
            printf("\n");
        }
    }
    return 0;
}
