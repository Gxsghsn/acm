#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int interpolationsearch(int *ary,int tar,int low,int high)
{
    while(low<=high){
        int mid=low+(((tar-*((int*)ary+low) )/(*((int*)ary+high-1)-*((int*)ary+low))))*(high-low);
        if(tar>*((int*)ary+(int)mid)){
            low=mid+1;
        }
        else if(tar<*((int*)ary+(int)mid)){
            high=mid-1;
        }
        else return mid;
    }
    return -1;
}


int main()
{
    int ary[]={1,2,3,4,5,6,7,8,9,10};
    cout<<interpolationsearch(ary,6,0,10)<<endl;
    return 0;
}
