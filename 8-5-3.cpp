#include<iostream>
#include<memory.h>
using namespace std;
typedef int State[9];
const int MAXSTATE=1000000;
State st[MAXSTATE],goal;
int dist[MAXSTATE];


const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};


const int MAXHASHSIZE=1000003;
int head[MAXHASHSIZE],next[MAXHASHSIZE];


void init_lookup_table()
{
    memset(head,0,sizeof(head));
}


int hash(State n)
{
    int v=0;
    for(int i=0;i<9;i++) {v=v*10+n[i];}

    return v%MAXHASHSIZE;
}


int try_to_insert(int s)
{
//    cout<<"here"<<endl;
    int h=hash(st[s]);
    int n=head[h];
    while(n){
        if(memcmp(st[s],st[n],sizeof(s))==0) return 0;
        n=next[n];
    }
    next[s]=head[h];
    head[h]=s;
    return 1;
}



int bfs()
{
    init_lookup_table();
    int front=1,rear=2;
    while(front<rear){
        State &s = st[front];
        if(memcmp(goal,s,sizeof(s))==0) return front;
        int z;
        for(z=0;z<9;z++) if(!s[z]) break;
        int x=z/3,y=z%3;
        for(int d=0;d<4;d++){
//            cout<<x<<" x"<<endl;
            int newx=x+dx[d];
//            cout<<newx<<" newx"<<endl;
            int newy=y+dy[d];
            int newz=newx*3+newy;
//            cout<<newx<<"~"<<newy<<"~"<<endl;
            if(newx>=0 && newx<3 && newy>=0 && newy<3){
                State &t=st[rear];
                memcpy(&t,&s,sizeof(s));
                t[newz]=s[z];
                t[z]=s[newz];
                dist[rear]=dist[front]+1;
                if(try_to_insert(rear)) {rear++;}
            }
        }
        front++;
    }
    return 0;
}

int main()
{
    freopen("8-5-3.txt","r",stdin);
    for(int i=0;i<9;i++) cin>>st[1][i];
    for(int i=0;i<9;i++) cin>>goal[i];
    int ans=bfs();
//    cout<<ans<<endl;
    if(ans>0) cout<<dist[ans]<<endl;
    else cout<<"-1"<<endl;
    return 0;
}
