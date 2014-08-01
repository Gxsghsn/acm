#include<iostream>
using namespace std;
int maze[100];
int pathrecord[100][2];
int pathrecordptr=0;
string euler_path_record;

bool getdot(string path,int &dot1,int &dot2)
{
    sscanf(&path[1],"%d",&dot1);
    path.erase(0,path.find(',')+1);
    sscanf(&path[0],"%d",&dot2);
//    cout<<dot1<<dot2<<endl;
    return true;
}

void record(int dot1,int dot2)
{
    pathrecord[pathrecordptr++][0]=dot1;
    pathrecord[pathrecordptr++][0]=dot2;
}

bool find_euler_path(int start)
{
    for(int i=0;i<pathrecordptr;i++){
        if(pathrecord[i][0]==start && pathrecord[i][1]!=1){
            pathrecord[i][1]=1;
            pathrecord[i+1][1]=1;

            int flag=1;
            for(int j=0;j<pathrecordptr;j+=2){
                if(pathrecord[j][1]==0)
                    flag=0;
            }
            if(flag==1) return true;
//            cout<<pathrecordptr<<"  "<<start<<endl;
            if(i%2==0)
                start=pathrecord[i+1][0];
            else
                start=pathrecord[i-1][0];

            if(find_euler_path(start)) {euler_path_record+=(char)start; return true;}
        }
    }
}

int main()
{
    freopen("6-4-4.txt","r",stdin);
    int pathnum=0;
    string path;
    while(cin>>path&&path!="()"){
        pathnum++;
        int dot1,dot2;
        if(!getdot(path,dot1,dot2)) {break;}
        record(dot1,dot2);
    }
//    for(int i=0;i<pathrecordptr;i++) cout<<pathrecord[i][0]<<" ";

    if(find_euler_path(0)){
        cout<<"find"<<endl;
        for(int i=euler_path_record.length();i>=0;i--)
            cout<<(int)euler_path_record[i]<<"*";
        cout<<endl;
        return 1;
    }
    else{
        cout<<"No Path"<<endl;
        return 0;
    }

}
