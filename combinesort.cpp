#include<iostream>
using namespace std;
//int a[]={1,3,5,7,9,0,2,4,6,8};
int a[]={1,3,2};
int nn=3;
void combine(int left,int right)
{
    cout<<"left & right :"<<left<<" "<<right<<endl;
    for(int i=left;i<right;i++) cout<<a[i]<<" ";
    cout<<endl;
    if(left+1>=right)
        return;
    int m=(left+right)/2;
//    cout<<"m "<<m<<endl;
    combine(left,m);
    combine(m,right);
    int l[100]={0};
    int lp=0;
    int i=left,j=m;
    while(i<m||j<right){
        cout<<"               ij"<<i<<j<<" leftright "<<left<<right<<endl;
        if(j>=right || a[i]<a[j]){
            l[lp++]=a[i++];
        }
        else{
            l[lp++]=a[j++];
        }
    }

    for(int k=left;k<right;k++){cout<<a[k]<<"-";}
    cout<<endl;
    cout<<"****"<<lp<<endl;
    for(int k=0;k<lp;k++){a[left+k]=l[k];cout<<l[k]<<" ";}
    cout<<endl<<endl;
}


int main()
{
    combine(0,nn);
    for(int i=0;i<nn;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
