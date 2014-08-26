#include<iostream>
#include<algorithm>
using namespace std;

int v[10000];
int main()
{
    freopen("8-4.txt","r",stdin);
    int m,n,a,b;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v,v+n);
//    for(int i=0;i<n;i++) cout<<v[i];
//    cout<<endl;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        cout<<(upper_bound(v,v+7,b)-v) - (lower_bound(v,v+7,a)-v)<<endl;
    }
    return 0;
}
