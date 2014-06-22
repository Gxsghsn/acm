#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout("exc2-10.out");
    int a[9],abc=123,def,ghi;
    next:
    while(abc<=321)
    {
        def = 2*abc;
        ghi = 3*abc;
        a[0]=abc/100;
        a[1]=abc/10%10;
        a[2]=abc%10;
        a[3]=def/100;
        a[4]=def/10%10;
        a[5]=def%10;
        a[6]=ghi/100;
        a[7]=ghi/10%10;
        a[8]=ghi%10;
        abc++;
        for(int i=1;i<10;i++)
            for(int j=0;j<i;j++)
                {
                    if(a[i]==a[j])
                        goto next;
                    if(a[i]==0)
                        goto next;
                    //cout<<abc<<" ";
                }
        fout<<abc-1<<" "<<def<<" "<<ghi<<endl;
    }
    fout.close();
    return 0;
}
