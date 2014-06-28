#include<iostream>
using namespace std;

int main()
{
//    int n=0,a,sum=0,max=0,min=99999;
//    while(cin>>a)
//    {
//        n++;
//        sum+=a;
//        if(a>max) max=a;
//        if(a<min) min=a;
//    }
//    cout<<max<<endl<<min<<endl<<(double)sum/n<<endl;



//    int dis=0;
//    int a[10];
//    int i=0,a1,a2,min=9999;
//    while(cin>>a[i])
//    {
//        i++;
//    }
//    for(int k=0;k<i;k++)
//    for(int j=k+1;j<=i;j++)
//    {
//        if(a[j]-a[k]<min)
//        {
//            min=a[j]-a[k];
//            a1=k;
//            a2=j;
//        }
//    }
//    cout<<a1<<" "<<a2<<endl;



//    int max=0,max2=0,a=0;
//    while(cin>>a)
//    {
//        if(a>max) {max2=max;max=a;}
//        else
//            if(a>max2) max2=a;
//    }
//    cout<<max2<<endl;



//    int sum=0,n=0,a[10],i=0,f=0;
//    double ave;
//    while(cin>>a[i])
//    {
//        sum+=a[i];
//        i++;
//    }
//    ave = sum/i;
////    cout<<i<<endl;
//    for(int j=0;j<i;j++)
//        f+=(a[j]-ave)*(a[j]-ave);
////    for(int j=0;j<5;j++)
////        cout<<a[j]<<" ";
//    cout<<(double)f/i<<endl;



    int a[10],n=0,sum=0,ave,num=0;
    while(cin>>a[n])
    {
        sum+=a[n++];
    }
    ave = sum/n;
    for(int j=0;j<n;j++)
        if(a[j]<ave)
            num++;
    cout<<num<<endl;
    return 0;
}
