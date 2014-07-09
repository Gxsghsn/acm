#include<iostream>
using namespace std;

int main()
{
    freopen("test4.in","r",stdin);
    string boa;
    int casenum=0,testnum,guassnum,day,n=0;
    cin>>testnum;
    int month[12][31];
    month[1][30]=0;month[1][29]=0;month[1][28]=0;month[3][30]=0;month[5][30]=0;month[8][30]=0;month[10][30]=0;
    while(testnum>0)
    {
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<31;j++)
            {
                month[i][j]=1;
            }
        }
        n=0;
        int m,d,m1,n1;
        cin>>guassnum;
        while(guassnum>0)
        {
            cin>>day;
            m=day/100-1;
            d=day%100-1;
            cin>>boa;
            if(boa=="Before")
            {
                for(int i=0;i<12;i++)
                    for(int j=0;j<31;j++)
                    {
                        if(i>m||(i==m&&j>=d))
                            month[i][j]=0;
                    }
            }
            if(boa=="After")
            {
                for(int i=0;i<12;i++)
                    for(int j=0;j<31;j++)
                    {
                        if(i<m||(i==m&&j<=d))
                            month[i][j]=0;
                    }
            }
            guassnum--;
        }
        cout<<endl;
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<31;j++)
            {
                if(month[i][j]==1)
                {
                    n++;
                    m1=i+1;
                    n1=j+1;
                }
            }
        }
        testnum--;
        casenum++;
        cout<<"Case "<<casenum<<":\n";
        if(n==1)
            printf("%02d%02d",m1,n1);
        else if(n==0)
            cout<<"Impossible"<<endl;
        else if(n>1)
            cout<<n<<endl;
    }
    return 0;
}

