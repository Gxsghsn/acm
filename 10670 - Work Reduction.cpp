#include <iostream>
#include <cstdio>
#include <algorithm>
#define test
using namespace std;
int cases;
int N,M,L;
int cost[16];

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
//        cout<<N1<<" "<<mincost<<endl;
    }
//    cout<<"mincost:"<<mincost<<endl;
    return mincost;
}

int compare(int a,int b)
{
    return cost[a]<cost[b];
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
        char s[16];
        char C;
        int A,B;
        int len=L;
//        cout<<N<<M<<L;
        while(len>0){
            scanf("%s",&s);
            sscanf(s,"%c:%d,%d",&C,&A,&B);
//            cout<<(char)C<<A<<B<<endl;
//            printf("%d,%d***\n",C,'A');
//            cout<<":::::"<<(C-'A')<<":::::"<<'A'-(int)'A'<<endl;
            cost[C-'A']=mincost(A,B);
            len--;
        }
        int b[16];
        for(int i=0;i<16;i++) b[i]=i;
        sort(b,b+L,compare);
        printf("Case %d\n",l);
        for(int i=0;i<L;i++)
            printf("%c %d\n",b[i]+'A',cost[b[i]]);
        l++;
    }
}
