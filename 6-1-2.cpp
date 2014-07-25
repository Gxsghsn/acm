#include<iostream>
#include<stack>
using namespace std;

stack<int> q;
int main()
{
    int n;
    cin>>n;
    int n1=1;
    int r[100];
    int r1=0;
    int m=n;
    for(int i=0;i<n;i++) {cin>>r[i];}
    while(m>0)
    {
        if(!q.empty()&&q.top()==r[r1])
        {
            r1++;
            q.pop();
            m--;
            if(m==0)
                cout<<"Yes"<<endl;
        }
        else
        {
            q.push(n1);
            n1++;
            if(n1>n+1)
            {
                cout<<"NO"<<endl;
                break;
            }
        }
    }
    return 0;
}
