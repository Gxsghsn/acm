#include<iostream>
#include<fstream>
using namespace std;
int light[100];
//#define fin cin

int main()
{
    //ifstream fin("exc3-1.in");
    int ln=10,pn=3,n,num=0;
    cin>>pn>>ln;
    for(int i=0;i<ln;i++)
        light[i]=0;
    for(int i=1;i<=pn;i++)
    {
        n=1;
        while(i*n<=ln)
        {
            if(light[i*n-1]==0) light[i*n-1]=1;
            else light[i*n-1]=0;
            n++;
        }
    }
    for(int i=0;i<ln;i++)
        if(light[i]==1)
		cout<<i+1<<" ";
    cout<<endl;


    
	
    return 0;
}
