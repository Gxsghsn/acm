#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;




int main()
{

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5-i;j++)
            cout<<i+1<<"/"<<j+1<<" ";
        cout<<endl;
    }


    int n;
    while(cin>>n)
    {


//        int hang=1;
//        for(int i=1;i<n;i++)
//        {
//            n-=i;
//            hang++;
//        }
//        cout<<"hang: "<<hang<<" n: "<<n<<endl;
//        if(hang%2==1)
//        {
//            cout<<hang+1-n<<"/"<<n<<endl;
//        }
//        else
//        {
//            cout<<n<<"/"<<hang+1-n<<endl;
//        }



        int i=1,j=1;
        while(n>1)
        {
            if(n==1)
                cout<<i<<"/"<<j<<endl;
            while(i>1)
            {
                i--;j++;
                n--;
                if(n==1)
                cout<<i<<"/"<<j<<endl;
            }
            j++;
            n--;
            if(n==1)
                cout<<i<<"/"<<j<<endl;
            while(j>1)
            {
                j--;i++;
                n--;
                if(n==1)
                cout<<i<<"/"<<j<<endl;
            }
            i++;
            n--;
            if(n==1)
                cout<<i<<"/"<<j<<endl;
        }

    }

//    int n;
//    while(scanf("%d",&n)==1)
//    {
//        int k = (int)floor((sqrt(8.0*n+1)-1)/2-1e-9)+1;
//        int s = k*(k+1)/2;
//        printf("%d/%d",s-n+1,k-s+n);
//    }
    return 0;
}
