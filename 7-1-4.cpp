#include<iostream>
#include<math.h>
using namespace std;

bool is_double_pali(int s)
{
//    cout<<s<<endl;
    int is_pali_num = 0;

    for(int a=2;a<10;a++){
        int n=s;
        int changed[30]={0};
        int len=0;
        for(;n>0;len++){
            changed[len]=n%a;
            n/=a;
        }

        int flag=1;
        for(int i=0;i<len/2;i++)
            if(changed[i]!=changed[len-i-1])
                flag=0;

        if(flag==1){
//            cout<<a<<": ";
//            for(int i=0;i<len;i++) cout<<changed[i];
//            cout<<endl;
            is_pali_num++;
        }
    }
    if(is_pali_num>=2) return true;
    else
        return false;
}



int main()
{
    freopen("7-1-4.txt","r",stdin);
    int n;
    cin>>n;
//    is_double_pali(n);
    while(!is_double_pali(n)) n++;
    cout<<n;
    return 0;
}
