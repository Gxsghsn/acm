#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    freopen("270.txt","r",stdin);
    int coor[710][2];
    int index=0;
    int t;
    int max=0;
    char str[1100];
//
//
//    gets(str);
//    sscanf(str,"%d",&t);
//    gets(str);



//    cout<<"str "<<str<<endl;



    cin>>t;
    while(t--){
        max=1;
        index=0;
        while(gets(str)!=NULL){
            cout<<str<<endl;
            if(str[0]=='\0') break;
            sscanf(str,"%d%d",&coor[index][0],&coor[index][1]);
            index++;
        }
//
//        while(cin>>coor[index][0]>>coor[index][1]){
////            cout<<coor[index][0]<<coor[index][1]<<endl;
//            index++;
//            if(cin.eof()) break;
//        }


        for(int i=0;i<index;i++){
            for(int j=i+1;j<index;j++){
                int y=coor[j][1]-coor[i][1];
                int x=coor[j][0]-coor[i][0];
                int max1=2;
                for(int k=j+1;k<index;k++){
                    int c1=coor[k][0]-coor[j][0],c2=coor[k][1]-coor[j][1];
                    if(c1*y==c2*x) {max1++;}
                }
                if(max1>max) max=max1;
            }
        }
        cout<<max<<endl;
        if(t) printf("\n");
    }
    return 0;
}





