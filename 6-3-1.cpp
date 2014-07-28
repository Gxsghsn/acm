#include<iostream>
#include<cmath>
using namespace std;
int treeswith[100];
int main()
{
    int layer,ballnum;
    while(cin>>layer>>ballnum){
        int ball;
        memset(treeswith,0,100*sizeof(int));
        for(int i=ballnum;i>0;i--){
            ball=1;
            while(ball*2+1<=pow(2.0,(double)layer)-1){
                treeswith[ball-1]=!treeswith[ball-1];
                treeswith[ball-1]==1?ball*=2:ball=ball*2+1;
            }
        }
        cout<<ball<<endl;
    }
    return 0;
}
