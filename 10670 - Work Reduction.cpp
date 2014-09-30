#include <iostream>
#include <cstdio>
#include <algorithm>
//#define test
using namespace std;
int cases;
int N,M,L;
int cost[16];

struct agency
{
    int A,B,V;
    char name[20];
}gen[102];




int mincost(int A,int B)
{
//    cout<<"\nhere"<<endl;
    int mincost=0;
    int M1=M;
    int N1=N;
    while(N1>M1){
        if(N1/2<M1){
            mincost+=(N1-M1)*A;
            N1=M1;
            break;
        }
        if(((int)(N1/2+0.5))*A < B)
            mincost+=(N1/2+0.5)*A;
        else mincost+=B;
        N1/=2;
    }
    return mincost;
}

bool comp(const agency &a,const agency &b)
{
    if (a.V < b.V)
        return true;
    else if (a.V > b.V)
        return false;
    else return strcmp (a.name, b.name) < 0 ? true: false;
}

int main()
{
    #ifdef test
        freopen("10670.txt","r",stdin);
    #endif // test
    cin>>cases;
    int l=1;
    while(l<=cases){
        cin>>N>>M>>L;
        char s[50];
        int len=0;
        while(len<L){
            scanf("%s",&s);
            sscanf(s,"%[^:]:%d,%d",gen[len].name,&gen[len].A,&gen[len].B);
            gen[len].V=mincost(gen[len].A,gen[len].B);
            len++;
        }
        sort(gen,gen+L,comp);
        printf("Case %d\n",l);
        for(int j=0;j<L;j++)
            printf("%s %d\n",gen[j].name,gen[j].V);
        l++;
    }
}
