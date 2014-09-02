#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    freopen("270.txt","r",stdin);
    int coorx[700],coory[700];
    int index=0;
    int t;
    int max=0;
    char str[1100];
//    gets(str);
//    sscanf(str,"%d",&t);
    cin>>t;
    gets(str);
    while(t--){
        while(gets(str)!=NULL)
        {
            if(str[0]=='\0') break;
            sscanf(str,"%d%d",&coorx[index],&coory[index]);
            index++;
        }
//        while(cin>>coorx[index]>>coory[index]){
//            index++;
//        }
        for(int i=0;i<index-1;i++){
            for(int j=i+1;j<index;j++){
                int y=coory[j]-coory[i];
                int x=coorx[j]-coorx[i];
                int max1=2;
                for(int k=j+1;k<index;k++){
                    int c1=coorx[k]-coorx[j],c2=coory[k]-coory[j];
                    if(c1*y==c2*x) {max1++;}
                }
                if(max1>max) max=max1;
            }
        }
    }
    cout<<max<<endl;
    return 0;
}







//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//int main()
//{
//    freopen("270.txt","r",stdin);
//    int count,flag,n;
//    char str[1100];
//    int sum[710][2];
//    gets(str);
//    sscanf(str,"%d",&n);
//    gets(str);
//    while(n--)
//    {
//        count=1;
//        int p=0;
//        while(gets(str)!=NULL)
//        {
//            if(str[0]=='\0') break;
//            sscanf(str,"%d%d",&sum[p][0],&sum[p][1]);
//            p++;
//        }
//        for(int i=0; i<p; i++)
//            for(int j=i+1; j<p; j++)
//            {
//                int y=sum[i][1]-sum[j][1] , x=sum[i][0]-sum[j][0];
//                flag=2;
//                for(int k=j+1; k<p; k++)
//                {
//                    int c1=sum[j][1]-sum[k][1],c2=sum[j][0]-sum[k][0];
//                    if(c1*x==y*c2) flag++;
//                }
//                if(flag>count) count=flag;
//            }
//        printf("%d\n",count);
//        if(n) printf("\n");
//    }
//    return 0;
//}
