#include<iostream>
using namespace std;

int main()
{
//    freopen("BirthdayCake.txt","r",stdin);
    int cheey_coordinate[200];
    int N;
    cin>>N;
    for(int i=0;i<4*N;i+=2){
        int x,y;
        cin>>x>>y;
        if(x*x+y*y<=100*100){
//            cout<<x<<" "<<y<<endl;
            cheey_coordinate[i]=x;
            cheey_coordinate[i+1]=y;
//            cout<<"ok"<<endl;
        }
    }
    for(int i=-100;i<=100;i++){
        for(int j=-100;i*i+j*j<=100*100;j++){
            int num1=0,num2=0;
            for(int k=0;k<4*N;k+=2){
                if(i*cheey_coordinate[k]+j*cheey_coordinate[k+1]==0)
                    break;
                i*cheey_coordinate[k]+j*cheey_coordinate[k+1]>0?num1++:num2++;
            }
            cout<<"";
            if(num1==N&&num2==N){
                cout<<i<<" "<<j<<endl;
                return 1;
            }
        }
    }
    return 0;
}
