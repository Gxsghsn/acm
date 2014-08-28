#include<iostream>
using namespace std;

int main()
{
    freopen("8-3-5.txt","r",stdin);
    int n,m,num[100],sum=0;
    int div[10],divp=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num[i];
        sum+=num[i];
    }
    int x=7;
    int a=0,sum1=0;
    while(a<n){
//        cout<<"a";
        sum1=0;
        while(1){
            if(sum1+num[a]<=x){
                sum1+=num[a];
                a++;
            }
            else break;
//            cout<<"sum1: "<<num[a]<<endl;
        }
        div[divp]=a;
        divp++;
        cout<<"divp in loop: "<<divp<<" a: "<<a<<endl;
    }
//    cout<<endl;
//    cout<<"divp: "<<divp<<endl;
    for(int i=0;i<divp;i++) cout<<"i: "<<i<<" "<<div[i]<<endl;

    int divp1=0;
    for(int i=0;i<n;i++){
        if(i==div[divp1]){
//            cout<<"***"<<i<<"****"<<div[divp1];
            divp1++;
            cout<<"| ";
        }
        cout<<num[i]<<" ";
    }
    return 0;
}
