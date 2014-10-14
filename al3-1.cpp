#include <iostream>
#include <cstdio>
using namespace std;

void matrixMultiply(int **a,int **b,int **c,int ra,int ca,int rb,int cb){
    for(int i=0;i<ra;i++){
    for(int k=0;k<cb;k++){
        int sum=0;
        for(int j=0;j<ca;j++){
            sum=a[i][j]*b[j][k];
        }
        c[i][k]=sum;
        }
    }
}

int main()
{
    int a[2][2]={1,1,2,0};
    int b[2][3]={0,2,3,1,1,2};
    int c[2][3];
    matrixMultiply(a,b,c,2,2,2,3);
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
}
