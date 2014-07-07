#include<iostream>
using namespace std;

int is_primer(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}


int main()
{
    int n;
    cin>>n;
    int max = 0;
    for(int i=2;i<n-2;i++)
    {
        if(is_primer(i))
            if(is_primer(i+2))
                max = i;
    }
    cout<<max<<" "<<max+2<<endl;
    return 0;
}
