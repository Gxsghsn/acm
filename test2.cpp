#include<iostream>
using namespace std;

int main()
{
    int n,num=1,start,cishu;
    cin>>n;
    while(n>0)
    {
        cin>>cishu>>start;
        string a1="1-2-1 1-2-1 1 1 1-2-1",a2="1 2 3 4 1-2-3 4";
        cout<<"case "<<num<<":\n";
        while(cishu>0)
        {

            if(start==1)
            {
                cout<<a1<<" ";
                start = 2;
            }
            else
            {
                cout<<a2<<" ";
                start=1;
            }

            cishu--;
//            cout<<"case "<<num<<":\n"<<
        }
            num++;
    }
    return 0;
}
