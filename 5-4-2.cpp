#include<iostream>
#include<math.h>
using namespace std;
#define MAXNUM 100
int primelist[MAXNUM];
int primelistnum=1;

int is_prime(int num)
{
    for(int i=0;i<primelistnum;i++)
    {
        if(num%primelist[i]==0)
            return 0;
    }
    return 1;
}

void initialize_primelist()
{
    primelist[0]=2;
    for(int i=3;i<MAXNUM;i++)
    {
        if(is_prime(i)==1)
        {
//            cout<<i<<"*";
            primelist[primelistnum]=i;
            primelistnum++;
        }
    }
}


int countfactorial(int num)
{
    int factorial=1;
    for(int i=2;i<=num;i++)
    {
        factorial*=i;
    }
    return factorial;
}

int in_primelist(int num)
{
    for(int i=0;i<primelistnum;i++)
    {
        if(primelist[i]==num)
            return 1;
    }
    return 0;
}

int resolve(int num,int count[])
{
//    num=countfactorial(num);
//    cout<<"*"<<num<<endl;
//    for(int i=0;i<primelistnum;i++)
//        cout<<count[i]<<"*";
    while(num!=1)
    {
//        cout<<"*";
        for(int i=0;i<primelistnum;i++)
        {
            if(num%primelist[i]==0)
            {
//                cout<<"&"<<endl;
                count[i]++;
                num/=primelist[i];
//                cout<<num<<endl;
            }
        }
    }
    return 0;
}

int main()
{
    initialize_primelist();
    int n;
    while(cin>>n)
    {
    cout<<"start"<<endl;
    int count[primelistnum]={0};
    for(int i=2;i<=n;i++)
    {
        resolve(i,count);
    }
    cout<<n<<"! = ";
    for(int i=0;i<primelistnum;i++)
    {
        if(count[i]!=0)
        cout<<count[i]<<" ";
    }
    cout<<endl;
    }
    return 0;
}
