#include<iomanip>
#include<iostream>
using namespace std;

int main()
{
    cout.fill('0');
    freopen("test6.in","r",stdin);
    int testnum,mnum,casenum=0;
    cin>>testnum;
    while(testnum>0)
    {
        int time77=0,timecc=0,count77=0,countcc=0,timeprimer=0;
        cin>>mnum;
        while(mnum>0)
        {
            string name;
            int hh,mm,ss,usetime;
            cin>>name>>hh;
            getchar();
            cin>>mm;
            getchar();
            cin>>ss;
            if(name=="77")
            {
               count77++;
               if(timeprimer!=0)
                  time77+=(hh*3600+mm*60+ss)-timeprimer;
            }
            else
            {
               countcc++;
               if(timeprimer!=0)
                  timecc+=(hh*3600+mm*60+ss)-timeprimer;
            }
            timeprimer=hh*3600+mm*60+ss;
            mnum--;
        }
        casenum++;
        cout<<"Case "<<casenum<<":\n";
        cout<<time77<<" "<<timecc<<" "<<count77<<" "<<countcc<<" ";
        if((double)time77/timecc<=2&&(double)time77/timecc>=0.5)
            cout<<"happy"<<endl;
        else
            cout<<"unhappy"<<endl;

        testnum--;
    }
    return 0;
}
