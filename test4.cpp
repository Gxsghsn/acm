#include<iostream>
using namespace std;

int main()
{
    freopen("test4.in","r",stdin);
    string boa;
    int casenum=0,testnum,guassnum,day,n=0;
    cin>>testnum;
    int month[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    while(testnum>0)
    {
        cin>>guassnum;
        while(guassnum>0)
        {
            cin>>day;
            int m=day/100;
            int d=day%100;
            cin>>boa;
            if(boa=="Before"){n=d;}
            if(boa=="After"){n=month[m]-d;}
            guassnum--;
        }
        testnum--;
        casenum++;
        cout<<"Case "<<casenum<<":\n"<<n<<endl;
    }
    return 0;
}

