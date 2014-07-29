#include<iostream>
using namespace std;

string dlr_ldr_to_lrd(string dlr,string ldr)
{
    if(dlr==ldr&&dlr.length()<2) return dlr;
    int n=ldr.find(dlr[0]);
//    cout<<"1"<<endl;
    string ldr1 = ldr.substr(0,n);
//    cout<<ldr1<<" * ";
    string dlr1 = dlr.substr(1,n);
//    cout<<dlr1<<" & \n";
//    cout<<ldr<<"\n";
    string ldr2 = ldr.substr(n+1,ldr.length());
//    cout<<ldr2<<" * ";
    string dlr2 = dlr.substr(n+1,ldr2.length());
//    cout<<dlr2<<" & \n";
//    if(dlr1==ldr1&&dlr2==ldr2){
//        string lrd="";
//        lrd+=dlr[1];lrd+=dlr[2];lrd+=dlr[0];
////        cout<<lrd<<"~"<<endl;
//        return lrd;
//    }
//    else{
        string lrd1 = dlr_ldr_to_lrd(dlr1,ldr1);
//        cout<<"lrd1 "<<lrd1<<"\n";
        string lrd2 = dlr_ldr_to_lrd(dlr2,ldr2);
//        cout<<" lrd2 "<<lrd2<<endl;
        return lrd1+lrd2+dlr[0];
//    }
}


int main()
{
    freopen("6-3-3.in","r",stdin);
    string dlr,ldr,lrd;
    while(cin>>dlr>>ldr){
        lrd = dlr_ldr_to_lrd(dlr,ldr);
        cout<<lrd<<endl;
    }
    //CDAB
    return 0;
}
