#include<iostream>
using namespace std;

int main()
{
    freopen("BirthdayCake.txt","r",stdin);
    int cheey_coordinate_x[200];
    int cheey_coordinate_y[200];
    int N;  
    while(1){
        cin>>N;
        if(!N) break;
        for(int i=0;i<2*N;i++){
            int x,y;
            cin>>x>>y;
            cheey_coordinate_x[i]=x;
            cheey_coordinate_y[i]=y;
        }
        int flag=0;
        int num1=0;
        for(int i=-500;i<=500;i++){
            for(int j=-500;j<=500;j++){
                if(i==0&&j==0) continue;
                num1=0;int num2=0;
                for(int k=0;k<2*N;k++){
                    if(i*cheey_coordinate_x[k]+j*cheey_coordinate_y[k]<0) num1++;
                    if(i*cheey_coordinate_x[k]+j*cheey_coordinate_y[k]>0) num2++;
                    if(i*cheey_coordinate_x[k]+j*cheey_coordinate_y[k]==0) break;
                }
                if(num1==N&&num2==N){
                    flag=1;
                    cout<<i<<" "<<j<<endl;
                    break;
                }
            }
            if(flag==1) break;
        }
    }
    return 0;
}
