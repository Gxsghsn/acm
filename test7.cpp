#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    freopen("test7.in","r",stdin);
    int testnum,casenum=1;
    cin>>testnum;
    while(testnum>0)
    {
        int a1,b1,c1,a2,b2,c2;
        double x1,x2,sum=0;
        cin>>a1>>b1>>c1>>a2>>b2>>c2;
        x1 =(double)((b2-b1) - sqrt((b1-b2)*(b1-b2)-4*(a1-a2)*(c1-c2)))/(2*(a1-a2));
        x2 =(double)((b2-b1) + sqrt((b1-b2)*(b1-b2)-4*(a1-a2)*(c1-c2)))/(2*(a1-a2));
        for(double i=x1;i<x2;i+=0.01)
        {
            sum+=((a1*i*i+b1*i+c1)-(a2*i*i+b2*i+c2))*0.01;
        }
        testnum--;
        cout<<"Case "<<casenum<<":\n";
        sum>0?sum=sum:sum=-sum;
        printf("%.2f\n",sum+0.005);
        casenum--;
    }
    return 0;
}
